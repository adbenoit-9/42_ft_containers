/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorsStack.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:56 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORSSTACK_HPP
# define OPERATORSSTACK_HPP

# include "printStack.hpp"

template<class T>
void	stackOperators(const T& stack)
{
	heading("operators");
	
	T copy(stack);
	std::cout << "0#  == " << (stack == copy) << std::endl;
	std::cout << "1#  != " << (stack != copy) << std::endl;
	std::cout << "2#  <  " << (stack < copy) << std::endl;
	std::cout << "3#  <= " << (stack <= copy) << std::endl;
	std::cout << "4#  >  " << (stack > copy) << std::endl;
	std::cout << "5#  >= " << (stack >= copy) << std::endl;
	
	copy.pop();
	std::cout << "6#  == " << (stack == copy) << std::endl;
	std::cout << "7#  != " << (stack != copy) << std::endl;
	std::cout << "8#  <  " << (stack < copy) << std::endl;
	std::cout << "9# <= " << (stack <= copy) << std::endl;
	std::cout << "10# >  " << (stack > copy) << std::endl;
	std::cout << "11# >= " << (stack >= copy) << std::endl;
}

#endif
