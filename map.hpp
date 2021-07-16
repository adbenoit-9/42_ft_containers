/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/16 19:41:31 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <tgmath.h>
#include <functional>
# include "pair.hpp"
// # include "iter/iterator.hpp"
// # include "iter/reverse_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<pair<const Key,T> >  >
	class map
	{
			/**
			 * ================================================= PUBLIC =================================================
			 * 
			 * explicit map(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
			 * template <class InputIterator>
			 * map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			 * map(const map& x);
			 *
			 * ~map();
			 * 
			 * map&									operator=(const map& x);
			 * 
			 * 					~ Iterators ~
			 * 
			 * iterator								begin();
			 * const_iterator						begin() const;
			 * iterator								end();
			 * const_iterator						end() const;
			 * reverse_iterator						rbegin();
			 * const_reverse_iterator				rbegin() const;
			 * reverse_iterator						rend();
			 * const_reverse_iterator				rend() const;
			 * 
			 * 					~ Capacity ~
			 * 
			 * bool									empty() const;
			 * size_type							size() const;
			 * size_type							max_size() const;
			 * 
			 * 					~ Element access ~
			 * 
			 * mapped_type&							operator[](const key_type& k);			 * 
			 * 
			 * 					~ Modifiers ~
			 * 
			 * pair<iterator,bool>					insert(const value_type& val);
			 * iterator 							insert(iterator position, const value_type& val);
			 * template <class InputIterator>
			 * void									insert(InputIterator first, InputIterator last);
			 * void									erase(iterator position);
			 * size_type							erase(const key_type& k);
			 * void									erase(iterator first, iterator last);
			 * void									swap(map& x);
			 * void 								clear();
			 * 
			 *                  ~ Observers ~
			 * 
			 * key_compare              			key_comp() const;
			 * value_compare            			value_comp() const;
			 * 
			 *                  ~ Operations ~
			 * 
			 * iterator								find(const key_type& k);
			 * const_iterator						find(const key_type& k) const;
			 * size_type							count(const key_type& k) const;
			 * iterator								lower_bound(const key_type& k);
			 * const_iterator						lower_bound(const key_type& k) const;
			 * iterator 							upper_bound(const key_type& k);
			 * const_iterator						upper_bound(const key_type& k) const;
			 * pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			 * pair<iterator,iterator>				equal_range(const key_type& k);
			 * 
			 * ================================================= PRIVATE =================================================
			 * 
			 * pointer			_begin; 
			 * Alloc			_alloc;
			 * size_type 		_size;
			 * 
			 **/

		public:
				
			typedef Key 										key_type;
			typedef T 										    mapped_type;
			typedef ft::pair<const Key, T>                      value_type;
			typedef	Compare										key_compare;
			typedef 											value_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	iterator<T>									iterator;
			typedef	const_iterator<T>							const_iterator;
			typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	reverse_iterator<iterator>					reverse_iterator;	
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

			explicit map(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
				_comp(comp), _alloc(alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_comp(comp), _alloc(alloc), _size(last - first)
			{
				
			}
			
			map(const map& x) : _comp(x._comp), _alloc(x._comp), _size(x.size)
			{
				this->alloc(this->_begin, this->size);
				// for ()
			}
			
			// ~map()
			// {
			// }

			// map& operator=(const map& x)
			// {		
			// 	if(this == &x)
			// 		return *this;

			// 	return *this;
			// }

			// // Iterators
			
			iterator begin() { return iterator(this->_begin); }
			const_iterator begin() const { return const_iterator(this->_begin); }

			iterator end() { return iterator(this->_begin) + this->_size; }
			const_iterator end() const { return const_iterator(this->_begin + this->_size); }

			reverse_iterator rbegin() { return reverse_iterator(iterator(this->_begin + this->_size - 1)); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(iterator(this->_begin + this->_size - 1)); }

			reverse_iterator rend() { return reverse_iterator(iterator(this->_begin - 1)); }
			const_reverse_iterator rend() const { return const_reverse_iterator(iterator(this->_begin - 1)); } 

			// Capacity

			size_type	size() const { return this->_size; }

			size_type	max_size() const
			{
				if(sizeof(value_type) == 1)
					return(static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1);
				return(static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1);
			} 
			
			bool		empty() const		{ return(this->_size == 0); }

			// Element access
			
			mapped_type& 				operator[](const key_type& k)
			{
				 
			}

			// Modifiers

			// pair<iterator,bool>			insert(const value_type& val);
			// iterator					insert(iterator position, const value_type& val);
			// template <class InputIterator>
  			// void						insert(InputIterator first, InputIterator last);
			
			// void						erase(iterator position);
			// size_type					erase(const key_type& k);
			// void						erase(iterator first, iterator last);

			// void						swap(map& x)
			// {
			// 	map tmp = *this;
				
			// 	*this = x;
			// 	x = tmp;
			// }

			// void						clear()
			// {
			// 	for(iterator it = this->begin(); it != this->end(); it++)
			// 		this->_alloc.destroy(&*it);
			// 	this->_size = 0;
			// }
			
			//                 ~ Observers ~
			
			key_compare              key_comp() const { return this->_comp; }
			value_compare            value_comp() const { return ; }
			
			// //                 ~ Operations ~
			
			// iterator							find(const key_type& k);
			// const_iterator						find(const key_type& k) const;
			// size_type							count(const key_type& k) const;
			// iterator							lower_bound(const key_type& k);
			// const_iterator						lower_bound(const key_type& k) const;
			// iterator 							upper_bound(const key_type& k);
			// const_iterator						upper_bound(const key_type& k) const;
			// pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			// pair<iterator,iterator>				equal_range(const key_type& k);
			

		private:
			pointer			_begin;
			key_compare		_comp;
			allocator_type	_alloc;
			size_type 		_size;
	};
}

#endif
