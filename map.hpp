/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/15 17:51:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "includes/Tree.hpp"
# include "includes/iterators.hpp"

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
			typedef Tree<Key, T, Compare, Alloc>					tree;
			typedef typename tree::key_type							key_type;
			typedef typename tree::mapped_type				    	mapped_type;
			typedef typename tree::value_type						value_type;
			typedef	typename tree::key_compare						key_compare;
			typedef	typename tree::allocator_type					allocator_type;
			typedef	typename tree::reference						reference;
			typedef	typename tree::const_reference					const_reference;
			typedef	typename tree::pointer							pointer;
			typedef	typename tree::const_pointer					const_pointer;
			typedef	typename tree::difference_type					difference_type;
			typedef	typename tree::size_type						size_type;
			typedef typename tree::value_compare					value_compare;
			
			typedef	map_iterator<bidirectional_iterator_tag, tree>	const_iterator;
			typedef	map_iterator<bidirectional_iterator_tag, tree>	iterator;
			typedef	reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef	reverse_iterator<iterator>						reverse_iterator;	
			
			explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _size(0) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _size(0)
			{
				for (InputIterator it = first; first < last; it++)
					insert(*it);
			}
			
			map(const map& x) : _tree(x._tree), _size(x._size) {}

			~map() {}

			map& operator=(const map& x)
			{		
				if(this == &x)
					return *this;
				this->_tree = *x._tree;
				this->_size = *x._size;
				return *this;
			}

			//					~ Iterators ~
			
 			iterator				begin() { return iterator(this->_tree.getParent()); }
 			const_iterator			begin() const { return const_iterator(this->_tree); }

 			iterator				end() { return iterator(this->_tree) + this->_size; }
 			const_iterator			end() const { return const_iterator(this->_tree + this->_size); }

 			// reverse_iterator		rbegin() { return reverse_iterator(iterator(this->_begin + this->_size - 1)); }
 			// const_reverse_iterator	rbegin() const { return const_reverse_iterator(iterator(this->_begin + this->_size - 1)); }

 			// reverse_iterator 		rend() { return reverse_iterator(iterator(this->_begin - 1)); }
 			// const_reverse_iterator	rend() const { return const_reverse_iterator(iterator(this->_begin - 1)); } 
			 

			//					~ Capacity ~

			size_type				size() const { return this->_size; }

			size_type				max_size() const { return this->_tree.max_size(); }
			
			bool					empty() const { return this->_size == 0; }

			//					~ Element access ~
			
			mapped_type& 			operator[](const key_type& k) { return this->_tree[k]; }

			//					~ Modifiers ~

			pair<iterator,bool>		insert(const value_type& val) {
				this->_tree.root = this->_tree.insertNode(this->_tree.root, val);
				pair<iterator,bool> ret;
				ret.second = (this->_size != this->_tree.size(this->_tree.root));
				this->_size += ret.second;
				iterator it = this->begin();
				while ((*it).first != val.first)
					it++;
				// ret.first = it;
				return ret;
			}
			
			// utilise la position uniquement si c'est coherent
			iterator				insert(iterator position, const value_type& val) {
				return this->_tree.insert(position, val); }
			template <class InputIterator>
  			void					insert(InputIterator first, InputIterator last)
			{
				for (iterator it = first; it != last; it++)
					this->_tree.root = this->_tree.insertNode(this->_tree.root, *it);
			}

			size_type				erase(const key_type& k) {
				this->tree.root = this->_tree.deleteNode(this->_tree.root, k);
				this->_size = this->tree.size(this->_tree.root);
				return this->_size;
			}
			
			void					erase(iterator position) { this->erase(*position.first); }

			void					erase(iterator first, iterator last)
			{
				for (iterator it = first; it != last; it++)
					this->erase(it);
			}

			// void					swap(map& x)
			// {
			// 	this->_tree.swap(x._tree);
			// }

			void					clear() { this->_tree.clear(); this->_size = 0; }
			
			//					~ Observers ~
			
			key_compare				key_comp() const { return this->_tree.key_comp(); }
			
			value_compare			value_comp() const {
				return this->_tree.value_compare(this->_tree.value_comp()); }

			//					~ Operations ~
    			
						// iterator							find(const key_type& k)
			// {
			// 	if (this->count())
			// 		for (iterator it = this->begin(); it != this->end(); it++)
			// 			if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
			// 				return it;
			// 	return this->end();
			// }

			// const_iterator						find(const key_type& k) const
			// {
			// 	if (this->count())
			// 		for (iterator it = this->begin(); it != this->end(); it++)
			// 			if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
			// 				return it;
			// 	return this->end();
			// }

			// size_type							count(const key_type& k) const;
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
			// 			return 1;
			// 	return 0;
			// }

			// iterator							lower_bound(const key_type& k)
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (!this->_key_comp(*it->value.first, k))
			// 			return it;
			// 	return this->end();
			// }

			// const_iterator						lower_bound(const key_type& k) const
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (!this->_key_comp(*it->value.first, k))
			// 			return it;
			// 	return this->end();
			// }

			// iterator 							upper_bound(const key_type& k)
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (this->_key_comp(k, *it->value.first))
			// 			return it;
			// 	return this->end();
			// }

			// const_iterator						upper_bound(const key_type& k) const
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (this->_key_comp(k, *it->value.first))
			// 			return it;
			// 	return this->end();
			// }

			// pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
			// 			return pair<const_iterator, const_iterator>(it, it + 1);
			// 	return pair<const_iterator, const_iterator>(this->lower_bound(), this->lower_bound()));
			// }

			// pair<iterator,iterator>				equal_range(const key_type& k);
			// {
			// 	for (iterator it = this->begin(); it != this->end(); it++)
			// 		if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
			// 			return pair<iterator, iterator>(it, it + 1);
			// 	return pair<iterator, iterator>(this->lower_bound(), this->lower_bound()));
			// }

			friend std::ostream&	operator<<(std::ostream& os, const map& map)
			{
				os << map._tree;
				return os;
			}
			
		private:
			tree		_tree;
			size_type	_size;
	};
		
}

#endif
