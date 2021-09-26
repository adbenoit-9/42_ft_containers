/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.vector.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 00:55:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_VECTOR_HPP
# define OPERATORS_VECTOR_HPP

# include "print.vector.hpp"

template<class T>
void	ft_operators(const ft::vector<T>& vect)
{
	heading("operators");
	
	ft::vector<T> copy(vect);
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
