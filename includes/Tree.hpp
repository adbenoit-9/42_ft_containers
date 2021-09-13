/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/14 00:41:36 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
// # include <functional>
# include "pair.hpp"
# include "utils.hpp"
#include <math.h> 
#include <vector> 

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator< pair<const Key,T> >  >
    struct Tree
    {
		typedef Key 												key_type;
		typedef T 										    		mapped_type;
		typedef pair<const key_type, mapped_type>           		value_type;
		typedef	Compare												key_compare;
		typedef	Alloc												allocator_type;
		typedef	typename allocator_type::reference					reference;
		typedef	typename allocator_type::const_reference			const_reference;
		typedef	typename allocator_type::pointer					pointer;
		typedef	typename allocator_type::const_pointer				const_pointer;
		typedef	ptrdiff_t											difference_type;
		typedef	size_t												size_type;

		struct Node
		{
			value_type				value;
			Node					*left;
			Node					*right;
			Node					*parent;
		};
		
		key_compare				key_comp;
		allocator_type  		alloc;
		size_type 				size;
		std::allocator<Node>	allocNode;
		Node*					root;


		class value_compare
		{
				friend struct Node;
			protected:
				Compare comp;
				value_compare (key_compare c) : comp(c) {}
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		};
		
		Tree(const key_compare& comp = key_compare(),const allocator_type& al = allocator_type()) :
			key_comp(comp), alloc(al), size(0)
		{
			this->root = nullptr;
		}
		
		Tree(const Tree& x)
		{
			*this = x;
		}
		
		~Tree()
		{
			this->destroy(this->getParent());
		}


		Tree& operator=(const Tree& x)
		{		
			if(this == &x)
				return *this;
			this->parent = x.parent;
			this->left = x.left;
			this->right = x.right;
			this->root->value = x.value;
			this->size = x.size;
			this->key_comp = x.key_comp;
			this->alloc = x.alloc;
			return *this;
		}

		//					~ Iterators ~

		Node*					getParent(Node *node = nullptr)
		{
			Node *tmp;

			if (!node)
				tmp = this->root;
			else
				tmp = node;
			while (tmp && tmp->parent)
				tmp = tmp->parent;
			return tmp;
		}

		size_type				maxsize() const { return this->alloc.maxsize(); }

		bool					empty() const { return this->size == 0; }

		mapped_type& 			operator[](const key_type& k)
		{
			Node *tmp;

			tmp = this;
			while (tmp)
			{
				if (k == tmp->value.first)
					return tmp->value.second;
				else if (this->key_comp(k, tmp->value.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
		}
		
		Node*				newNode(value_type val, Node* parent)
		{
			Node* node;
			
			node = this->allocNode.allocate(sizeof(Node));
			this->alloc.construct(&node->value, val);
			
			node->parent = parent;
			node->left = nullptr;
			node->right = nullptr;

			return node;
		}
		
		Node*					insertNode(Node* node, Node* parent, value_type val)
		{
			if (!node)
				return newNode(val, parent);

			if (this->key_comp(val.first, node->value.first))
				node->left = insertNode(node->left, node, val);
			else if (this->key_comp(node->value.first, val.first))
				node->right = insertNode(node->right, node, val);
			else
				return node;
			++this->size;
				
			node = this->balance_tree(node, val.first);
			
			return node;
		}

		Node*				deleteNode(Node* node, key_type key)
		{
			if (!node)
				return node;
			
			if (this->key_comp(key, node->value.first))
				node->left = deleteNode(node->left, key);
			else if (this->key_comp(node->value.first, key))
				node->right = deleteNode(node->right, key);
			else
			{
				--this->size;
				if (!node->left || !node->right)
				{
					Node* tmp = node;
					node = node->left ? node->right : node->left;
					if (node)
						node->parent = tmp->parent;
					this->allocNode.destroy(tmp);
					this->allocNode.deallocate(tmp, sizeof(Node));
				}
				else
				{
					Node *tmp = node->right;
					while (tmp->left)
						tmp = tmp->left;
					tmp->parent = node->parent;
					tmp->right = node->right;
					tmp->left = node->left;
					this->allocNode.destroy(node);
					this->allocNode.deallocate(node, sizeof(Node));
					node = tmp;
				}
			}
			if (!node)
				return node;
			node = balance_tree(node, key);
			
			return node;
		}
		
		void				destroy(Node *node)
		{
			if (node)
			{
				destroy(node->left);
				destroy(node->right);
				this->alloc.destroy(&node->value);
				this->allocNode.destroy(node);
				this->allocNode.deallocate(node, sizeof(Node));
			}
		}
		
		void					swap(Node& x)
		{
			// key_compare				tkey_comp = this->key_comp;
			// allocator_type  		talloc = this->alloc;
			// // std::allocator< Node >  tallocNode = this->alloc;
			// size_type 				tsize = this->size;
			// Node*					tparent = this->parent;
			// Node*					tleft = this->left;
			// Node*					tright = this->right;

			this->key_comp = x.key_comp;
			// this->alloc = x.alloc;
			// // this->allocNode = x.alloc;
			// this->size = x.size;
			// this->parent = x.parent;
			// this->left = x.left;
			// this->right = x.right;

			// x.key_comp = tkey_comp;
			// x.alloc = talloc;
			// // x.allocNode = talloc;
			// x.size = tsize;
			// x.parent = tparent;
			// x.left = tleft;
			// x.right = tright;
		}

		void					clear()
		{
			while (this->parent)
				this = this->parent;
			this->destroy(this);
			this->size = 0;
		}

		Node*	leftRotate(Node* x)
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

		Node*	rightRotate(Node* y)
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
		
		
		int		height(Node* node, int h = 0) const
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
		
		Node*	balance_tree(Node* node, key_type key)
		{
			// calcul balance factor
			int bf = node ? height(node->right) - height(node->left) : 0;
			
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

		value_compare			value_comp() const { return value_compare(this->_comp); }
		
		ft::vector<ft::pair<key_type, int> >	getTreeDrawing(Node* node, ft::vector<ft::pair<key_type, int> > drawing, int l, int y = 0, int level = 0, int side = 0) const
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
		
		void				drawTree() const
		{
			int 		treeHeight = height(this->root);
			int			l = pow(2, treeHeight - 1) * 2 - 1;
			ft::vector<ft::pair<key_type, int> >	drawing(treeHeight * l);
			
			drawing = this->getTreeDrawing(this->root, drawing, l, l / 2);
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
	
    template < class Key, class T >	
	std::ostream&	operator<<(std::ostream& os, const Tree<Key, T>& tree)
	{
		std::cout << "\n\033[1;32m"
		<< "┌┬┐┬─┐┌─┐┌─┐" << std::endl
 		<< " │ ├┬┘├┤ ├┤ " << std::endl 
 		<< " ┴ ┴└─└─┘└─┘" << std::endl
 		<< "~~~~~~~~~~~~~" << "\033[0m" << std::endl << std::endl;
		tree.drawTree();
		std::cout << "\033[2mheight : " << tree.height(tree.root) << "\033[0m\n" << std::endl;
		return os;
	}
}

#endif
