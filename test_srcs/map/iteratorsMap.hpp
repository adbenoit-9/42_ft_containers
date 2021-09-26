/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorsMap.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:36 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORSMAP_HPP
# define ITERATORSMAP_HPP

# include "printMap.hpp"

template<class T>
void	mapIterators(T& map)
{
	T tmp;
					/* ITERATOR */
	heading("iterator");
	printMap(tmp, 0); // 0#
	for (typename T::iterator it = map.begin() ; it != map.end(); ++it)
		tmp.insert(*it);
	printMap(tmp, 1); // 1#
	typename T::iterator it = map.begin();
	std::cout << "2#  " << it->first << std::endl; // 2#
	++it;
	std::cout << "3#  " << it->first << std::endl; // 3#
	--it;
	std::cout << "4#  " << it->first << std::endl; // 4#

	tmp.clear();
	
			/* REVERSE ITERATOR */
	heading("reverse_iterator");
	printMap(tmp, 0); // 0#
	for (typename T::reverse_iterator rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
		tmp.insert(*rit.base());
	printMap(tmp, 1); // 1#
	typename T::reverse_iterator rit = map.rbegin();
	std::cout << "2#  " << rit->first << std::endl; // 2#
	++rit;
	std::cout << "3#  " << rit->first << std::endl; // 3#
	--rit;
	std::cout << "4#  " << rit->first << std::endl; // 4#
}


#endif
