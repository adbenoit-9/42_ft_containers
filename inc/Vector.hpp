/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/08 14:43:01 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <tgmath.h>
# include "iter/Iterator.hpp"
# include "iter/Reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
			/**
			 * ================================================= PUBLIC =================================================
			 * 
			 * explicit vector(const allocator_type& alloc = allocator_type());
			 * explicit vector(size_type n, const value_type& val = value_type(), 
			 * 					const allocator_type& alloc = allocator_type());
			 * 			template <class InputIterator>
			 * 			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			 * 			vector(const vector& x);
			 *
			 * 	~vector();
			 * 
			 * vector&	operator= (const vector& x);
			 * 
			 * 					~ Iterators ~
			 * 
			 * iterator					begin();
			 * const_iterator			begin() const;
			 * iterator					end();
			 * const_iterator			end() const;
			 * reverse_iterator			rbegin();
			 * const_reverse_iterator	rbegin() const;
			 * reverse_iterator			rend();
			 * const_reverse_iterator	rend() const;
			 * 
			 * 					~ Capacity ~
			 * 
			 * size_type				size() const;
			 * size_type				max_size() const;
			 * void						resize(size_type n, value_type val = value_type());
			 * size_type				capacity() const;
			 * bool						empty() const;
			 * void						reserve(size_type n); 
			 * 
			 * 					~ Element access ~
			 * 
			 * reference				operator[] (size_type n);
			 * const_reference			operator[] (size_type n) const;
			 * reference				at (size_type n);
			 * const_reference			at (size_type n) const;
			 * reference				front();
			 * const_reference			front() const;
			 * reference				back();
			 * const_reference			back() const;
			 * 
			 * 
			 * 					~ Modifiers ~
			 * 
			 * void						push_back(const T& value);
			 * void						pop_back();
			 * iterator					insert(iterator pos, const T& value);
			 * void						insert(iterator pos, size_type count, const T& value);
			 * template<class InputIt>
			 * void						insert(iterator pos, InputIt first, InputIt last);
			 * iterator					erase(iterator pos);
			 * iterator					erase(iterator first, iterator last);
			 * void						push_front(const T& va
			 * void						resize(size_type count, T value = T());
			 * void						swap(List& other);
			 * void 					clear();
			 * 
			 * ================================================= PRIVATE =================================================
			 * 
			 * pointer			_begin; 
			 * Alloc			_alloc;
			 * size_type 		_size;
			 * size_type 		_capacity;
			 * 
			 **/

		public:
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	Iterator<T>									iterator;
			typedef	const Iterator<T>							const_iterator;
			typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	reverse_iterator<iterator>					reverse_iterator;	
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

			explicit vector(const allocator_type& alloc = allocator_type())  :
			_alloc(alloc), _size(0), _capacity(0) { this->_begin = this->_alloc.allocate(0); }
			
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _size(n), _capacity(n)
			{
				this->_begin = this->_alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&this->_begin[i], val);		
			}
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0) :
			_alloc(alloc)
			{
				for (InputIterator it = first; it < last; it++)
					++this->_size;

				this->_capacity = this->_size;
				this->_begin = this->_alloc.allocate(this->_size);
				
				int i = 0;
				for (InputIterator it = first; it < last; it++, i++)
					this->_alloc.construct(&this->_begin[i], *it);
			}
			
			vector(const vector& x)
			{
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_begin = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_begin[i], x._begin[i]);
			}
			
			~vector() {}

			vector& operator= (const vector& x)
			{		
				if (this == &x)
					return *this;

				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_begin[i]);
				this->_alloc.deallocate(this->_begin, this->_capaity);
				
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_begin = this->_alloc.allocate(this->_capacity);

				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_begin[i], x._begin[i]);

				return *this;
			}

			// Iterators
			
			iterator begin() { return iterator(this->_begin); }
			const_iterator begin() const { return const_iterator(this->_begin); }

			iterator end() { return iterator(this->_begin) + this->_size; }
			const_iterator end() const { return const_iterator(this->_begin + this->_size); }

			reverse_iterator rbegin() { return reverse_iterator(iterator(this->_begin + this->_size)); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(iterator(this->_begin + this->_size)); }

			reverse_iterator rend() { return reverse_iterator(iterator(this->_begin)); }
			const_reverse_iterator rend() const { return const_reverse_iterator(iterator(this->_begin)); } 

			// Capacity

			size_type	size() const { return this->_size; }

			size_type	max_size() const
			{
				if (sizeof(value_type) == 1)
					return (static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1);
				return (static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1);
			} 
			
			void		resize(size_type n, value_type val = value_type())
			{
				pointer tmp = this->_begin;

				this->_begin = this->_alloc.allocate(n);

				for (size_type i = 0; i < this->_size && i < n; i++)
				{
					this->_alloc.construct(&this->_begin[i], tmp[i]);
					this->_alloc.destroy(&tmp[i]);
				}
				for (size_type i = this->_size; i < n; i++)
					this->_alloc.construct(&this->_begin[i], val);
				for (size_type i = n; i < this->_size; i++)
					this->_alloc.destroy(&tmp[i]);

				this->_alloc.deallocate(tmp, this->_capacity);
				this->_size = n;
				this->_capacity = n;
			}
			
			size_type	capacity() const	{ return this->_capacity; }
			
			bool		empty() const		{ return (this->_size == 0); }
			
			void			reserve(size_type n)
			{
				if (n <= this->_capacity)
					return ;

				pointer tmp = this->_begin;
 
				this->_begin = this->_alloc.allocate(n);

				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&this->_begin[i], tmp[i]);
					this->_alloc.destroy(&tmp[i]);
				}

				this->_alloc.deallocate(tmp, this->_capacity);
				this->_capacity = n;
			}

			// Element access
			
			reference		operator[] (size_type n) { return this->_begin[n]; }
			const_reference	operator[] (size_type n) const { return this->_begin[n]; }
			
			reference		at (size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_begin[n];
			}

			const_reference	at (size_type n) const
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_begin[n];
			}

			reference		front() { return this->_begin[0]; }
			const_reference	front() const { return this->_begin[0]; }
			reference		back() { return this->_begin[this->_size - 1]; }
			const_reference	back() const { return this->_begin[this->size - 1]; }

			// Modifiers
			
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				size_type size = last - first;

				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_begin[i]);
				if (this->_capacity < size)
				{
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_capacity = size;
					this->_begin = this->_alloc.allocate(size);
				}
				this->_size = size;

				size_type i = 0;
				for (InputIterator it = first; it < last; it++, i++)
					this->_alloc.construct(&this->_begin[i], *it);
			}

			void assign (size_type n, const value_type& val)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_begin[i]);
				if (this->_capacity < n)
				{
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_capacity = n;
					this->_begin = this->_alloc.allocate(n);
				}
				this->_size = n;

				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&this->_begin[i], val);
			}

		private:
			pointer			_begin;
			Alloc			_alloc;
			size_type 		_size;
			size_type 		_capacity;
	};
}

#endif
