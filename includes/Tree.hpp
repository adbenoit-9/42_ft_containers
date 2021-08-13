/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/08/13 17:21:01 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
// # include <functional>
# include "pair.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator< pair<const Key,T> >  >
    class Tree
    {
        public:
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
			// typedef	map_iterator<bidirectional_iterator_tag, value_type,
			// ptrdiff_t, const value_type*, const value_type&>				const_iterator;
			// typedef	map_iterator<bidirectional_iterator_tag, value_type>	iterator;
			// typedef	reverse_iterator<const_iterator>					const_reverse_iterator;
			// typedef	reverse_iterator<iterator>							reverse_iterator;	
			struct Node
			{
				value_type		value;
				struct Node		*left;
				struct Node		*right;
				struct Node		*parent;

				Node(const Node& x)
				{
					value = x.value;
					left = x.left;
					right = x.right;
					parent = x.parent;
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
					bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};
            
            explicit Tree(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
                _key_comp(comp), _alloc(alloc), _allocNode(allocator_type()), _size(0) { this->_root = nullptr; }
            
			Tree(const Tree& x) { this->_root = nullptr; *this = x; }
			
            ~Tree()
            {
				this->destroy(getParent(this->_root));
            }


			Tree& operator=(const Tree& x)
			{		
				if(this == &x)
					return *this;
				destroy(this->_root);
				this->_root = constructNode();
				this->_root.parent = x._root.parent;
				this->_root.left = x._root.left;
				this->_root.right = x._root.right;
				this->_size = x._size;
				this->_key_comp = x._key_comp;
				this->_alloc = x._alloc;
				this->_allocNode = x._allocNode;
				return *this;
			}

			//					~ Iterators ~

			Node*					getParent(Node* node)
			{
                while (node && node->parent)
					node = node->parent;
				return node;
			}
			
			// Tree					getParent()
			// {
			// 	Tree tree = *this;
            //     while (tree._root && tree._root->parent)
			// 		tree._root = tree._root->parent;
			// 	return tree;
			// }

 			size_type				size() const { return this->_size; }

 			size_type				max_size() const { return this->_alloc.max_size(); }

 			bool					empty() const { return this->_size == 0; }

            mapped_type& 			operator[](const key_type& k)
			{
				Node *tmp;

				tmp = this->_root;
				while (tmp)
				{
					if (k == tmp->value.first)
						return tmp->value.second;
					else if (this->_key_comp(k, tmp->value.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
			}
			
			bool					insertNode(Node* node)
			{
				Node *tmp;

				tmp = this->_root;
				while (tmp)
				{
					node->parent = tmp;
					if (this->_key_comp(node->value.first, tmp->value.first))
						tmp = tmp->left;
					else if (this->_key_comp(tmp->value.first, node->value.first))
						tmp = tmp->right;
					else
						return 1;
				}				
				tmp = node;
				return 0;
				
			}
			
			Node*	constructNode(value_type val, Node* parent = nullptr)
			{
				Node *node;
				
				this->_allocNode.allocate(node, 1);
				this->_alloc.construt(&val, node->value);
				node->left = 0;
				node->right = 0;
				node->parent = parent;

				return node;
			}
			
			void				destroy(Node *node)
			{
				if (node)
				{
					destroy(node->left);
					destroy(node->right);
					this->_alloc.destroy(&node->value);
					this->_allocNode.destroy(node);
					this->_allocNode.deallocate(node, 1);
				}
			}
			
			void					swap(Tree& x)
			{
				Tree tmp = *this;
				
				*this = x;
				x = tmp;
			}

			void					clear()
			{
                while (this->_root->parent)
					this->_root = this->_root->parent;
				this->destroy(this->_root);
				this->_size = 0;
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


        private:
            key_compare				_key_comp;
            allocator_type  		_alloc;
            std::allocator< Node >  _allocNode;
			size_type 				_size;
            Node					*_root;
    };
}

#endif
