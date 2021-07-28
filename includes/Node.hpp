/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/28 17:25:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <memory>
# include <functional>
# include "includes/pair.hpp"
# include "includes/iterators.hpp"
# include "includes/reverse_iterator.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<pair<const Key,T> >  >
    class Tree
    {

        public:
        	typedef Key 												key_type;
			typedef T 										    		mapped_type;
			typedef pair<const key_type, mapped_type>           		value_type;
			typedef	Compare												key_compare;
			typedef	Alloc												allocator_type;
			typedef	typename allocator_type::reference					reference;
			typedef	typename allocator_type::const_reference			const_reference;
			typedef	typename allocator_type::pointer					pointer;
			typedef	typename allocator_type::const_pointer				const_pointer;
			typedef	ptrdiff_t											difference_type;
			typedef	size_t												size_type;
			typedef	map_iterator<bidirectional_iterator_tag,
					t_tree, ptrdiff_t, const T*, const T&>				const_iterator;
			typedef	map_iterator<bidirectional_iterator_tag, t_tree>	iterator;
			typedef	reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	reverse_iterator<iterator>							reverse_iterator;	
            typedef                                                     struct s_node
            {
                value_type		value;
                struct s_node *left;
                struct s_node *right;
                struct s_node *parent;
            }                                                           t_node;
            
            class value_compare
			{
					friend class Tree;
				protected:
					Compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};
            
            explicit Tree(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
                _key_compare(comp), _alloc(alloc), _size(0) { _parent = 0; _left = 0, _right = 0; }
            
            Tree(value_type val, key_compare c, Tree *p);
            ~Tree()
            {
                for (iterator it = )
            }

            mapped_type& 			operator[](const key_type& k)
			{
				t_tree *tmp;

				tmp = this->_tree;
				while (tmp)
				{
					if (k == tmp->value.first)
						return tmp->value.second;
					else if (this->_key_comp(k, tmp->value.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
			}

			//					~ Modifiers ~

			pair<iterator,bool>		insert(const value_type& val);
			{
				if (this->count(val.first))
					return (this->equal_range(val.first));
				t_tree	*tmp = this->_tree;
				t_tree	*parent;
				while (tmp)
				{
					parent = tmp;
					if (this->_key_comp(val.first, tmp->value.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				t_tree node(val, parent);
				this->_alloc.construt(&node, tmp);

				return ret;
			}
			
			iterator				insert(iterator position, const value_type& val)
			{
				// utilise la position uniquement si c'est coherent
			}
			// template <class InputIterator>
  			// void						insert(InputIterator first, InputIterator last);
			
			// void						erase(iterator position);
			// size_type					erase(const key_type& k);
			// void						erase(iterator first, iterator last);

			void					swap(map& x)
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
			
			//					~ Observers ~
			
			key_compare				key_comp() const { return this->_comp; }
			value_compare			value_comp() const { return value_compare(this->_comp); }

			//					~ Operations ~
    			
			iterator							find(const key_type& k)
			{
				if (this->count())
					for (iterator it = this->begin(); it != this->end(); it++)
						if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
							return it;
				return this->end();
			}

			const_iterator						find(const key_type& k) const
			{
				if (this->count())
					for (iterator it = this->begin(); it != this->end(); it++)
						if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
							return it;
				return this->end();
			}

			size_type							count(const key_type& k) const;
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
						return 1;
				return 0;
			}

			iterator							lower_bound(const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_key_comp(*it->value.first, k))
						return it;
				return this->end();
			}

			const_iterator						lower_bound(const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_key_comp(*it->value.first, k))
						return it;
				return this->end();
			}

			iterator 							upper_bound(const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (this->_key_comp(k, *it->value.first))
						return it;
				return this->end();
			}

			const_iterator						upper_bound(const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (this->_key_comp(k, *it->value.first))
						return it;
				return this->end();
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
						return pair<const_iterator, const_iterator>(it, it + 1);
				return pair<const_iterator, const_iterator>(this->lower_bound(), this->lower_bound()));
			}

			pair<iterator,iterator>				equal_range(const key_type& k);
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!this->_key_comp(k, *it->value.first) && !this->_key_comp(*it->value.first, k))
						return pair<iterator, iterator>(it, it + 1);
				return pair<iterator, iterator>(this->lower_bound(), this->lower_bound()));
			}

        private:
            key_compare		_key_comp;
            allocator_type  _alloc;
			size_type 		_size;
            t_node			*_root;
            Tree();
    };
}

#endif
