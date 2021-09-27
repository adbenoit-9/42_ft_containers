/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.map.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 20:29:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_MAP_HPP
# define OPERATORS_MAP_HPP

# include "print.map.hpp"

template<class Key, class Value>
void	ft_operators(const ft::map<Key, Value>& map)
{
				/* FIND */
	heading("find");
	std::cout << "0#  (" << map.find(0)->first << ", " << map.find(0)->second << ")" << std::endl;
	std::cout << "1#  (" << map.find(4)->first << ", " << map.find(4)->second << ")" << std::endl;
	std::cout << "2#  (" << map.find(2)->first << ", " << map.find(2)->second << ")" << std::endl;
	
	// 			/* COUNT */
	heading("count");
	std::cout << "0#  " << map.count(0) << std::endl;
	std::cout << "1#  " << map.count(4) << std::endl;
	std::cout << "2#  " << map.count(2) << std::endl;
	std::cout << "3#  " << map.count(404) << std::endl;
	
				/* LOWER_BOUND */
	heading("lower_bound");
	std::cout << "0#  (" << map.lower_bound(0)->first << ", " << map.lower_bound(0)->second << ")" << std::endl;
	std::cout << "1#  (" << map.lower_bound(4)->first << ", " << map.lower_bound(4)->second << ")" << std::endl;
	std::cout << "2#  (" << map.lower_bound(2)->first << ", " << map.lower_bound(2)->second << ")" << std::endl;
	
				/* UPPER_BOUND */
	heading("upper_bound");
	std::cout << "0#  (" << map.upper_bound(0)->first << ", " << map.upper_bound(0)->second << ")" << std::endl;
	std::cout << "1#  (" << map.upper_bound(2)->first << ", " << map.upper_bound(2)->second << ")" << std::endl;
	
				/* EQUAL_RANGE */
	heading("equal_range");
	std::cout << "0#  (" << map.equal_range(0).first->first << ", " << map.equal_range(0).first->second << ")" << std::endl;
	std::cout << "1#  (" << map.equal_range(4).first->first << ", " << map.equal_range(4).first->second << ")" << std::endl;
	std::cout << "2#  (" << map.equal_range(2).first->first << ", " << map.equal_range(2).first->second << ")" << std::endl;
	
	
	heading("operators");
	ft::map<Key, Value> copy(map);
	
	std::cout << "0#  == " << (map == copy) << std::endl;
	std::cout << "1#  != " << (map != copy) << std::endl;
	std::cout << "2#  <  " << (map < copy) << std::endl;
	std::cout << "3#  <= " << (map <= copy) << std::endl;
	std::cout << "4#  >  " << (map > copy) << std::endl;
	std::cout << "5#  >= " << (map >= copy) << std::endl;
	std::cout << "6#  [] " << copy[0] << std::endl;
	
	copy[404] = 404;
	
	std::cout << "7#  == " << (map == copy) << std::endl;
	std::cout << "8#  != " << (map != copy) << std::endl;
	std::cout << "9#  <  " << (map < copy) << std::endl;
	std::cout << "10# <= " << (map <= copy) << std::endl;
	std::cout << "11# >  " << (map > copy) << std::endl;
	std::cout << "12# >= " << (map >= copy) << std::endl;
	std::cout << "13# [] " << copy[404] << std::endl;
}



#endif
