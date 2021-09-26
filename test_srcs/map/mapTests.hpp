/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:53:53 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPTESTS_HPP
# define MAPTESTS_HPP

# include "iteratorsMap.hpp"
# include "modifiersMap.hpp"
# include "operatorsMap.hpp"
# include "observersMap.hpp"
# include "printMap.hpp"

template<class T>
void    mapTests(T& map)
{
	for (int i = 0; i < 6; ++i) {
		typename T::value_type	val(i, i);
		map.insert(val);
	}
	
	mapIterators(map);
	mapModifiers(map);
	mapOperators(map);
	mapObservers(map);

				/* COPY CONSTRUCTOR */
	heading("copy constructor");
	T copy(map);
	printMap(copy, 0); // 0#
	copy.clear();
	printMap(map, 1); // 1#
	
	typename T::value_type	val(1000, 10);
	map.insert(val);
	
				/* OPERATOR = */
	heading("operator =");
	copy = map;
	printMap(copy, 0); // 0#
	copy.clear();
	printMap(map, 1); // 1#
	std::cout << std::endl;
}

#endif
