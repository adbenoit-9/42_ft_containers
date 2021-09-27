/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.map.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 13:47:13 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_MAP_HPP
# define ITERATORS_MAP_HPP

# include "print.map.hpp"

template<class Key, class Value>
void	ft_iterators(ft::map<Key, Value>& map)
{
	ft::map<Key, Value> tmp;
					/* ITERATOR */
	heading("iterator");
	print(tmp, 0); // 0#
	for (typename ft::map<Key, Value>::iterator it = map.begin() ; it != map.end(); ++it)
		tmp.insert(*it);
	print(tmp, 1); // 1#
	typename ft::map<Key, Value>::iterator it = map.begin();
	std::cout << "2#  " << it->first << std::endl; // 2#
	++it;
	std::cout << "3#  " << it->first << std::endl; // 3#
	--it;
	std::cout << "4#  " << it->first << std::endl; // 4#

	tmp.clear();
	
			/* REVERSE ITERATOR */
	heading("reverse_iterator");
	print(tmp, 0); // 0#
	for (typename ft::map<Key, Value>::reverse_iterator rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
		tmp.insert(*rit.base());
	print(tmp, 1); // 1#
	typename ft::map<Key, Value>::reverse_iterator rit = map.rbegin();
	std::cout << "2#  " << rit->first << std::endl; // 2#
	++rit;
	std::cout << "3#  " << rit->first << std::endl; // 3#
	--rit;
	std::cout << "4#  " << rit->first << std::endl; // 4#
}


#endif
