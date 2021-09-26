/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.map.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 00:45:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_MAP_HPP
# define MODIFIERS_MAP_HPP

# include "print.map.hpp"

template<class Key, class Value>
void	ft_modifiers(ft::map<Key, Value> &map)
{
				/* INSERT */
	heading("insert");
	ft::map<Key, Value> tmp;
	std::cout << "0#";
	for (int i = 6; i < 10; i++)
	{
		typename ft::map<Key, Value>::value_type val(i, i);
		std::cout << " " << tmp.insert(val).second;
	}
	std::cout << std::endl;
	print(tmp, 1); // 1#
	map.insert(tmp.begin(), tmp.end());
	print(map, 2); //2#
	ft::map<Key, Value> tmp1;
	map.insert(tmp1.begin(), tmp1.end());
	print(map, 3); //3#
	{
		typename ft::map<Key, Value>::value_type val(-15, 42);
		std::cout << "4#  " << tmp.insert(val).first->first << std::endl; // 4#
	}
	map.insert(tmp.begin(), tmp.begin());
	print(map, 5); //5#
	map.insert(tmp.begin(), ++tmp.begin());
	print(map, 6); //6#
	{
		typename ft::map<Key, Value>::value_type val(-42, 42);
		tmp.insert(val);
	}
	std::cout << "7#  " << map.insert(map.begin(), *tmp.begin())->first << std::endl; // 7#
	print(map, 8); //8#
	std::cout << "9#  " << map.insert(tmp.begin(), *tmp.begin())->first << std::endl; // 9#
	print(map, 10); //10#
	{
		typename ft::map<Key, Value>::value_type val(-52, 42);
		tmp.insert(val);
	}
	std::cout << "11#  " << map.insert(map.begin(), *tmp.begin())->first << std::endl; // 11#
	print(map, 12); //12#

				/* ERASE */
	heading("erase");
	map.erase(map.begin());
	print(map, 0); // 0#
	map.erase(map.begin()++);
	print(map, 1); // 1#
	std::cout << "2#  " << map.erase(3) << std::endl;
	print(map, 3); // 3#
	std::cout << "4#  " << map.erase(404) << std::endl;
	print(map, 5); // 5#
	map.erase(map.begin(), map.end());
	print(map, 6); // 6#
	map.erase(map.begin(), map.begin());
	print(map, 7); // 7#
	
				/* SWAP */
	heading("swap");
	for (int i = 0; i < 5; i++)
	{
		typename ft::map<Key, Value>::value_type val(i, i);
		map.insert(val);
	}
	ft::map<Key, Value> swap;
	map.swap(swap);
	print(map, 0); // 0#
	print(swap, 1); // 1#
	map.insert(swap.begin()++, swap.end());
	map.swap(swap);
	print(map, 2); // 2#
	print(swap, 3); // 3#
	
				/* CLEAR */
	heading("clear");
	swap.clear();
	print(swap, 0); // 0#
	tmp.clear();
	print(tmp, 1); // 1#
	ft::map<Key, Value> empty;
	empty.clear();
	print(empty, 2); // 2#
}

#endif
