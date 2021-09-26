/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printMap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:17:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTMAP_HPP
# define PRINTMAP_HPP

# include <iostream>

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

#endif
