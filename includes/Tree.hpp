/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/20 22:24:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include "pair.hpp"
# include "utils.hpp"
# include "../vector.hpp"
# include <vector>
# include <math.h> 

namespace ft
{
    template <class T, class Compare, class Alloc>
    struct Tree
    {
		typedef typename T::first_type 				key_type;
		typedef typename T::second_type 			mapped_type;
		typedef T									value_type;
		typedef	Compare								key_compare;
		typedef	Alloc								allocator_type;
		typedef	value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef	value_type*							pointer;
		typedef	const value_type*					const_pointer;
		typedef	ptrdiff_t							difference_type;
		typedef	size_t								size_type;

		struct Node
		{
			value_type				value;
			Node*					left;
			Node*					right;
			Node*					parent;

			Node*	getParent() {
				Node* node = this;
				while (node->parent)
					node = node->parent;
				return node;
			}
			
			Node*			getMinimum() {
				Node* node = this;
				while (node->left)
					node = node->left;
				return node;
			}
			
			Node*			getMaximum() {
				Node* node = this;
				while (node->right)
					node = node->right;
				return node;
			}
		};
		
		key_compare				key_comp;
		allocator_type  		allocValue;
		std::allocator<Node>	allocNode;
		Node*					root;
		Node*					end;


		class value_compare
		{
				friend struct Tree;
			protected:
				Compare comp;
				value_compare (key_compare c) : comp(c) {}
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first); }
		};
		
		Tree(const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) :
			key_comp(comp), allocValue(alloc) {
				this->root = nullptr;
				this->end = this->allocNode.allocate(sizeof(Node));
				this->setEnd();
		}
		
		Tree(const Tree& x) { *this = x; }
		
		Tree(const Node& node, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) :
			key_comp(comp), allocValue(alloc) {
				*this->root = node;
				this->end = this->allocNode.allocate(sizeof(Node));
				this->setEnd();
		}
		
		~Tree() {}


		Tree&			operator=(const Tree& x)
		{		
			if(this == &x)
				return *this;
			destroy(this->root);
			this->root = nullptr;
			this->allocNode.deallocate(this->end, sizeof(Node));
			this->allocValue = x.allocValue;
			this->allocNode = x.allocNode;
			this->end = this->allocNode.allocate(sizeof(Node));
			this->key_comp = x.key_comp;
			this->root = copyNode(this->root, x.root);
			this->setEnd();
			return *this;
		}

		mapped_type& 	operator[](const key_type& k)
		{
			Node* node = findNode(k);
			if (node)
				return node->value.second;
			this->root = insertNode(this->root,
			ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
			this->setEnd();
			return (*this)[k];
		}
		
		Node*			findNode(const key_type& k) const
		{
			Node *tmp = this->root;
			while (tmp)
			{
				if (this->key_comp(k, tmp->value.first))
					tmp = tmp->left;
				else if (this->key_comp(tmp->value.first, k))
					tmp = tmp->right;
				else
					return tmp;
			}
			return 0;
		}
		
		Node*			copyNode(Node* dest, Node* src)
		{
			if (src)
			{
				dest = copyNode(dest, src->left);
				dest = copyNode(dest, src->right);
				dest = insertNode(dest, src->value);
			}
			return dest;
		}
		
		
		void			setEnd() {
			if (this->root)
				this->end->parent = this->root->getMaximum();
			else
				this->end->parent = nullptr;
			this->end->right = nullptr;
			this->end->left = nullptr;
		}

		size_type		max_size() const { return this->allocValue.max_size(); }

		
		size_type		size(Node* node) const
		{
			size_type s = 0;

			if (node)
			{
				s += size(node->right);
				s += size(node->left);
				++s;
			}
			return s;
		}
		
		Node*			newNode(value_type val, Node* parent)
		{
			Node* node;
			
			node = this->allocNode.allocate(sizeof(Node));
			this->allocValue.construct(&node->value, val);
			
			node->parent = parent;
			node->left = nullptr;
			node->right = nullptr;

			return node;
		}
		
		Node*			insertNode(Node* node, const value_type& val, Node* parent = nullptr)
		{
			if (!node)
				return newNode(val, parent);

			if (this->key_comp(val.first, node->value.first))
				node->left = insertNode(node->left, val, node);
			else if (this->key_comp(node->value.first, val.first))
				node->right = insertNode(node->right, val, node);
			else
				return node;

			node = this->balanceTree(node, val.first);
			
			return node;
		}

		Node*			deleteNode(Node* node, const key_type key)
		{
			if (!node)
				return node;
			if (this->key_comp(key, node->value.first))
				node->left = deleteNode(node->left, key);
			else if (this->key_comp(node->value.first, key))
				node->right = deleteNode(node->right, key);
			else
			{
				if (!node->left || !node->right)
				{
					Node* tmp = node;
					node = node->left ? node->left : node->right;
					if (node)
						node->parent = tmp->parent;
					this->allocValue.destroy(&tmp->value);
					this->allocNode.destroy(tmp);
					this->allocNode.deallocate(tmp, sizeof(Node));
				}
				else
				{
					// find the greatest smaller
					Node *tmp = node->right->getMinimum();

					// switch them
					if (tmp != node->right)
					{
						tmp->right = node->right;
						node->right->parent = tmp;
					}
					if (tmp != node->left)
					{
						tmp->left = node->left;
						node->left->parent = tmp;
					}
					tmp->parent->left = nullptr;
					tmp->parent = node->parent;
					// delete it
					this->allocValue.destroy(&node->value);
					this->allocNode.destroy(node);
					this->allocNode.deallocate(node, sizeof(Node));
					node = tmp;
				}
			}
			node = balanceTree(node);
			return node;
		}
		
		void			destroy(Node *node)
		{
			if (node)
			{
				destroy(node->left);
				destroy(node->right);
				this->allocValue.destroy(&node->value);
				// this->allocNode.destroy(node);
				this->allocNode.deallocate(node, sizeof(Node));
			}
		}
		
		void			clear()
		{
			// this->allocNode.destroy(node);
			this->allocNode.deallocate(this->end, sizeof(Node));
			if (this->root)
				destroy(this->root->getParent());
			this->root = nullptr;
		}

		Node*			leftRotate(Node* x)
		{
			Node *top = x->right;
			Node *tmp = top->left;
			
			top->parent = x->parent;
			x->parent = top;
			if (tmp)
				tmp->parent = x;
			x->right = tmp;
			top->left = x;

			return top;
		}

		Node*			rightRotate(Node* y)
		{
			Node* top = y->left;
			Node* tmp = top->right;
			
			top->parent = y->parent;   
			y->parent = top;
			if (tmp)
				tmp->parent = y;
			y->left = tmp;
			top->right = y;  

			return top;
		}
		
		
		int				height(Node* node, int h = 0) const
		{
			if (node)
			{
				h++;
				int tmp = h;
				h = height(node->right, h);
				tmp = height(node->left, tmp); 
				h = h > tmp ? h : tmp;
			}
			
			return h;
		}
		
		// calcul balance factor
		int				balanceFactor(Node* node) const
		{
			if (!node)
				return 0;
			return height(node->right) - height(node->left);
		}
		
		Node*			balanceTree(Node* node, const key_type key)
		{
			int bf = balanceFactor(node);
			
			// Left Left Case
			if (bf < -1 && this->key_comp(key, node->left->value.first))
				return rightRotate(node);
			// Right Right Case
			if (bf > 1 && this->key_comp(node->right->value.first, key))
				return leftRotate(node);
			// Left Right Case
			if (bf < -1 && this->key_comp(node->left->value.first, key))
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
			// Right Left Case
			if (bf > 1 && this->key_comp(key, node->right->value.first))
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
			
			return node;
		}
		
		Node*			balanceTree(Node* node)
		{
			if (!node)
				return node;
				
			int bf = balanceFactor(node);
			// Left Left Case
			if (bf < -1 && balanceFactor(node->left) <= 0)
				return rightRotate(node);
			// Right Right Case
			if (bf > 1 && balanceFactor(node->right) >= 0)
				return leftRotate(node);
			// Left Right Case
			if (bf < -1 && balanceFactor(node->left) > 0)
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
			// Right Left Case
			if (bf > 1 && balanceFactor(node->right) < 0)
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
			
			return node;
		}

		value_compare	value_comp() const { return value_compare(this->key_comp); }
		
		ft::vector<ft::pair<std::string, int> >	getTreeDrawing(Node* node,
			ft::vector<ft::pair<std::string, int> > drawing, int l, int y = 0,
			int level = 0, int side = 0) const
		{
			if (node)
			{
				++level;
				y += (side * (l / pow(2, level)));
				if (side == 1)
					++y;
				drawing = getTreeDrawing(node->right, drawing, l, y, level, 1);
				drawing = getTreeDrawing(node->left, drawing, l, y, level, -1);;
				drawing[(level - 1) * l + y].first = node->value.first;
				drawing[(level - 1) * l + y].second = -1;
				if (node->parent && node->value.first > node->parent->value.first)
					drawing[(level - 1) * l + y].second = 1;
			}
			
			return drawing;
		}
		
		void		drawTree() const
		{
			int 		treeHeight = height(this->root);
			int			l = pow(2, treeHeight - 1) * 2 - 1;
			ft::vector<ft::pair<std::string, int> >	drawing(treeHeight * l);
			
			drawing = getTreeDrawing(this->root, drawing, l, l / 2);
			for (size_t i = 0; i < drawing.size(); i++)
			{
				if (i % l == 0 && i != 0)
				{
					std::cout << std::endl;
					std::string link;
					int draw = 0;
					for (int j = 0; j < l; j++)
					{
						if (!drawing[i - l + j].first.empty())
						{
							link += '^';
							int n = l / (pow(2, i / l + 1)) + 1;
							draw = (drawing[i + j + n].second == 1) ? 1 : 0;
						}
						else if (drawing[i + j].first.empty())
							link += (draw == 1) ? '-' : ' ';
						else
						{
							link += '|';
							draw = (drawing[i + j].second == -1) ? 1 : 0;
						}
					}

					std::cout << "\033[32m" << link << "\033[0m" << std::endl;
				}
				if (drawing[i].first.empty())
					std::cout << " ";
				else
					std::cout << "\033[35m" <<  drawing[i].first << "\033[0m";
			}
			std::cout << std::endl << std::endl;
		}
    };
	
    template <class T, class Compare, class Alloc>	
	std::ostream&	operator<<(std::ostream& os, const Tree<T, Compare, Alloc>& tree)
	{
		os << "\n\033[1;32m"
		<< "┌┬┐┬─┐┌─┐┌─┐" << std::endl
 		<< " │ ├┬┘├┤ ├┤ " << std::endl 
 		<< " ┴ ┴└─└─┘└─┘" << std::endl
 		<< "~~~~~~~~~~~~~" << "\033[0m" << std::endl << std::endl;
		tree.drawTree();
		os	<< "\033[2mheight : " << tree.height(tree.root) << "\033[0m\n"
			<< "\033[2msize : " << tree.size(tree.root) << "\033[0m\n" << std::endl;
		return os;
	}
}

#endif
