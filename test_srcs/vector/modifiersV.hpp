/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiersV.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:41:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERSV_HPP
# define MODIFIERSV_HPP

# include "printVector.hpp"

template<class T>
void	vectorModifiers(T &vect)
{	
				/* ASSIGN */
	heading("assign");
	vect.assign(0, 9);
	printVector(vect, 0); // 0#
	vect.assign(1, 9);
	printVector(vect, 1); // 1#
	
	T toCopy(7, 42);
	vect.assign(toCopy.begin(), toCopy.end());
	printVector(vect, 2); // 2#
	
				/* PUSH_BACK */
	heading("push_back");
	vect.push_back(1);
	printVector(vect, 0); // 0#
  	std::cout << std::endl;
	
				/* POP_BACK */
	heading("pop_back");
	vect.pop_back();
	printVector(vect, 0); // 0#
  	std::cout << std::endl;

				/* INSERT */
	heading("insert");
	vect.assign(0, 0);
	for (int i = 0; i < 5; i++)
		vect.push_back(i);
	vect.insert(vect.end(), 42);
	printVector(vect, 0); // 0#
	vect.insert(vect.begin() + 4, 3, 10);
	printVector(vect, 1);  // 1#
	T tmp;
	vect.assign(0, 0);
	for (int i = 1; i < 5; i++)
		vect.push_back(i);
	tmp.resize(4);
	tmp.insert(tmp.begin() + 2, vect.begin(), vect.end());
	printVector(tmp, 2);  // 2#
	vect.insert(vect.begin(), 2, 42);
	printVector(vect, 3); // 3#

				/* ERASE */
	heading("erase");
	vect.erase(vect.begin() + 2);
	printVector(vect, 0); // 0#
	vect.erase(vect.begin() + 2, vect.end() - 1);
	printVector(vect, 1); // 1#
	
				/* SWAP */
	heading("swap");
	T toSwap(5, 8);
	vect.swap(toSwap);
	printVector(vect, 0); // 0#
	
				/* CLEAR */
	heading("clear");
	T copy(vect);
	copy.clear();
	printVector(vect, 0); // 0#
}

#endif
