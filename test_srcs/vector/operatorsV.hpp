/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorsV.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:40:56 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORSV_HPP
# define OPERATORSV_HPP

# include "printVector.hpp"

template<class T>
void	vectorOperators(const T& vect)
{
	heading("operators");
	
	T copy(vect);
	std::cout << "0#  == " << (vect == copy) << std::endl;
	std::cout << "1#  != " << (vect != copy) << std::endl;
	std::cout << "2#  <  " << (vect < copy) << std::endl;
	std::cout << "3#  <= " << (vect <= copy) << std::endl;
	std::cout << "4#  >  " << (vect > copy) << std::endl;
	std::cout << "5#  >= " << (vect >= copy) << std::endl;
	std::cout << "6#  [] " << vect[0] << std::endl;
	
	copy.erase(copy.begin());
	std::cout << "7#  == " << (vect == copy) << std::endl;
	std::cout << "8#  != " << (vect != copy) << std::endl;
	std::cout << "9#  <  " << (vect < copy) << std::endl;
	std::cout << "10# <= " << (vect <= copy) << std::endl;
	std::cout << "11# >  " << (vect > copy) << std::endl;
	std::cout << "12# >= " << (vect >= copy) << std::endl;
	std::cout << "13# [] " << vect[0] << std::endl;
}

#endif
