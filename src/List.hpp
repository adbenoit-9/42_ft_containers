/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:14:59 by adbenoit          #+#    #+#             */
/*   Updated: 2021/06/28 16:41:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>

template< class T, class Allocator = std::allocator<T> > 
class List
{
	private:
		typedef	T value_type;
		typedef	Allocator allocator_type;
		typedef	size_t size_type;
		typedef	ptrdiff_t difference_type;
		typedef	T& reference;
		typedef	const T&  const_reference;
		typedef	Allocator::pointer pointer;
		typedef	Allocator::const_pointer const_pointer;
		typedef	LegacyBidirectionalIterator iterator;		//to value_type
		typedef	LegacyBidirectionalIterator const_iterator;	//to const value_type
		typedef	std::reverse_iterator<iterator> reverse_iterator;	
		typedef	std::reverse_iterator<const_iterator> const_reverse_iterator;

		size_type	_size;
		T			*_values;

	public:
		List();
		explicit List(const Allocator& alloc);
		explicit List(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template< class InputIt >
		List(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		List(const List& other);
		~List();
		List&			operator=(const List& other);

		void				assign(size_type count, const T& value);
		template< class InputIt >
		void				assign(InputIt first, InputIt last);
 
		/*
		** Element access
		*/
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

		/*
		** Iterators
		*/
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		/*
		** Capacity
		*/
		bool					empty() const;
		size_type				size() const;
		size_type				max_size() const; 

		/*
		** Modifiers
		*/
		void 					clear();
		iterator				insert(iterator pos, const T& value);
		void					insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void					insert(iterator pos, InputIt first, InputIt last);
		iterator				erase(iterator pos);
		iterator				erase(iterator first, iterator last);
		void					push_back(const T& value);
		void					pop_back();
		void					push_front(const T& value);
		void					pop_front();
		void					resize(size_type count, T value = T());
		void					swap(List& other);
 
		/*
		** Operations
		*/
		void					merge(List& other);
		template <class Compare> 
		void					merge(List& other, Compare comp);
		void					splice(const_iterator pos, List& other);
		void					splice(const_iterator pos, List& other, const_iterator it);
		void					splice(const_iterator pos, List& other, const_iterator first, const_iterator last);
		void					remove( const T& value );
		template<class UnaryPredicate>
		void					remove_if(UnaryPredicate p);
		void					reverse();
		void					unique();
		template<class BinaryPredicate>
		void					unique(BinaryPredicate p);
		void					sort();
		template<class Compare> 
		void					sort(Compare comp);
};

#include "List.tpp"
// operator==
// operator!=
// operator<
// operator<=
// operator>=

// std::swap()

// erase()
// erase_if()

#endif
