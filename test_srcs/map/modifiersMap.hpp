/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiersMap.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:45 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERSMAP_HPP
# define MODIFIERSMAP_HPP

# include "printMap.hpp"

template<class T>
void	mapModifiers(T &map)
{
				/* INSERT */
	heading("insert");
	T tmp;
	std::cout << "0#";
	for (int i = 6; i < 10; i++)
	{
		typename T::value_type val(i, i);
		std::cout << " " << tmp.insert(val).second;
	}
	std::cout << std::endl;
	printMap(tmp, 1); // 1#
	map.insert(tmp.begin(), tmp.end());
	printMap(map, 2); //2#
	T tmp1;
	map.insert(tmp1.begin(), tmp1.end());
	printMap(map, 3); //3#
	{
		typename T::value_type val(-15, 42);
		std::cout << "4#  " << tmp.insert(val).first->first << std::endl; // 4#
	}
	map.insert(tmp.begin(), tmp.begin());
	printMap(map, 5); //5#
	map.insert(tmp.begin(), ++tmp.begin());
	printMap(map, 6); //6#
	{
		typename T::value_type val(-42, 42);
		tmp.insert(val);
	}
	std::cout << "7#  " << map.insert(map.begin(), *tmp.begin())->first << std::endl; // 7#
	printMap(map, 8); //8#
	std::cout << "9#  " << map.insert(tmp.begin(), *tmp.begin())->first << std::endl; // 9#
	printMap(map, 10); //10#
	{
		typename T::value_type val(-52, 42);
		tmp.insert(val);
	}
	std::cout << "11#  " << map.insert(map.begin(), *tmp.begin())->first << std::endl; // 11#
	printMap(map, 12); //12#

				/* ERASE */
	heading("erase");
	map.erase(map.begin());
	printMap(map, 0); // 0#
	map.erase(map.begin()++);
	printMap(map, 1); // 1#
	std::cout << "2#  " << map.erase(3) << std::endl;
	printMap(map, 3); // 3#
	std::cout << "4#  " << map.erase(404) << std::endl;
	printMap(map, 5); // 5#
	map.erase(map.begin(), map.end());
	printMap(map, 6); // 6#
	map.erase(map.begin(), map.begin());
	printMap(map, 7); // 7#
	
				/* SWAP */
	heading("swap");
	for (int i = 0; i < 5; i++)
	{
		typename T::value_type val(i, i);
		map.insert(val);
	}
	T swap;
	map.swap(swap);
	printMap(map, 0); // 0#
	printMap(swap, 1); // 1#
	map.insert(swap.begin()++, swap.end());
	map.swap(swap);
	printMap(map, 2); // 2#
	printMap(swap, 3); // 3#
	
				/* CLEAR */
	heading("clear");
	swap.clear();
	printMap(swap, 0); // 0#
	tmp.clear();
	printMap(tmp, 1); // 1#
	T empty;
	empty.clear();
	printMap(empty, 2); // 2#
}

#endif
