/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/21 19:10:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Tree.hpp"
# include "iterators.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<ft::pair<const Key,T> >  >
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
			 * tree			_tree; 
			 * 
			 **/

		public:
			typedef Key											key_type;
			typedef T				    						mapped_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef ft::pair<const Key,T>							value_type;
			typedef Tree< const value_type, Compare, Alloc>		const_tree;
			typedef Tree< value_type, Compare, Alloc>			tree;
			typedef	typename tree::reference					reference;
			typedef	typename tree::const_reference				const_reference;
			typedef	typename tree::pointer						pointer;
			typedef	typename tree::const_pointer				const_pointer;
			typedef	typename tree::difference_type				difference_type;
			typedef	typename tree::size_type					size_type;
			typedef typename tree::value_compare				value_compare;
			
			typedef	map_iterator<bidirectional_iterator_tag,
			const_tree, tree>										const_iterator;
			typedef	map_iterator<bidirectional_iterator_tag, tree>	iterator;
			typedef	reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef	reverse_iterator<iterator>						reverse_iterator;	
			
			explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {
				this->insert(first, last);
			}
			
			map(const map& x) { *this = x; }

			~map() {}

			map& operator=(const map& x)
			{		
				if(this == &x)
					return *this;
				this->_tree = x._tree;
				return *this;
			}

			//					~ Iterators ~
			
 			iterator				begin() {
				typename tree::Node *b;
				b = this->_tree.root ? this->_tree.root->min() : this->_tree.end;
				return iterator(b, this->_tree.end);
			}
 			const_iterator			begin() const {
				typename tree::Node *b;
				b = this->_tree.root ? this->_tree.root->min() : this->_tree.end;
				return const_iterator(b, this->_tree.end);
			}
				
 			iterator				end() {
				return iterator(this->_tree.end, this->_tree.end);
			}
 			const_iterator			end() const {
				return const_iterator(this->_tree.end, this->_tree.end);
			}

			reverse_iterator		rbegin() { return reverse_iterator(this->end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->end()); }

			reverse_iterator		rend() { return reverse_iterator(iterator(this->begin())); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); } 
			 

			//					~ Capacity ~

			size_type				size() const { return this->_tree.size(this->_tree.root); }

			size_type				max_size() const { return this->_tree.max_size(); }
			
			bool					empty() const { return this->size() == 0; }

			//					~ Element access ~
			
			mapped_type& 			operator[](const key_type& k) { return this->_tree[k]; }

			//					~ Modifiers ~

			pair<iterator,bool>		insert(const value_type& val) {
				size_type n = this->size();
				this->_tree.root = this->_tree.insertNode(this->_tree.root, val);
				pair<iterator,bool> ret;
				ret.second = (n != this->size());
				ret.first = this->find(val.first);
				this->_tree.setEnd();
				return ret;
			}
			
			// utilise la position uniquement si c'est coherent
			iterator				insert(iterator position, const value_type& val) {
				(void)position;
				this->insert(val);
				return find(val.first);
			}
			
			template <class InputIterator>
  			void					insert(InputIterator first, InputIterator last) {
				for (InputIterator it = first; it != last; it++)
					this->_tree.root = this->_tree.insertNode(this->_tree.root, *it);
				this->_tree.setEnd();
				
			}

			size_type				erase(const key_type& k) {
				size_type n = this->size();
				this->_tree.root = this->_tree.deleteNode(this->_tree.root, k);
				this->_tree.setEnd();
				return (n != this->size());
			}
			
			void					erase(iterator position) { this->erase((*position).first); }

			void					erase(iterator first, iterator last) {
				iterator tmp;
				while (first != last)
				{
					tmp = first;
					++first;
					this->erase(tmp);
				}
			}

			void					swap(map& x){
				typename tree::Node* tmp = x._tree.root;
				x._tree.root = this->_tree.root;
				this->_tree.root = tmp;
			}

			void					clear() {
				this->_tree.clear();
			}
			
			//					~ Observers ~
			
			key_compare				key_comp() const { return this->_tree.key_comp; }
			
			value_compare			value_comp() const { return this->_tree.value_comp(); }

			//					~ Operations ~
    			
			iterator				find(const key_type& k) {
				typename tree::Node* node = this->_tree.findNode(k);
				if (node)
					return iterator(node, this->_tree.end);
				return this->end();
			}

			const_iterator			find(const key_type& k) const {
				typename tree::Node* node = this->_tree.findNode(k);
				if (node)
					return const_iterator(node, this->_tree.end);
				return this->end();
			}

			size_type				count(const key_type& k) const {
				return (this->_tree.findNode(k)) ? 1 : 0;
			}

			iterator				lower_bound(const key_type& k) {
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp(it->first, k))
						return it;
				return this->end();
			}

			const_iterator			lower_bound(const key_type& k) const {
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp(it->first, k))
						return it;
				return this->end();
			}

			iterator 				upper_bound(const key_type& k) {
				for (iterator it = this->begin(); it != this->end(); it++)
					if (this->_tree.key_comp(k, it->first))
						return it;
				return this->end();
			}

			const_iterator			upper_bound(const key_type& k) const {
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (this->_tree.key_comp(k, it->first))
						return it;
				return this->end();
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp(k, it->first) && !this->_tree.key_comp(it->first, k))
						return pair<const_iterator, const_iterator>(it++, it);
				return pair<const_iterator, const_iterator>(this->lower_bound(k), this->lower_bound(k));
			}

			pair<iterator,iterator>				equal_range(const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_tree.key_comp(k, it->first) && !this->_tree.key_comp(it->first, k))
						return pair<iterator, iterator>(it++, it);
				return pair<iterator, iterator>(this->lower_bound(k), this->lower_bound(k));
			}
			
		private:
			tree					_tree;
	};
}

#endif
