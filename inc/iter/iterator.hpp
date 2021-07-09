/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:07:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/09 15:48:13 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
	class iterator
	{

		public:
			typedef T         						value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*   							pointer;
			typedef T& 								reference;
			typedef std::random_access_iterator_tag	iterator_category;

			iterator() {}
			iterator(const iterator &toCopy) : _ptr(toCopy._ptr) {}
			iterator(const pointer ptr) : _ptr(ptr) {}
			~iterator() {}

			// operators : assignment
			iterator&	operator=(pointer ptr) { this->_ptr = ptr; return *this; }
			iterator&	operator=(const iterator &toCopy) { this->_ptr = toCopy._ptr; return *this; }
			iterator&	operator+=(difference_type n) { this->_ptr += n; return *this; }
			iterator&	operator+=(const iterator &it) { this->_ptr += it._ptr; return *this; }
			iterator&	operator-=(difference_type n) { this->_ptr -= n; return *this; }
			iterator&	operator-=(const iterator &it) { this->_ptr -= it._ptr; return *this; }

			// operators : member access
			reference   operator*() const { return *this->_ptr; }
			pointer     operator->() { return &(operator*()); }
			T&			operator[](const int &i) { return this->_ptr[i]; }

			// operators : increment / decrement
			iterator&   operator++() { this->_ptr++; return *this; }
			iterator    operator++(int) { iterator tmp = *this; ++*this; return tmp; }
			iterator&   operator--() { this->_ptr--; return *this; }
			iterator    operator--(int) { iterator tmp = *this; --*this; return tmp; }

			// operators : arithmetic
			friend iterator	operator+(const iterator& it, difference_type n) { return iterator(it._ptr + n); }
			friend iterator	operator+(const iterator& a, const iterator& b) { return iterator(a._ptr + b._ptr); }
			friend iterator	operator-(const iterator& it, difference_type n) { return iterator(it._ptr - n); }
			friend difference_type	operator-(const iterator& a, const iterator& b) { return (a._ptr - b._ptr); }

			// operators : comparison
			friend bool operator== (const iterator& lhs, const iterator& rhs) { return lhs._ptr == rhs._ptr; }
			friend bool operator!= (const iterator& lhs, const iterator& rhs) { return lhs._ptr != rhs._ptr; }
			friend bool operator< (const iterator& lhs, const iterator& rhs) { return lhs._ptr < rhs._ptr; }
			friend bool operator<= (const iterator& lhs, const iterator& rhs) { return lhs._ptr <= rhs._ptr; }
			friend bool operator> (const iterator& lhs, const iterator& rhs) { return lhs._ptr > rhs._ptr; }
			friend bool operator>= (const iterator& lhs, const iterator& rhs) { return lhs._ptr >= rhs._ptr; }

		private:
			pointer _ptr;
	};

	template <class T>
	class const_iterator
	{

		public:
			typedef const T         				value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*   							pointer;
			typedef T& 								reference;
			typedef std::random_access_iterator_tag	iterator_category;

			const_iterator() {}
			const_iterator(const const_iterator &toCopy) : _ptr(toCopy._ptr) {}
			const_iterator(const iterator<T> &other) : _ptr(&*other) {}
			~const_iterator() {}

			// operators : assignment
			const_iterator&	operator=(const const_iterator &toCopy) { this->_ptr = toCopy._ptr; return *this; }
			const_iterator&	operator+=(difference_type n) { this->_ptr += n; return *this; }
			const_iterator&	operator+=(const const_iterator &it) { this->_ptr += it._ptr; return *this; }
			const_iterator&	operator-=(difference_type n) { this->_ptr -= n; return *this; }
			const_iterator&	operator-=(const const_iterator &it) { this->_ptr -= it._ptr; return *this; }

			// operators : member access
			reference   operator*() const { return *this->_ptr; }
			pointer     operator->() { return &(operator*()); }
			// T&			operator[](const int &i) { return this->_ptr[i]; }

			// operators : increment / decrement
			const_iterator&   operator++() { this->_ptr++; return *this; }
			const_iterator    operator++(int) { const_iterator tmp = *this; ++*this; return tmp; }
			const_iterator&   operator--() { this->_ptr--; return *this; }
			const_iterator    operator--(int) { const_iterator tmp = *this; --*this; return tmp; }

			// operators : arithmetic
			friend const_iterator	operator+(const const_iterator& it, difference_type n) { return const_iterator(it._ptr + n); }
			friend const_iterator	operator+(const const_iterator& a, const const_iterator& b) { return const_iterator(a._ptr + b._ptr); }
			friend const_iterator	operator-(const const_iterator& it, difference_type n) { return const_iterator(it._ptr - n); }
			friend difference_type	operator-(const const_iterator& a, const const_iterator& b) { return (a._ptr - b._ptr); }

			// operators : comparison
			friend bool operator== (const const_iterator& lhs, const const_iterator& rhs) { return lhs._ptr == rhs._ptr; }
			friend bool operator!= (const const_iterator& lhs, const const_iterator& rhs) { return lhs._ptr != rhs._ptr; }
			friend bool operator< (const const_iterator& lhs, const const_iterator& rhs) { return lhs._ptr < rhs._ptr; }
			friend bool operator<= (const const_iterator& lhs, const const_iterator& rhs) { return lhs._ptr <= rhs._ptr; }
			friend bool operator> (const const_iterator& lhs, const const_iterator& rhs) { return lhs._ptr > rhs._ptr; }
			friend bool operator>= (const const_iterator& lhs, const const_iterator& rhs) { return lhs._ptr >= rhs._ptr; }

		private:
			pointer _ptr;
	};
}

#endif