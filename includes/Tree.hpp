/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:43:23 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/30 16:23:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include "pair.hpp"
// # include "iterators.hpp"
// # include "reverse_iterator.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<ft::pair<const Key,T> >  >
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
            typedef                                                     struct s_node
            {
                value_type		value;
                struct s_node	*left;
                struct s_node	*right;
                struct s_node	*parent;
            }                                                           t_node;
			// typedef	map_iterator<bidirectional_iterator_tag,
			// 		t_node, ptrdiff_t, const T*, const T&>				const_iterator;
			// typedef	map_iterator<bidirectional_iterator_tag, t_node>	iterator;
			// typedef	reverse_iterator<const_iterator>					const_reverse_iterator;
			// typedef	reverse_iterator<iterator>							reverse_iterator;	
            
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
                _key_comp(comp), _alloc(alloc), _size(0) { this->_root = nullptr; }
            
			Tree(const Tree& x) : _key_comp(x._key_comp), _alloc(x._alloc), _size(x._size)
				{ this->_root = nullptr; }
			
            ~Tree()
            {
                while (this->_root->parent)
					this->_root = this->_root->parent;
				this->destroy_tree(this->_root);
            }


			Tree& operator=(const Tree& x)
			{		
				if(this == &x)
					return *this;
				return *this;
			}

			//					~ Iterators ~

 			// iterator				begin() { return iterator(this->_root); }
 			// const_iterator			begin() const { return const_iterator(this->_root); }

 			// iterator				end() { return iterator(this->_begin) + this->_size; }
 			// const_iterator			end() const { return const_iterator(this->_begin + this->_size); }

 			// reverse_iterator		rbegin() { return reverse_iterator(iterator(this->_begin + this->_size - 1)); }
 			// const_reverse_iterator	rbegin() const { return const_reverse_iterator(iterator(this->_begin + this->_size - 1)); }

 			// reverse_iterator 		rend() { return reverse_iterator(iterator(this->_begin - 1)); }
 			// const_reverse_iterator	rend() const { return const_reverse_iterator(iterator(this->_begin - 1)); } 

 			//					~ Capacity ~

 			size_type				size() const { return this->_size; }

 			size_type				max_size() const { return this->_alloc.max_size(); }

 			bool					empty() const { return this->_size == 0; }

 			//					~ Element access ~

            mapped_type& 			operator[](const key_type& k)
			{
				t_node *tmp;

				tmp = this->_root;
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

			// pair<iterator,bool>		insert(const value_type& val)
			// {
			// 	if (this->count(val.first))
			// 	{
			// 		pair<iterator,bool> ret;
			// 		ret.first = find(val.first);
			// 		ret.second = false;
			// 		return ret;
			// 	}
			// 	t_node	*tmp = this->_root;
			// 	t_node	*parent;
			// 	while (tmp)
			// 	{
			// 		parent = tmp;
			// 		if (this->_key_comp(val.first, tmp->value.first))
			// 			tmp = tmp->left;
			// 		else
			// 			tmp = tmp->right;
			// 	}
			// 	t_node *node;

				// this->_allocNode.allocate(node, 1);
				// this->_alloc.construt(&val, node->value);
				// this->_allocNode.construct(&node, tmp);
				// node->left = 0;
				// node->right = 0;
				// node->parent = parent;
				
				// tmp = node;

			// 	tmp = balance_tree(parent->parent);
				
			// 	pair<iterator,bool> ret;
			// 	ret.first = find(val.first);
			// 	ret.second = true;
			// 	return ret;
			// }

			// iterator				insert(iterator position, const value_type& val)
			// {
			// 	// utilise la position uniquement si c'est coherent
			// }

			// size_type				erase(const key_type& k)
			// {
				
			// }

			void					swap(Tree& x)
			{
				Tree tmp = *this;
				
				*this = x;
				x = tmp;
			}

			void					clear()
			{
                while (this->_root->parent)
					this->_root = this->_root->parent;
				this->destroy_tree(this->_root);
				this->_size = 0;
			}

			void	destroy_tree(t_node *node)
			{
				if (node)
				{
					destroy_tree(node->left);
					destroy_tree(node->right);
					this->_alloc.destroy(&node->value);
				}
				this->_allocNode.destroy(node);
				this->_allocNode.deallocate(node, 1);
			}
			
			t_node*	rotate_left(t_node* n1, t_node* n2)
			{
				t_node* tmp = n2->left;
				if (tmp)
					tmp->parent = n1;
				
				n2->parent = n1->parent;
				n2->left = n1;
				
				n1->parent = n2;
				n1->right = tmp;
				
				return n2;
			}
			
			t_node*	rotate_rightLeft(t_node* n1, t_node* n2)
			{
				t_node* n3 = n2->left;
				n3->parent = n1->parent;
				
				n2->parent = n3;
				n2->left = n3->right;
				if (n2->left)
					n2->left->parent = n2;
				
				n1->parent = n3;
				n1->right = n3->left;
				if (n1->right)
					n1->right->parent = n1;

				n3->left = n1;
				n3->right = n2;
				
				return n3;
			}

			int		height(t_node* node)
			{
				int	h = 0;

				if (node)
				{
					height(node->right);
					height(node->left);
					++h;
				}
				return h;
			}
			
			t_node*	balance_tree(t_node *node)
			{
				// calcul balance factor
				int bf = height(node->right) - height(node->left);
				if (bf >= -1 && bf <= 1)
					return ;
				else if (bf > 1)
					return rotate_left(node, node->right);
				return rotate_rightLeft(node, node->right);
			}

			//					~ Observers ~
			
			key_compare				key_comp() const { return this->_comp; }
			value_compare			value_comp() const { return value_compare(this->_comp); }

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
            key_compare		_key_comp;
            allocator_type  _alloc;
            std::allocator<t_node>  _allocNode;
			size_type 		_size;
            t_node			*_root;
    };
}

#endif
