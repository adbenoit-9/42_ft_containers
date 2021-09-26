/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.vector.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 00:52:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_VECTOR_HPP
# define MODIFIERS_VECTOR_HPP

# include "print.vector.hpp"

template<class T>
void	ft_modifiers(ft::vector<T> &vect)
{	
				/* ASSIGN */
	heading("assign");
	vect.assign(0, 9);
	print(vect, 0); // 0#
	vect.assign(1, 9);
	print(vect, 1); // 1#
	
	ft::vector<T> toCopy(7, 42);
	vect.assign(toCopy.begin(), toCopy.end());
	print(vect, 2); // 2#
	
				/* PUSH_BACK */
	heading("push_back");
	vect.push_back(1);
	print(vect, 0); // 0#
  	std::cout << std::endl;
	
				/* POP_BACK */
	heading("pop_back");
	vect.pop_back();
	print(vect, 0); // 0#
  	std::cout << std::endl;

				/* INSERT */
	heading("insert");
	vect.assign(0, 0);
	for (int i = 0; i < 5; i++)
		vect.push_back(i);
	vect.insert(vect.end(), 42);
	print(vect, 0); // 0#
	vect.insert(vect.begin() + 4, 3, 10);
	print(vect, 1);  // 1#
	ft::vector<T> tmp;
	vect.assign(0, 0);
	for (int i = 1; i < 5; i++)
		vect.push_back(i);
	tmp.resize(4);
	tmp.insert(tmp.begin() + 2, vect.begin(), vect.end());
	print(tmp, 2);  // 2#
	vect.insert(vect.begin(), 2, 42);
	print(vect, 3); // 3#

				/* ERASE */
	heading("erase");
	vect.erase(vect.begin() + 2);
	print(vect, 0); // 0#
	vect.erase(vect.begin() + 2, vect.end() - 1);
	print(vect, 1); // 1#
	
				/* SWAP */
	heading("swap");
	ft::vector<T> toSwap(5, 8);
	vect.swap(toSwap);
	print(vect, 0); // 0#
	
				/* CLEAR */
	heading("clear");
	ft::vector<T> copy(vect);
	copy.clear();
	print(vect, 0); // 0#
}

#endif
