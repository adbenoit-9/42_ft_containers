/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:07:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/29 14:51:40 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

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
			vector_iterator&	operator+=(const vector_iterator &it) { this->_ptr += it._ptr; return *this; }
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

	template <	class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class map_iterator
	{
		public:
			typedef T         						value_type;
			typedef Distance						difference_type;
			typedef Pointer   						pointer;
			typedef Reference 						reference;
			typedef Category						iterator_category;

			map_iterator() {}
			map_iterator(const map_iterator<Category, T, Distance, T*, T&> &toCopy) : _tree(toCopy.base()) {}
			map_iterator(T* ptr) : _tree(ptr) {}
			virtual ~map_iterator() {}

			T*				base() const { return this->_tree ; }

			bool			equalKey(pointeur value1, pointeur value2) const
			{
				return !(value1->comp(value1->value.first, value2->value.first))
						&& !(value1->comp(value2->value.first,value1->value.first));
			}
			
			// operators : assignment
			map_iterator&	operator=(pointer ptr) { this->_tree = ptr; return *this; }
			map_iterator&	operator=(const map_iterator &toCopy) { this->_tree = toCopy._tree; return *this; }

			// operators : member access
			reference   	operator*() const { return *this->_tree; }
			pointer     	operator->() const { return &(operator*()); }

			// operators : increment / decrement
			map_iterator&   operator++()
			{
				// find the smallest greater
				if (this->_tree.right)
					while (this->_tree.left)
							this->ptr = this->_tree.left;
				else if (this->_tree.parent != this->_tree)
				{
					// find first previous greater node
					t_tree *tmp = this->_tree.parent;
					while (this->_tree.comp(tmp.value.first,this->_tree.value.first))
						tmp = tmp->parent;
					this->_tree = tmp;
				}
				else
				{
					// ptr = end
				}
				
				return *this;
			}
			
			map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
			
			map_iterator&   operator--()
			{
				// find the greatest smaller
				if (this->_tree.left)
					while (this->_tree.right)
							this->ptr = this->_tree.right;
				else if (this->_tree.parent != this->_tree)
				{
					// find first previous smaller node
					t_tree *tmp = this->_tree.parent;
					while (this->_tree.comp(this->_tree.value.first, tmp.value.first))
						tmp = tmp->parent;
					this->_tree = tmp;
				}
				else
				{
					// undefined
				}
				
				return *this;
			}
			
			map_iterator    operator--(int) { map_iterator tmp = *this; --*this; return tmp; }

			// operators : comparison
			friend bool		operator== (const map_iterator& lhs, const map_iterator& rhs) { return lhs._tree.value == rhs._tree.value; }
			friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) { return lhs._tree.value != rhs._tree.value; }

		private:
			T	_tree;
	};
}

#endif