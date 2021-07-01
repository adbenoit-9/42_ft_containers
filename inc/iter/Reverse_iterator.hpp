/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:40 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/01 19:14:36 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Iterators_traits.hpp"

template <class Iterator>
class reverse_iterator
{
	private:
		typedef Iterator         								iterator_type;
		typedef iterator_traits<Iterator>::iterator_category    iterator_category;
		typedef iterator_traits<Iterator>::value_type			value_type;
		typedef iterator_traits<Iterator>::difference_type		difference_type;
		typedef iterator_traits<Iterator>::pointer				pointer;
		typedef iterator_traits<Iterator>::reference			reference;

		pointer _ptr;

	public:
		reverse_iterator() {}
		explicit reverse_iterator (iterator_type it) { this->_ptr = it._ptr - 1; }
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it) { this->_ptr = rev_it._ptr; } 

		// operators : assignment
		// Iterator&	operator=(Iterator &it) { this->_ptr = it->_ptr; return this; }
		// Iterator&	operator=(pointer ptr) { this->_ptr = ptr; return this; }
		// Iterator&	operator+=(const int &n) { this->_ptr = this->_ptr + n; return *this; }
		// Iterator&	operator+=(const Iterator &it) { this->_ptr = this->_ptr + it; return *this; }
		// Iterator&	operator-=(const int &n) { this->_ptr = this->_ptr - n; return *this; }
		// Iterator&	operator-=(const Iterator &it) { this->_ptr = this->_ptr - it; return *this; }

		// // operators : member access
		// reference   operator*() const { return *_ptr; }
		// pointer     operator->() { return this->_ptr; }
		// T&			operator[](const int &i) { return this->_ptr[i]; }

		// // operators : increment / decrement
		// Iterator&   operator++() { this->_ptr++; return *this; }
		// Iterator    operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		// Iterator&   operator--() { this->_ptr--; return *this; }
		// Iterator    operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

		// // operators : arithmetic
  		// reverse_iterator operator+ ( difference_type n, const reverse_iterator& rev_it) { return Iterator(it.__ptr - n); }

		// // operators : comparison
		// friend bool operator== (const Iterator& a, const Iterator& b) { return a._ptr == b._ptr; }
		// friend bool operator!= (const Iterator& a, const Iterator& b) { return a._ptr != b._ptr; }
		// friend bool operator< (const Iterator& a, const Iterator& b) { return a._ptr < b._ptr; }
		// friend bool operator> (const Iterator& a, const Iterator& b) { return a._ptr > b._ptr; }
		// friend bool operator<= (const Iterator& a, const Iterator& b) { return a._ptr <= b._ptr; }
		// friend bool operator>= (const Iterator& a, const Iterator& b) { return a._ptr >= b._ptr; }
};

#endif
