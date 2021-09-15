/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:07:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/15 18:01:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

namespace ft
{
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};
	
	/*
	**		VECTOR ITERATOR
	*/

	template <	class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class vector_iterator
	{
		public:
			typedef T         						value_type;
			typedef Distance						difference_type;
			typedef Pointer   						pointer;
			typedef Reference 						reference;
			typedef Category						iterator_category;

			vector_iterator() {}
			vector_iterator(const vector_iterator<Category, T, Distance, T*, T&> &toCopy) : _ptr(toCopy.base()) {}
			vector_iterator(T* ptr) : _ptr(ptr) {}
			virtual ~vector_iterator() {}

			T*			base() const { return this->_ptr ; } 
			// operators : assignment
			vector_iterator&	operator=(pointer ptr) { this->_ptr = ptr; return *this; }
			vector_iterator&	operator=(const vector_iterator &toCopy) { this->_ptr = toCopy._ptr; return *this; }
			vector_iterator&	operator+=(difference_type n) { this->_ptr += n; return *this; }
			// vector_iterator&	operator+=(const vector_iterator &it) { this->_ptr += it._ptr; return *this; }
			vector_iterator&	operator-=(difference_type n) { this->_ptr -= n; return *this; }
			vector_iterator&	operator-=(const vector_iterator &it) { this->_ptr -= it._ptr; return *this; }

			// operators : member access
			reference   		operator*() const { return *this->_ptr; }
			pointer     		operator->() const { return &(operator*()); }
			reference			operator[](const difference_type &i) { return this->_ptr[i]; }

			// operators : increment / decrement
			vector_iterator&   operator++() { this->_ptr++; return *this; }
			vector_iterator    operator++(int) { vector_iterator tmp = *this; ++*this; return tmp; }
			vector_iterator&   operator--() { this->_ptr--; return *this; }
			vector_iterator    operator--(int) { vector_iterator tmp = *this; --*this; return tmp; }

			// operators : arithmetic
			friend vector_iterator	operator+(const vector_iterator& it, difference_type n) { return vector_iterator(it._ptr + n); }
			friend vector_iterator	operator+(difference_type n, const vector_iterator& it) { return vector_iterator(it._ptr + n); }
			friend vector_iterator	operator-(const vector_iterator& it, difference_type n) { return vector_iterator(it._ptr - n); }
			friend vector_iterator	operator-(difference_type n, const vector_iterator& it) { return vector_iterator(it._ptr - n); }
			friend difference_type	operator-(const vector_iterator& a, const vector_iterator& b) { return (a._ptr - b._ptr); }

			// operators : comparison
			friend bool 	operator== (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr == rhs._ptr; }
			friend bool 	operator!= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr != rhs._ptr; }
			friend bool 	operator< (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr < rhs._ptr; }
			friend bool 	operator<= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr <= rhs._ptr; }
			friend bool 	operator> (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr > rhs._ptr; }
			friend bool 	operator>= (const vector_iterator& lhs, const vector_iterator& rhs) { return lhs._ptr >= rhs._ptr; }

		private:
			T*	_ptr;
	};


	/*
	**		MAP ITERATOR
	*/
	
	template <	class Category, class T >
	class map_iterator
	{
		public:
			typedef typename T::value_type				value_type;
			typedef typename T::Node					Node;
			typedef typename value_type::first_type		key_type;
			typedef typename value_type::second_type	mapped_type;
			typedef typename T::difference_type			difference_type;
			typedef typename T::pointer   				pointer;
			typedef typename T::reference 				reference;
			typedef Category							iterator_category;
			// typedef Tree<key_type, 

			map_iterator() {}
			map_iterator(const map_iterator<Category, T> &toCopy) { this->_ptr = toCopy.base(); }
			map_iterator(Node* node) { this->_ptr = node; }
			virtual ~map_iterator() {}

			Node*		base() const { return this->_ptr; }
			
			// operators : assignment
			// map_iterator&	operator=(pointer ptr) { this->_ptr = ptr; return *this; }
			map_iterator&	operator=(const map_iterator &toCopy) { this->_ptr = toCopy._ptr; return *this; }

			// operators : member access
			reference   	operator*() const { return this->_ptr->value; }
			pointer     	operator->() const { return &(operator*()); }

			// operators : increment / decrement
			map_iterator&   operator++()
			{
				// find the smallest greater
				if (this->_ptr->right)
				{
					this->_ptr = this->_ptr->right;
					while (this->_ptr->left)
							this->_ptr = this->_ptr->left;
				}
				// else if (this->_ptr->parent)
				// {
				// 	// find first previous greater node
				// 	Node *tmp = this->_ptr->parent;
				// 	while (tmp->parent && tmp->value < this->_ptr->value)
				// 		tmp = tmp->parent;
				// 	this->_ptr = tmp;
				// }
				else
				{
					// is the greater
					std::cout << "wtf\n";
					// ptr = end
				}
				
				return *this;
			}
			
			map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
			
			map_iterator&   operator--()
			{
				// find the greatest smaller
				if (this->_ptr->left)
				{
					this->root = this->_ptr->left;
					while (this->_ptr->right)
							this->_ptr = this->_ptr->right;
				}
				else if (this->_ptr->parent)
				{
					// find first previous smaller node
					T *tmp = this->_ptr->parent;
					while (this->_ptr->value < tmp->value)
						tmp = tmp->parent;
					this->_node = tmp;
				}
				else
				{
					// undefined
				}
				
				return *this;
			}
			
			map_iterator    operator--(int) { map_iterator tmp = *this; --*this; return tmp; }

			// operators : comparison
			friend bool		operator== (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr->value == rhs._ptr->value; }
			friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr->value != rhs._ptr->value; }

		private:
			Node*	_ptr;
	};
	// template <	class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	// class map_iterator
	// {
	// 	public:
	// 		typedef T         							value_type;
	// 		typedef typename value_type::first_type		key_type;
	// 		typedef typename value_type::second_type	mapped_type;
	// 		typedef Distance							difference_type;
	// 		typedef Pointer   							pointer;
	// 		typedef Reference 							reference;
	// 		typedef Category							iterator_category;
	// 		// typedef Tree<key_type, 

	// 		map_iterator() {}
	// 		map_iterator(const map_iterator<Category, T, Distance, T*, T&> &toCopy) : _node(toCopy.base()) {}
	// 		map_iterator(T* ptr) : _node(ptr) {}
	// 		virtual ~map_iterator() {}

	// 		T*				base() const { return this->_node ; }
			
	// 		// operators : assignment
	// 		map_iterator&	operator=(pointer ptr) { this->_node = ptr; return *this; }
	// 		map_iterator&	operator=(const map_iterator &toCopy) { this->_node = toCopy._node; return *this; }

	// 		// operators : member access
	// 		reference   	operator*() const { return *this->_node; }
	// 		pointer     	operator->() const { return &(operator*()); }

	// 		// operators : increment / decrement
	// 		map_iterator&   operator++()
	// 		{
	// 			// find the smallest greater
	// 			if (this->_node.right)
	// 				while (this->_node.left)
	// 						this->ptr = this->_node.left;
	// 			else if (this->_node.parent != this->_node)
	// 			{
	// 				// find first previous greater node
	// 				T *tmp = this->_node.parent;
	// 				while (this->_node._key_comp(tmp->value.first,this->_node.value.first))
	// 					tmp = tmp->parent;
	// 				this->_node = tmp;
	// 			}
	// 			else
	// 			{
	// 				// ptr = end
	// 			}
				
	// 			return *this;
	// 		}
			
	// 		map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
			
	// 		map_iterator&   operator--()
	// 		{
	// 			// find the greatest smaller
	// 			if (this->_node.left)
	// 				while (this->_node.right)
	// 						this->ptr = this->_node.right;
	// 			else if (this->_node.parent != this->_node)
	// 			{
	// 				// find first previous smaller node
	// 				T *tmp = this->_node.parent;
	// 				while (this->_node._key_comp(this->_node.value.first, tmp->value.first))
	// 					tmp = tmp->parent;
	// 				this->_node = tmp;
	// 			}
	// 			else
	// 			{
	// 				// undefined
	// 			}
				
	// 			return *this;
	// 		}
			
	// 		map_iterator    operator--(int) { map_iterator tmp = *this; --*this; return tmp; }

	// 		// operators : comparison
	// 		friend bool		operator== (const map_iterator& lhs, const map_iterator& rhs) { return lhs._node.value == rhs._node.value; }
	// 		friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) { return lhs._node.value != rhs._node.value; }

	// 	private:
	// 		Tree*	_node;
	// };
}

#endif
