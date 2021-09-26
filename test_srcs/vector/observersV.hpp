/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observersV.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:49:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVERSV_HPP
# define OBSERVERSV_HPP

# include "printVector.hpp"

template<class T>
void	vectorObservers(const T &vect)
{
	T tmp = vect;
	T tmp1;
	
				/* EMPTY */
	heading("empty");
	std::cout << "0#  " << vect.empty() << std::endl; // 0#
	std::cout << "1#  " << tmp.empty() << std::endl; // 1#
	std::cout << "2#  " << tmp1.empty() << std::endl; // 2#
	
				/* RESIZE */
	heading("resize");
	tmp.resize(0, 42);
	printVector(tmp, 0); // 0#
	tmp.resize(3, 42);
	printVector(tmp, 1); // 1#
	tmp1.resize(3, 42);
	printVector(tmp, 2);  // 2#
	tmp1.clear();
	
				/* RESERVE */
	heading("reserve");
	tmp.reserve(0);
	printVector(tmp, 0); // 0#
	tmp.reserve(6);
	printVector(tmp, 1); // 1#
	tmp1.reserve(8);
	printVector(tmp, 2); // 2#
	tmp1.clear();
	
				/* SIZE */
	heading("size");
	std::cout << "0#  " << vect.size() << std::endl; // 0#
	std::cout << "1#  " << tmp.size() << std::endl; // 1#
	std::cout << "2#  " << tmp1.size() << std::endl; // 2#
	
				/* MAX_SIZE */
	heading("max_size");
	std::cout << "0#  " << vect.max_size() << std::endl; // 0#
	std::cout << "1#  " << tmp.max_size() << std::endl; // 1#
	std::cout << "2#  " << tmp1.max_size() << std::endl; // 2#
	
				/* CAPACITY */
	// heading("capacity");
	// std::cout << "0#  " << vect.capacity() << std::endl; // 0#
	// std::cout << "1#  " << tmp.capacity() << std::endl; // 1#
	// std::cout << "2#  " << tmp1.capacity() << std::endl; // 2#
}

#endif
