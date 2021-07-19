/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/20 01:09:13 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
#include <functional>
# include "pair.hpp"
# include "iter/iterator.hpp"
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
			typedef pair<const Key, T>                      	value_type;
			typedef	Compare										key_compare;
			typedef 											value_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	map_iterator<bidirectional_iterator_tag, T,
					ptrdiff_t, const T*, const T&>				const_iterator;
			typedef	map_iterator<bidirectional_iterator_tag, T>	iterator;
			typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	reverse_iterator<iterator>					reverse_iterator;	
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;
			typedef 											struct	s_node
			{
				value_type		value;
				struct s_node	*left;
				struct s_node	*right;
			} 													t_node;
			typedef t_node										t_tree;

			explicit map(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
				_tree(nullptr), _comp(comp), _alloc(alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_tree(nullptr), _comp(comp), _alloc(alloc), _size(last - first)
			{
				this->alloc(this->_begin, this->size);
				for (InputIterator it = first; first < last; it++)
					insert(*it);
			}
			
			map(const map& x) : _tree(nullptr), _comp(x._comp), _alloc(x._alloc), _size(x._size)
			{
				this->alloc.allocate(this->_begin, this->size);
				for (InputIterator it = x.begin(); first < last; it++)
					insert(*it);
			}
			
			~map()
			{
				for (iterator it = this->begin(); first < last; it++)
					this->alloc.destroy(&*it);
				this->alloc.deallocate(this->_begin, this->size);
			}

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

			size_type	max_size() const { return this->alloc.max_size(); }
			
			bool						empty() const		{ return(this->_size == 0); }

			// Element access
			
			mapped_type& 				operator[](const key_type& k)
			{
				t_tree *tmp;

				tmp = this->_tree;
				while (tmp)
				{
					if (k == tmp->value.first)
						return tmp->value.second;
					else if (Compare(k, tmp->value))
						tmp = tmp->left;
					else if (!Compare(k, tmp->value))
						tmp = tmp->right;
				}
			}

			// Modifiers

			pair<iterator,bool>			insert(const value_type& val);
			{
				t_tree				*tmp;

				tmp = this->_tree;				
				while (this->_tree)
				{
					if (k == this->_tree->value.first)
						this->_tree->value = val; // ne pas inserer si cest egal
					else if (Compare(k, this->_tree->value))
						this->_tree = this->_tree->left;
					else if (!Compare(k, this->_tree->value))
						this->_tree = this->_tree->right;
				}
				this->_alloc.construct(this->_tree->value, &val);
				pair<iterator,bool> ret = this->_tree->value;
				this->_tree = tmp;
				
				return ret;
			}
			
			iterator					insert(iterator position, const value_type& val)
			{
				// utilise la position uniquement si c'est coherent
			}
			// template <class InputIterator>
  			// void						insert(InputIterator first, InputIterator last);
			
			// void						erase(iterator position);
			// size_type					erase(const key_type& k);
			// void						erase(iterator first, iterator last);

			void						swap(map& x)
			{
				map tmp = *this;
				
				*this = x;
				x = tmp;
			}

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
			t_tree*			_tree;
			key_compare		_comp;
			allocator_type	_alloc;
			size_type 		_size;
	};
}

#endif
