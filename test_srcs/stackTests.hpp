/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/25 00:45:47 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKTESTS_HPP
#define STACKTESTS_HPP

#include <iostream>

template<class T>
void	printStack(const T &vect, int n)
{
	std::cout << n << "#  size: " << vect.size();
	if (vect.empty() == 1)
		std::cout << std::endl << "    empty stack";
	std::cout << std::endl;	
}

template<class T>
void	checkOperators(const T& stack)
{
	std::cout << "⬜ operators:" << std::endl;
	
	T copy(stack);
	std::cout << "0#  ";
	std::cout << (stack == copy) << " ";
	std::cout << (stack != copy) << " ";
	std::cout << (stack < copy) << " ";
	std::cout << (stack <= copy) << " ";
	std::cout << (stack > copy) << " ";
	std::cout << (stack >= copy) << " ";
	std::cout << std::endl;	
	
	copy.pop();
	std::cout << "1#  ";
	std::cout << (stack == copy) << " ";
	std::cout << (stack != copy) << " ";
	std::cout << (stack < copy) << " ";
	std::cout << (stack <= copy) << " ";
	std::cout << (stack > copy) << " ";
	std::cout << (stack >= copy) << " ";
	std::cout << std::endl;	
}

template<class T>
void    stackTests(T stack)
{

	{
					/* EMPTY */
		// 0#
		T tmp(stack);
		std::cout << "⬜ empty:" << std::endl;
		printStack(tmp, 0);
		// 1#
		tmp.push(1);
		printStack(tmp, 1);
		// 2#
		tmp.pop();
		printStack(tmp, 2);
		std::cout << std::endl;
	}
	{
					/* SIZE */
		// 0#
		T tmp;
		std::cout << "⬜ size:" << std::endl;
		printStack(tmp, 0);
		// 1#
		tmp.push(1);
		printStack(tmp, 1);
		// 2#
		tmp.pop();
		printStack(tmp, 2);
		std::cout << std::endl;
	}
	{
					/* TOP */
		// 0#
		T tmp;
		std::cout << "⬜ top:" << std::endl;
		printStack(tmp, 0);
		// 1#
		tmp.push(1);
		printStack(tmp, 1);
		// 2#
		tmp.pop();
		printStack(tmp, 2);
		std::cout << std::endl;
	}
	{
					/* PUSH */
		// 0#
		T tmp;
		std::cout << "⬜ push:" << std::endl;
		printStack(tmp, 0);
		for (int i = 0; i < 5; i++)
		{
			tmp.push(i);
			printStack(tmp, i + 1); // i+1#
		}
					/* POP */
		// 0#
		std::cout << std::endl;
		std::cout << "⬜ pop:" << std::endl;
		printStack(tmp, 0);
		for (int i = 0; i < 5; i++)
		{
			tmp.pop();
			printStack(tmp, i + 1); // i+1#
		}
		std::cout << std::endl;
	}
	{
		T tmp;
		for (int i = 0; i < 5; i++)
			tmp.push(i);
		checkOperators(tmp);
		std::cout << std::endl;
	}
}

#endif
