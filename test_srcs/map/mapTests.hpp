/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:53:53 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 01:11:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPTESTS_HPP
# define MAPTESTS_HPP

# include "iterators.map.hpp"
# include "modifiers.map.hpp"
# include "operators.map.hpp"
# include "observers.map.hpp"

template<class Key, class Value>
void    mapTests(ft::map<Key, Value>& map)
{
	for (int i = 0; i < 6; ++i) {
		typename ft::map<Key, Value>::value_type val(i, i);
		map.insert(val);
	}
	
	ft_iterators(map);
	ft_modifiers(map);
	ft_operators(map);
	ft_observers(map);

				/* COPY CONSTRUCTOR */
	heading("copy constructor");
	ft::map<Key, Value> copy(map);
	print(copy, 0); // 0#
	copy.clear();
	print(map, 1); // 1#
	
	typename ft::pair<Key, Value> val = ft::make_pair(1000, 10);
	map.insert(val);
	
				/* OPERATOR = */
	heading("operator =");
	copy = map;
	print(copy, 0); // 0#
	copy.clear();
	print(map, 1); // 1#
	std::cout << std::endl;
}

#endif
