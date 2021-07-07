/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:40 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/07 15:54:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Iterators_traits.hpp"
# include <iostream>

template <class Iterator>
class reverse_iterator
{

	public:
		typedef Iterator         										iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		reverse_iterator() {}
		explicit reverse_iterator (iterator_type toCopy) : _it(toCopy - 1) {}
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it._it) {}

		iterator_type base() const { iterator_type tmp(this->_it); return ++tmp; }
		

		// operators : assignment
		template <class Iter>
		reverse_iterator&	operator=(const reverse_iterator<Iter> &rev_it) { this->_it = rev_it._it; return *this; }
		reverse_iterator&	operator+=(difference_type n) { this->_it -= n; return *this; }
		reverse_iterator&	operator-=(difference_type n) { this->_it += n; return *this; }

		// operators : member access
		reference   		operator*() const { return *this->_it; }
		pointer				operator->() const { return &(operator*()); }
		reverse_iterator&	operator[](difference_type n) const { return base()[-n - 1]; }

		// // operators : increment / decrement
		reverse_iterator&   operator++() { this->_it--; return *this; }
		reverse_iterator    operator++(int) { reverse_iterator tmp = *this; --*this; return tmp; }
		reverse_iterator&   operator--() { this->_it++; return *this; }
		reverse_iterator    operator--(int) { reverse_iterator tmp = *this; ++*this; return tmp; }

		// operators : arithmetic
  		reverse_iterator	operator+(difference_type n) const { reverse_iterator tmp(*this); tmp._it -= n; return tmp; }
  		reverse_iterator	operator-(difference_type n) const { reverse_iterator tmp(*this); tmp._it += n; return tmp; }

	private:
		iterator_type	_it;
};

template <class It>
reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n,
const typename reverse_iterator<It>::reverse_iterator& rev_it) { reverse_iterator<It> tmp(rev_it); tmp.base() -= n; return tmp; }
template <class It>
reverse_iterator<It> operator-(typename reverse_iterator<It>::difference_type n,
const typename reverse_iterator<It>::reverse_iterator& rev_it) { reverse_iterator<It> tmp(rev_it); tmp.base() += n; return tmp; }

// operators : comparison
template <class It>
bool operator== (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return lhs.base() == rhs.base(); }
template <class It>
bool operator!= (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return lhs.base() != rhs.base(); }
template <class It>
bool operator< (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return lhs.base() < rhs.base(); }
template <class It>
bool operator<= (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return lhs.base() <= rhs.base(); }
template <class It>
bool operator> (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return lhs.base() > rhs.base(); }
template <class It>
bool operator>= (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return lhs.base() >= rhs.base(); }

#endif
