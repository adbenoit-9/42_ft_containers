/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:07:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/20 18:13:37 by adbenoit         ###   ########.fr       */
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
	
	// template <	class Category, class T, class not_const_T = T>
	template <	class Category, class T, class not_const_T = T>
	class map_iterator
	{
		public:
			typedef typename T::value_type				value_type;
			typedef typename not_const_T::Node			Node;
			typedef typename T::key_type				key_type;
			typedef typename T::mapped_type				mapped_type;
			typedef	typename T::key_compare				key_compare;
			typedef typename T::difference_type			difference_type;
			typedef typename T::pointer   				pointer;
			typedef typename T::reference 				reference;
			typedef Category							iterator_category;

			map_iterator() {}
			map_iterator(const map_iterator<Category, not_const_T> &toCopy) : _ptr(toCopy.base()), _end(toCopy.end()) {}
			map_iterator(Node* node, Node* end) {
				this->_ptr = node;
				this->_end = end;
			}
			virtual ~map_iterator() {}

			Node*			base() const { return this->_ptr; }
			Node*			end() const { return this->_end; }
			
			// operators : assignment
			// map_iterator&	operator=(Node* ptr) { this->_ptr = ptr; return *this; }
			map_iterator&	operator=(const map_iterator<Category, not_const_T> &toCopy) {
				this->_ptr = toCopy._ptr;
				this->_end = toCopy._end;
				return *this;
			}

			// operators : member access
			reference   	operator*() const { return this->_ptr->value; }
			pointer     	operator->() const { return &(operator*()); }

			// operators : increment / decrement
			map_iterator&   operator++()
			{
				// find the smallest greater
				if (this->_ptr->right)
				{
					this->_ptr = this->_ptr->right->getMinimum();
					return *this;
				}
				else if (this->_ptr->parent)
				{
					// find first previous greater node
					key_type key = this->_ptr->value.first;
					Node *tmp = this->_ptr->parent;
					while (tmp && this->_key_comp(tmp->value.first, key))
						tmp = tmp->parent;
					if (tmp)
					{
						this->_ptr = tmp;
						return *this;
					}
				}
				this->_ptr = this->_end;
				return *this;
			}
			
			map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
			
			map_iterator&   operator--()
			{
				// find the greatest smaller
				if (this->_ptr == this->_end)
				{
					this->_ptr = this->_ptr->parent;
					return *this;
				}
				else if (this->_ptr->left)
				{
					this->_ptr = this->_ptr->left->getMaximum();
					return *this;
				}
				else if (this->_ptr->parent)
				{
					// find first previous smaller node
					key_type key = this->_ptr->value.first;
					Node *tmp = this->_ptr->parent;
					while (tmp && this->_key_comp(key, tmp->value.first))
						tmp = tmp->parent;
					if (tmp)
					{
						this->_ptr = tmp;
						return *this;
					}
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
				return lhs._ptr == rhs._ptr; }
			friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) {
				return lhs._ptr != rhs._ptr; }

		private:
			Node*		_ptr;
			Node*		_end;
			key_compare	_key_comp;
	};
}

#endif
