/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:49:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTACCESS_HPP
# define ELEMENTACCESS_HPP

# include "printVector.hpp"

template<class T>
void	vectorElementAccess(const T& vect)
{
				/* AT */
	heading("at");
	try
	{
		std::cout << "0#  " << vect.at(1) << std::endl; // 0#
		vect.at(6);
		std::cout << "1#  Error\n"; // 1#
	}
	catch(const std::exception& e) {}
	
				/* FRONT */
	heading("front");
	std::cout << "0#  " << vect.front() << std::endl; // 0#
	T tmp(vect);
	tmp.erase(tmp.begin());
	std::cout << "1#  " << tmp.front() << std::endl; // 1#
	
				/* BACK */
	heading("back");
	std::cout << "0#  " << vect.back() << std::endl; // 0#
	tmp.push_back(1);
	std::cout << "1#  " << tmp.back() << std::endl; // 1#
	tmp.pop_back();
	std::cout << "2#  " << tmp.back() << std::endl; // 2#
}

#endif
