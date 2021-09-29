/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/29 16:28:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <math.h> 
# include "pair.hpp"
# include "utils.hpp"

namespace ft
{
    template <	class T,
				class Compare = ft::less<typename T::first_type>,
				class Alloc = std::allocator<T> >
    class Tree
    {
		/**
		 * ================================================= PUBLIC =================================================
		 * 
		 * Tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		 * Tree(const Tree& x);
		 * Tree(const Node& node, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		 * 
		 * ~Tree();
		 * 
		 * Tree&			operator=(const Tree& x);
		 * 
		 * 						~ Capacity ~
		 * 
		 * size_type		size() const;
		 * int				height() const;
		 * size_type		max_size() const;
		 * 
		 * 						~ Element access ~
		 * 
		 * mapped_type& 	operator[](const key_type& k);
		 * 
		 * 						~ Modifiers ~
		 * 
		 * void				set_end_node();
		 * void				swap(Tree& x);
		 * void				insertValue(const value_type& val);
		 * void				deleteKey(const key_type key);
		 * void				clear();
		 * 
		 * 						~ Observers ~
		 * 
		 * Node*			root() const;
		 * Node*			end_node() const;
		 * key_compare		key_comp() const;
		 * value_compare	value_comp() const;
		 * 
		 * 						~ Operator ~
		 * 
		 * Node*			find(const key_type& k) const;
		 * 
		 * 						~ Balance (avl) ~
		 * 
		 * Node*			leftRotate(Node* x);
		 * Node*			rightRotate(Node* y);
		 * int				balanceFactor(Node* node) const;
		 * Node*			balanceTree(Node* node, const key_type key);
		 * Node*			balanceTree(Node* node);
		 * 
		 * 						~ Node utils ~
		 * 
		 * size_type		sizeNode(Node* node) const;
		 * int				heightNode(Node* node, int h = 0) const;
		 * Node*			copyNode(Node* dest, Node* src);
		 * Node*			newNode(value_type val, Node* parent);
		 * Node*			insertNode(Node* node, const value_type& val, Node* parent = 0);
		 * Node*			deleteNode(Node* node, const key_type key);
		 * void				destroyNode(Node *node);
		 * 
		 * ================================================= PRIVATE =================================================
		 * 
		 * key_compare				_comp;
		 * allocator_type  			_allocValue;
		 * std::allocator<Node>		_allocNode;
		 * Node*					_root;
		 * Node*					_end_node;
		 * 
		 **/
			
		public:
			typedef typename T::first_type 						key_type;
			typedef typename T::second_type 					mapped_type;
			typedef T											value_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	size_t										size_type;

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
				
				Node*	min() {
					Node* node = this;
					while (node->left)
						node = node->left;
					return node;
				}
				
				Node*	max() {
					Node* node = this;
					while (node->right)
						node = node->right;
					return node;
				}
			};
			
			class value_compare
			{
					friend class Tree;
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
				_comp(comp), _allocValue(alloc) {
					this->_root = 0;
					this->_end_node = this->_allocNode.allocate(1);
					this->set_end_node();
			}
			
			Tree(const Tree& x) { *this = x; }
			
			Tree(const Node& node, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
				_comp(comp), _allocValue(alloc) {
					this->_root = &node;
					this->_end_node = this->_allocNode.allocate(1);
					this->set_end_node();
			}
			
			~Tree() {
				this->clear();
				this->_allocNode.deallocate(this->_end_node, 1);
			}

			Tree&			operator=(const Tree& x)
			{		
				if(this == &x)
					return *this;
				destroyNode(this->_root);
				this->_root = 0;
				this->_allocNode.deallocate(this->_end_node, 1);
				this->_allocValue = x._allocValue;
				this->_allocNode = x._allocNode;
				this->_end_node = this->_allocNode.allocate(1);
				this->_comp = x._comp;
				this->_root = copyNode(this->_root, x._root);
				this->set_end_node();
				return *this;
			}

			//					~ Capacity ~
			
			size_type		size() const {
				return sizeNode(this->_root);
			}
			
			int				height() const {
				return heightNode(this->_root);
			}
			
			size_type		max_size() const { return this->_allocNode.max_size(); }
			//					~ Element access ~
			
			
			mapped_type& 	operator[](const key_type& k) {
				Node* node = this->find(k);
				if (node)
					return node->value.second;
				this->_root = insertNode(this->_root,
				ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
				this->set_end_node();
				return (*this)[k];
			}
			
			//					~ Modifiers ~
			
			// empty node which represents the end of the tree (after the biggest element)
			void			set_end_node() {
				if (this->_root)
					this->_end_node->parent = this->_root->max();
				else
					this->_end_node->parent = 0;
				this->_end_node->right = 0;
				this->_end_node->left = 0;
			}

			void			swap(Tree& x) {
				Node* tmp = this->_root;
				this->_root = x._root;
				x._root = tmp;
			}
			
			void			insertValue(const value_type& val) {
				this->_root = insertNode(this->_root, val);
				this->set_end_node();
			}

			void			deleteKey(const key_type key) {
				this->_root = deleteNode(this->_root, key);
				this->set_end_node();
			}
			
			void			clear() {
				if (this->_root)
					destroyNode(this->_root->getParent());
				this->_root = 0;
				this->set_end_node();
			}
			
			//					~ Observers ~
			
			Node*			begin_node() const { return this->_root ? this->_root->min() : this->_end_node; }
			Node*			end_node() const { return this->_end_node; }
			Node*			root() const { return this->_root; }
			key_compare		key_comp() const { return this->_comp; }
			value_compare	value_comp() const { return value_compare(this->_comp); }
			
			//					~ Operator ~
			
			Node*			find(const key_type& k) const
			{
				Node *tmp = this->_root;
				while (tmp)
				{
					if (this->_comp(k, tmp->value.first))
						tmp = tmp->left;
					else if (this->_comp(tmp->value.first, k))
						tmp = tmp->right;
					else
						return tmp;
				}
				return 0;
			}
			
		private:
			//					~ Balance (avl) ~

			// put x under the left side of top
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

			// put y under the right side of top
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
			
			// calcul balance factor
			int				balanceFactor(Node* node) const {
				if (!node)
					return 0;
				return heightNode(node->right) - heightNode(node->left);
			}
			
			Node*			balance_after_insert(Node* node, const key_type key)
			{
				int bf = balanceFactor(node);
				
				// Left Left Case
				if (bf < -1 && this->_comp(key, node->left->value.first))
					return rightRotate(node);
				// Right Right Case
				if (bf > 1 && this->_comp(node->right->value.first, key))
					return leftRotate(node);
				// Left Right Case
				if (bf < -1 && this->_comp(node->left->value.first, key))
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
				// Right Left Case
				if (bf > 1 && this->_comp(key, node->right->value.first))
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
				
				return node;
			}
			
			Node*			balance_after_delete(Node* node)
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

		public:
			//					~ Node utils ~
			
			size_type		sizeNode(Node* node) const {
				size_type s = 0;
				if (node)
				{
					s += sizeNode(node->right);
					s += sizeNode(node->left);
					++s;
				}
				return s;
			}
			
			int				heightNode(Node* node, int h = 0) const
			{
				if (node)
				{
					h++;
					int tmp = h;
					h = heightNode(node->right, h);
					tmp = heightNode(node->left, tmp); 
					h = h > tmp ? h : tmp;
				}
				
				return h;
			}
			
			Node*			copyNode(Node* dest, Node* src) {
				if (src)
				{
					dest = copyNode(dest, src->left);
					dest = copyNode(dest, src->right);
					dest = insertNode(dest, src->value);
				}
				return dest;
			}
			
			Node*			newNode(value_type val, Node* parent)
			{
				Node* node;
				
				node = this->_allocNode.allocate(1);
				this->_allocValue.construct(&node->value, val);
				
				node->parent = parent;
				node->left = 0;
				node->right = 0;

				return node;
			}
			
			Node*			insertNode(Node* node, const value_type& val, Node* parent = 0)
			{
				if (!node)
					return newNode(val, parent);

				if (this->_comp(val.first, node->value.first))
					node->left = insertNode(node->left, val, node);
				else if (this->_comp(node->value.first, val.first))
					node->right = insertNode(node->right, val, node);
				else
					return node;

				node = this->balance_after_insert(node, val.first);
				
				return node;
			}


			Node*			deleteNode(Node* node, const key_type key)
			{
				if (!node)
					return node;
				if (this->_comp(key, node->value.first))
					node->left = deleteNode(node->left, key);
				else if (this->_comp(node->value.first, key))
					node->right = deleteNode(node->right, key);
				else
				{
					if (!node->left || !node->right)
					{
						Node* tmp = node;
						node = node->left ? node->left : node->right;
						if (node)
							node->parent = tmp->parent;
						this->_allocValue.destroy(&tmp->value);
						this->_allocNode.deallocate(tmp, 1);
						
					}
					else
					{
						// find the greatest smaller
						Node *tmp = node->right->min();

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
						tmp->parent->left = 0;
						tmp->parent = node->parent;
						// destroy it
						this->_allocValue.destroy(&node->value);
						this->_allocNode.deallocate(node, 1);
						node = tmp;
					}
				}
				node = balance_after_delete(node);
				return node;
			}
			
			void			destroyNode(Node *node) {
				if (node)
				{
					destroyNode(node->left);
					destroyNode(node->right);
					this->_allocValue.destroy(&node->value);
					this->_allocNode.deallocate(node, 1);
				}
			}

		private:
			key_compare				_comp;
			allocator_type  		_allocValue;
			std::allocator<Node>	_allocNode;
			Node*					_root;
			Node*					_end_node;
    };
}

#endif
