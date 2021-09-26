/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorsV.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:42:36 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORSV_HPP
# define ITERATORSV_HPP

# include "printVector.hpp"

template<class T>
void	vectorIterators(T& vect)
{
				/* ITERATOR */
	heading("iterator");
	printVector(vect, 0); // 0#
	int i = 0;
	for (typename T::iterator it = vect.begin() ; it != vect.end(); ++it)
		*it = ++i;
	printVector(vect, 1); // 0#
	std::cout << "2#  " << vect.begin() - vect.begin() << std::endl; // 1#
	std::cout << "3#  " << *(vect.begin() + 2) << std::endl; // 2#
	std::cout << "4#  " << *(vect.end() - 1) << std::endl; // 3#
	typename T::iterator it = vect.begin();
	it += 3;
	std::cout << "5#  " << *it << std::endl; // 4#
	it -=2;
	std::cout << "6#  " << *it << std::endl; // 5#
	std::cout << "7#  " << *--it << *++it << std::endl; // 6#
	
				/* REVERSE ITERATOR */
	heading("reverse_iterator");
	printVector(vect, 0); // 1#
	i = 0;
	for (typename T::reverse_iterator rit = vect.rbegin(); rit != vect.rend(); ++rit)
		*rit = ++i;
	printVector(vect, 1); // 0#
	std::cout << "2#  " << vect.begin() - vect.begin() << std::endl; // 1#
	std::cout << "3#  " << *(vect.begin() + 2) << std::endl; // 2#
	std::cout << "4#  " << *(vect.end() - 1) << std::endl; // 3#
	typename T::reverse_iterator rit = vect.rbegin();
	rit += 3;
	std::cout << "5#  " << *rit << std::endl; // 4#
	rit -=2;
	std::cout << "6#  " << *rit << std::endl; // 5#
	std::cout << "7#  " << *--rit << *++rit << std::endl; // 6#
}

#endif
