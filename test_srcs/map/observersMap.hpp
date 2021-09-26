/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observersMap.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:51:40 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVERSMAP_HPP
# define OBSERVERSMAP_HPP

# include "printMap.hpp"

template<class T>
void	mapObservers(const T &map)
{
	T tmp;
				/* EMPTY */
	heading("empty");
	std::cout << "0#  " << map.empty() << std::endl; // 0#
	std::cout << "1#  " << tmp.empty() << std::endl; // 1#
	
				/* SIZE */
	heading("size");
	std::cout << "0#  " << map.size() << std::endl; // 0#
	std::cout << "1#  " << tmp.size() << std::endl; // 1#
	
	// 			/* MAX_SIZE */
	// heading("max_size");
	// std::cout << "0#  " << map.max_size() << std::endl; // 0#
	// std::cout << "1#  " << tmp.max_size() << std::endl; // 1#
}

#endif
