/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/09 17:57:31 by adbenoit         ###   ########.fr       */
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
		std::allocator<Node> allocNode;
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
		
		Node*				constructNode(value_type val)
		{
			Node* node;
			
			node = this->allocNode.allocate(sizeof(Node));
			this->alloc.construct(&node->value, val);
			
			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;

			return node;
		}
		
		bool					insert(Node* node)
		{
			Node *tmp;

			tmp = this->getParent();
			int side = -1;
			while (tmp)
			{
				node->parent = tmp;
				if (this->key_comp(node->value.first, tmp->value.first))
				{
					side = 0;
					tmp = tmp->left;
				}
				else if (this->key_comp(tmp->value.first, node->value.first))
				{
					tmp = tmp->right;
					side = 1;
				}
				else
					return 1;
			}
			if (side == 0)
				node->parent->left = node;
			else if (side == 1)
				node->parent->right = node;
			else
				this->root = node;
			++this->size;
			
			// Node* balance = balance_tree(this->root);
			// if (balance)
			// 	this->root = balance;
			return 0;
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
		
		Node*	rotate_left(Node* n1, Node* n2)
		{
			Node* tmp = n2->left;
			if (tmp)
				tmp->parent = n1;
			
			n2->parent = n1->parent;
			n2->left = n1;
			
			n1->parent = n2;
			n1->right = tmp;
			
			return n2;
		}
		
		Node*	rotate_rightLeft(Node* n1, Node* n2)
		{
			Node* n3 = n2->left;
			n3->parent = n1->parent;
			
			n2->parent = n3;
			n2->left = n3->right;
			if (n2->left)
				n2->left->parent = n2;
			
			n1->parent = n3;
			n1->right = n3->left;
			if (n1->right)
				n1->right->parent = n1;

			n3->left = n1;
			n3->right = n2;
			
			return n3;
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
		
		Node*	balance_tree(Node *node)
		{
			// calcul balance factor
			int bf = height(node->right) - height(node->left);
			if (bf >= -1 && bf <= 1)
				return nullptr;
			else if (bf > 1)
				return rotate_left(node, node->right);
			return rotate_rightLeft(node, node->right);
		}

		value_compare			value_comp() const { return value_compare(this->_comp); }
		
		std::vector<std::pair<key_type, std::string> >	getTreeDrawing(Node* node, std::vector<std::pair<key_type, std::string> > drawing, int l, int y = 0, int level = 0, int side = 0) const
		{
			if (node)
			{
				++level;
				y += (side * (l / pow(2, level)));
				drawing = getTreeDrawing(node->right, drawing, l, y, level, 1);
				drawing = getTreeDrawing(node->left, drawing, l, y, level, -1);;
				drawing[(level - 1) * l + y].first = node->value.first;
				std::cout << drawing.size() << "\t--> " << "drawing[" << (level - 1) * l + y << "] = " <<  drawing[(level - 1) * l + y].first << std::endl;
				// std::cout << "height = " << height(node) << "\tlevel : " << level << "\tkey -> " << node->value.first << std::endl;
			}
			
			return drawing;
		}

		void				drawTree() const
		{
			int 		treeHeight = height(this->root);
			int			l = pow(2, treeHeight - 1) * 2 - 1;
			std::vector<std::pair<key_type, std::string> >	drawing(treeHeight * l);
			// std::vector<int>		count(treeHeight, 0);
			
			std::cout << "\033[1mTree height = " << treeHeight << "\nlenght = " << l << "\033[0m" << std::endl;
			
			drawing = this->getTreeDrawing(this->root, drawing, l, l / 2);
			for (size_t i = 0; i < drawing.size(); i++)
			{
				std::cout << drawing[i].first;
				if (drawing[i].first.empty())
					std::cout << " ";
				if (i % (l - 1) == 0)
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
    };
	
    template < class Key, class T >	
	std::ostream&	operator<<(std::ostream& os, const Tree<Key, T>& tree)
	{
		
		// tree.displayNode(tree.root);
		tree.drawTree();
		return os;
	}
}

#endif
