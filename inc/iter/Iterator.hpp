/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:07:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/02 15:05:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template <class T>
class Iterator
{
	private:
	    typedef T         						value_type;
    	typedef ptrdiff_t						difference_type;
    	typedef T*   							pointer;
    	typedef T& 								reference;
    	typedef std::random_access_iterator_tag	iterator_category;

		pointer _ptr;

	public:
		Iterator() {}
		Iterator(const Iterator &toCopy) : _ptr(toCopy._ptr) {}
		Iterator(const pointer ptr) : _ptr(ptr) {}
		~Iterator() {}

		// operators : assignment
		Iterator&	operator=(Iterator &it) { this->_ptr = it->_ptr; return this; }
		Iterator&	operator=(pointer ptr) { this->_ptr = ptr; return this; }
		Iterator&	operator+=(difference_type n) { this->_ptr += n; return *this; }
		Iterator&	operator+=(const Iterator &it) { this->_ptr += it._ptr; return *this; }
		Iterator&	operator-=(difference_type n) { this->_ptr -= n; return *this; }
		Iterator&	operator-=(const Iterator &it) { this->_ptr -= it._ptr; return *this; }

		// operators : member access
		reference   operator*() const { return *_ptr; }
		pointer     operator->() { return &(operator*()); }
		T&			operator[](const int &i) { return this->_ptr[i]; }

		// operators : increment / decrement
		Iterator&   operator++() { this->_ptr++; return *this; }
		Iterator    operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		Iterator&   operator--() { this->_ptr--; return *this; }
		Iterator    operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

		// operators : arithmetic
		friend Iterator	operator+(const Iterator& it, difference_type n) { return Iterator(it._ptr + n); }
		friend Iterator	operator+(const Iterator& a, const Iterator& b) { return Iterator(a._ptr + b._ptr); }
		friend Iterator	operator-(const Iterator& it, difference_type n) { return Iterator(it._ptr - n); }
		friend Iterator	operator-(const Iterator& a, const Iterator& b) { return Iterator(a._ptr - b._ptr); }

		// operators : comparison
		friend bool operator== (const Iterator& lhs, const Iterator& rhs) { return lhs._ptr == rhs._ptr; }
		friend bool operator!= (const Iterator& lhs, const Iterator& rhs) { return lhs._ptr != rhs._ptr; }
		friend bool operator< (const Iterator& lhs, const Iterator& rhs) { return lhs._ptr < rhs._ptr; }
		friend bool operator<= (const Iterator& lhs, const Iterator& rhs) { return lhs._ptr <= rhs._ptr; }
		friend bool operator> (const Iterator& lhs, const Iterator& rhs) { return lhs._ptr > rhs._ptr; }
		friend bool operator>= (const Iterator& lhs, const Iterator& rhs) { return lhs._ptr >= rhs._ptr; }
};

#endif