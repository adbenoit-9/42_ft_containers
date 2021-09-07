/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/07 12:23:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
// # include <functional>
# include "pair.hpp"
# include "utils.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator< pair<const Key,T> >  >
    struct Node
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

		key_compare				key_comp;
		allocator_type  		alloc;
		size_type 				size;

		value_type		value;
		struct Node		*left;
		struct Node		*right;
		struct Node		*parent;
		
		Node(const key_compare& comp = key_compare(),const allocator_type& al = allocator_type(), value_type val = nullptr) :
			key_comp(comp), alloc(al), size(0)
		{
			this->_value = val;
			this->parent = nullptr;
			this->right = nullptr;
			this->left = nullptr;
		}
		
		Node(const key_compare& comp = key_compare(),const allocator_type& al = allocator_type()) :
			key_comp(comp), alloc(al), allocNode(allocator_type()), size(0)
		{
			this->_value = nullptr;
			this->_left = nullptr;
			this->_right = nullptr;
			this->_left = nullptr;
		}
		
		Node(const Node& x, typename ft::enable_if<is_node<Node> >::type * = 0)
		{
			*this = x;
		}
		
		~Node()
		{
			this->destroy(getParent(this));
		}


		Node& operator=(const Node& x)
		{		
			if(this == &x)
				return *this;
			this->parent = x.parent;
			this->left = x.left;
			this->right = x.right;
			this->value = x.value;
			this->size = x.size;
			this->key_comp = x.key_comp;
			this->alloc = x.alloc;
			this->allocNode = x.allocNode;
			return *this;
		}

		//					~ Iterators ~

		Node*					getParent(Node* node)
		{
			while (node && node->parent)
				node = node->parent;
			return node;
		}

		size_type				size() const { return this->size; }

		size_type				maxsize() const { return this->alloc.maxsize(); }

		bool					empty() const { return this->size == 0; }

		mapped_type& 			operator[](const key_type& k)
		{
			Node *tmp;

			tmp = this->_root;
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
		
		bool					insert(Node* node)
		{
			Node *tmp;

			tmp = this->_root;
			while (tmp)
			{
				node->parent = tmp;
				if (this->key_comp(node->value.first, tmp->value.first))
					tmp = tmp->left;
				else if (this->key_comp(tmp->value.first, node->value.first))
					tmp = tmp->right;
				else
					return 1;
			}				
			tmp = node;
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
				this->allocNode.deallocate(node, 1);
			}
		}
		
		void					swap(Tree& x)
		{
			key_compare				tkey_comp = this->key_comp;
			allocator_type  		talloc = this->alloc;
			std::allocator< Node >  tallocNode = this->alloc;
			size_type 				tsize = this->size;
			Node*					tparent = this->parent;
			Node*					tleft = this->left;
			Node*					tright = this->right;

			this->key_comp = x.key_comp;
			this->alloc = x.alloc;
			this->allocNode = x.alloc;
			this->size = x.size;
			this->parent = x.parent;
			this->left = x.left;
			this->right = x.right;

			x.key_comp = tkey_comp;
			x.alloc = talloc;
			x.allocNode = talloc;
			x.size = tsize;
			x.parent = tparent;
			x.left = tleft;
			x.right = tright;
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

		int		height(Node* node)
		{
			int	h = 0;

			if (node)
			{
				height(node->right);
				height(node->left);
				++h;
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

		
		key_compare				key_comp() const { return this->_comp; }
		value_compare			value_comp() const { return value_compare(this->_comp); }


    };
}

#endif
