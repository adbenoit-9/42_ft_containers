/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/06/30 18:49:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		private:
			typedef	T value_type;
			typedef	Alloc allocator_type;
			typedef	typename allocator_type::reference reference;
			typedef	typename allocator_type::const_reference const_reference;
			typedef	typename allocator_type::pointer pointer;
			typedef	typename allocator_type::const_pointer const_pointer;
			// typedef	LegacyBidirectionalIterator iterator;		//to value_type
			// typedef	LegacyBidirectionalIterator const_iterator;	//to const value_type
			// typedef	std::reverse_iterator<iterator> reverse_iterator;	
			// typedef	std::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef	ptrdiff_t difference_type;
			typedef	size_t size_type;

			// iterator 	_begin;
			// iterator 	_end;
			size_type 		_size;
			

		public:
			vector(const allocator_type& alloc = allocator_type());
			// vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			// vector(const vector& x);
	};

	template < class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type& alloc) 
	{
		alloc.allocate(0);
		alloc.construct(this->)
	}
	
}

#endif
