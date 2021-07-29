/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:14:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/29 15:01:47 by adbenoit         ###   ########.fr       */
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
			typedef Tree<key_type, mapped_type, key_compare,
					allocator_type>								tree;
			typedef	typename Tree::const_iterator				const_iterator;
			typedef	typename Tree::iterator						iterator;
			typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	reverse_iterator<iterator>					reverse_iterator;	
			
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
			
			iterator				begin() { return this->_tree.begin(); }
			const_iterator			begin() const { return this->_tree.begin(); }

			iterator				end() { return this->_tree.end();  }
			const_iterator			end() const { return this->_tree.end();  }

			reverse_iterator		rbegin() { return this->_tree.rbegin();  }
			const_reverse_iterator	rbegin() const { return this->_tree.rbegin();  }

			reverse_iterator 		rend() { return this->_tree.rend();  }
			const_reverse_iterator	rend() const { return this->_tree.rend();  } 

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
				map tmp = *this;
				
				*this = x;
				x = tmp;
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
    			
			iterator							find(const key_type& k) { return this->_tree.find(k); }
			const_iterator						find(const key_type& k) const { return this->_tree.find(k); }

			size_type							count(const key_type& k) const { return this->_tree.count(k); }
			
			iterator							lower_bound(const key_type& k) { return this->_tree.lower_bound(k); }
			const_iterator						lower_bound(const key_type& k) const { return this->_tree.lower_bound(k); }
			
			iterator 							upper_bound(const key_type& k) { return this->_tree.upper_bound(k); }
			const_iterator						upper_bound(const key_type& k) const { return this->_tree.upper_bound(k); }

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const { return this->_tree.equal_range(k); }
			pair<iterator,iterator>				equal_range(const key_type& k) { return this->_tree.equal_range(k); }

		private:
			tree	_tree;
			std::allocator<Tree> _alloc;
	};
}

#endif
