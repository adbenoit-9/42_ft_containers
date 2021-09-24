/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:53:53 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/25 01:41:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPTESTS_HPP
#define MAPTESTS_HPP

#include <iostream>

template<class T>
void	printMap(const T& map, int n)
{
	std::cout << n << "#  size: " << map.size() << std::endl << "    ";
	for (typename T::const_iterator it = map.begin() ; it != map.end(); ++it)
		std::cout << "(" << it->first << ", " << it->second << ") ";
	if (map.empty() == 1)
		std::cout << "empty map";
	std::cout << std::endl;
}

template<class T>
void	checkMapIterators(T& map)
{
	T tmp;
					/* ITERATOR */
	std::cout << "⬜ iterator:" << std::endl;
	for (typename T::iterator it = map.begin() ; it != map.end(); ++it)
		tmp.insert(*it);
	printMap(tmp, 0); // 0#
	std::cout << std::endl;

	
	tmp.clear();
			/* REVERSE ITERATOR */
	std::cout << "⬜ reverse:iterator:" << std::endl;
	for (typename T::reverse_iterator rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
		tmp.insert(*rit.base());
	printMap(tmp, 0); // 0#
	std::cout << std::endl;
}


template<class T>
void	checkMapModifiers(T &map)
{
				/* INSERT */
	std::cout << "⬜ insert:" << std::endl;
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
	std::cout << std::endl;

				/* ERASE */
	std::cout << "⬜ erase:" << std::endl;
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
	std::cout << std::endl;
	
				/* SWAP */
	std::cout << "⬜ swap:" << std::endl;;
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
	std::cout << std::endl;
	
				/* CLEAR */
	std::cout << "⬜ clear:" << std::endl;
	swap.clear();
	printMap(swap, 0); // 0#
	tmp.clear();
	printMap(tmp, 1); // 1#
	T empty;
	empty.clear();
	printMap(empty, 2); // 2#
	std::cout << std::endl;
}

template<class T>
void	checkMapOperators(const T& map)
{
				/* FIND */
	std::cout << "⬜ find:" << std::endl;
	std::cout << "0#  (" << map.find(0)->first << ", " << map.find(0)->second << ") ";
	std::cout << "(" << map.find(4)->first << ", " << map.find(4)->second << ") ";
	std::cout << "(" << map.find(2)->first << ", " << map.find(2)->second << ") ";
	std::cout << std::endl;
	
	// 			/* COUNT */
	std::cout << "⬜ count:" << std::endl;
	std::cout << "0#  " << map.count(0);
	std::cout << " " << map.count(4);
	std::cout << " " << map.count(2);
	std::cout << " " << map.count(404);
	std::cout << std::endl;
	
				/* LOWER_BOUND */
	std::cout << "⬜ lower_bound:" << std::endl;
	std::cout << "0#  (" << map.lower_bound(0)->first << ", " << map.lower_bound(0)->second << ") ";
	std::cout << "(" << map.lower_bound(4)->first << ", " << map.lower_bound(4)->second << ") ";
	std::cout << "(" << map.lower_bound(2)->first << ", " << map.lower_bound(2)->second << ") ";
	std::cout << std::endl;
	
				/* UPPER_BOUND */
	std::cout << "⬜ upper_bound:" << std::endl;
	std::cout << "0#  (" << map.upper_bound(0)->first << ", " << map.upper_bound(0)->second << ") ";
	std::cout << "(" << map.upper_bound(2)->first << ", " << map.upper_bound(2)->second << ") ";
	std::cout << std::endl;
	
				/* EQUAL_RANGE */
	std::cout << "⬜ equal_range:" << std::endl;
	std::cout << "0#  (" << map.equal_range(0).first->first << ", " << map.equal_range(0).first->second << ") ";
	std::cout << "(" << map.equal_range(4).first->first << ", " << map.equal_range(4).first->second << ") ";
	std::cout << "(" << map.equal_range(2).first->first << ", " << map.equal_range(2).first->second << ") ";
	std::cout << std::endl;
}

template<class T>
void    mapTests(T& map)
{
	// title("Map");
			
	for (int i = 0; i < 6; ++i) {
		typename T::value_type	val(i, i);
		map.insert(val);
	}
	
	checkMapIterators(map);
	checkMapModifiers(map);
	checkMapOperators(map);
	
				/* OPERATOR [] */
	std::cout << "⬜ operator:[]:" << std::endl;
	std::cout << "0#  map[1] = " << map[1] << std::endl;
	map[404] = 404;
	std::cout << "1#  map[404] = " << map[404] << std::endl;
	std::cout << std::endl;
	
				/* CONST MAP */
	std::cout	<< "\t###### const map ######" << std::endl;;
	const T constMap(map);
	checkMapOperators(map);
	std::cout << std::endl;
}

#endif
