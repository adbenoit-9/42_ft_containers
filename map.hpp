/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/07 14:03:56 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "includes/Tree.hpp"

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
			typedef pair<const key_type, mapped_type>           value_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;
			typedef Node<key_type, mapped_type, key_compare,
					allocator_type>								tree;
			typedef	typename Tree::const_iterator				const_iterator;
			typedef	typename Tree::iterator						iterator;
			typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	reverse_iterator<iterator>					reverse_iterator;	
			
			// typedef	map_iterator<bidirectional_iterator_tag, value_type,
			// ptrdiff_t, const value_type*, const value_type&>				const_iterator;
			// typedef	map_iterator<bidirectional_iterator_tag, value_type>	iterator;
			// typedef	reverse_iterator<const_iterator>					const_reverse_iterator;
			// typedef	reverse_iterator<iterator>							reverse_iterator;	
			
			explicit map(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
				_tree(comp, alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_tree(comp, alloc)
			{
				for (InputIterator it = first; first < last; it++)
					insert(*it);
			}
			
			map(const map& x) : _tree(x._tree) {}

			~map() {}

			map& operator=(const map& x)
			{		
				if(this == &x)
					return *this;
				*tmp = *x.tree;
				return *this;
			}

			//					~ Iterators ~
			
 			iterator				begin() { return iterator(this->_tree->getParent()); }
 			const_iterator			begin() const { return const_iterator(this->_tree); }

 			iterator				end() { return iterator(this->_tree) + this->_size; }
 			const_iterator			end() const { return const_iterator(this->_tree + this->_size); }

 			// reverse_iterator		rbegin() { return reverse_iterator(iterator(this->_begin + this->_size - 1)); }
 			// const_reverse_iterator	rbegin() const { return const_reverse_iterator(iterator(this->_begin + this->_size - 1)); }

 			// reverse_iterator 		rend() { return reverse_iterator(iterator(this->_begin - 1)); }
 			// const_reverse_iterator	rend() const { return const_reverse_iterator(iterator(this->_begin - 1)); } 
			 

			//					~ Capacity ~

			size_type				size() const { return this->_tree.size(); }

			size_type				max_size() const { return this->_tree.max_size(); }
			
			bool					empty() const { return this->_tree.size() == 0; }

			//					~ Element access ~
			
			mapped_type& 			operator[](const key_type& k) { return this->_tree[k]; }

			//					~ Modifiers ~

			pair<iterator,bool>		insert(const value_type& val) { return this->_tree.insert(val); }
			
			iterator				insert(iterator position, const value_type& val) { return this->_tree.insert(position, val); }
				// utilise la position uniquement si c'est coherent
			template <class InputIterator>
  			void					insert(InputIterator first, InputIterator last)
			{
				for (iterator it = this->_tree.begin(); it < this->_tree.end(); it++)
					this->insert(*it);
			}

			size_type				erase(const key_type& k) { return this->_tree.erase(k); }
			
			void					erase(iterator position) { this->erase(*position); }

			void					erase(iterator first, iterator last)
			{
				for (iterator it = this->_tree.begin(); it < this->_tree.end(); it++)
					this->erase(*it);
			}

			void					swap(map& x)
			{
				this->_tree.swap(x._tree);
			}

			void					clear()
			{
				this->_tree.clear();
				// this->_alloc.deallocate(this->_tree, this->_size);
			}
			
			//					~ Observers ~
			
			key_compare				key_comp() const { return this->_tree.key_comp(); }
			value_compare			value_comp() const { return value_compare(this->_tree.value_comp()); }

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

		private:
			tree	_tree;
			std::allocator<tree> _alloc;
	};
}

#endif
