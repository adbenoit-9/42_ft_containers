/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:40 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/02 15:03:59 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Iterators_traits.hpp"

template <class Iterator>
class reverse_iterator
{
	private:
		typedef Iterator         										iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		pointer _ptr;

	public:
		reverse_iterator() {}
		explicit reverse_iterator (iterator_type it) { this->_ptr = it._ptr - 1; }
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it) { this->_ptr = rev_it._ptr; }

		iterator_type base() const { return Iterator(this->_ptr + 1); }
		

		// operators : assignment
		reverse_iterator&	operator+=(difference_type n) { this->_ptr -= n; return *this; }
		reverse_iterator&	operator-=(difference_type n) { this->_ptr += n; return *this; }

		// operators : member access
		reference   		operator*() const { return *this->_ptr; }
		pointer				operator->() const { return &(operator*()); }
		reverse_iterator&	operator[] (difference_type n) const { return base()[-n - 1]; }

		// // operators : increment / decrement
		reverse_iterator&   operator++() { this->_ptr--; return *this; }
		reverse_iterator    operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
		reverse_iterator&   operator--() { this->_ptr++; return *this; }
		reverse_iterator    operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }

		// operators : arithmetic
  		reverse_iterator	operator+ (difference_type n) const { reverse_iterator tmp(*this); tmp._ptr -= - n; return tmp; }
  		reverse_iterator	operator- (difference_type n) const { reverse_iterator tmp(*this); tmp._ptr += n; return tmp; }

		friend reverse_iterator operator+ (difference_type n, const reverse_iterator& rev_it) { reverse_iterator tmp(rev_it); tmp._ptr -= n; return tmp; }
		friend reverse_iterator operator- (difference_type n, const reverse_iterator& rev_it) { reverse_iterator tmp(rev_it); tmp._ptr += n; return tmp; }

		// // operators : comparison
		friend bool operator== (const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.base() == rhs.base(); }
		friend bool operator!= (const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.base() != rhs.base(); }
		friend bool operator< (const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.base() < rhs.base(); }
		friend bool operator<= (const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.base() <= rhs.base(); }
		friend bool operator> (const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.base() > rhs.base(); }
		friend bool operator>= (const reverse_iterator& lhs, const reverse_iterator& rhs) { return lhs.base() >= rhs.base(); }
};

#endif
