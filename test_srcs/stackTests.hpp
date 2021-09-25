/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/25 16:04:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKTESTS_HPP
#define STACKTESTS_HPP

#include <iostream>

template<class T>
void	printStack(const T &stack, int n)
{
	std::cout << n << "#  size: " << stack.size();
	if (stack.empty() == 1)
		std::cout << std::endl << "    empty stack";
	std::cout << std::endl;	
}

template<class T>
void	checkStackObservers(const T& stack)
{
				/* EMPTY */
	T tmp(stack);
	heading("empty");
	std::cout << "0#  " << stack.empty() << std::endl; // 0#
	tmp.push(1);
	std::cout << "1#  " << tmp.empty() << std::endl; // 1#
	tmp.pop();
	std::cout << "2#  " << tmp.empty() << std::endl; // 2#
				/* SIZE */
	heading("size");
	std::cout << "0#  " << stack.size() << std::endl; // 0#
	std::cout << "1#  " << tmp.size() << std::endl; // 1#
	tmp.push(1);
	std::cout << "2#  " << tmp.size() << std::endl; // 2#
				/* TOP */
	heading("top");
	std::cout << "1#  " << tmp.top() << std::endl; // 1#
	tmp.push(2);
	std::cout << "2#  " << tmp.top() << std::endl; // 2#
}

template<class T>
void	checkStackModifers(T& stack)
{
				/* PUSH */
	heading("push");
	printStack(stack, 0); // #0
	for (int i = 0; i < 5; i++)
	{
		stack.push(i);
		printStack(stack, i + 1); // i+1#
	}
				/* POP */
	heading("pop");
	printStack(stack, 0); // #0
	for (int i = 0; i < 5; i++)
	{
		stack.pop();
		printStack(stack, i + 1); // i+1#
	}
}

template<class T>
void	checkStackOperators(const T& stack)
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

template<class T>
void    stackTests(T& stack)
{
	checkStackObservers(stack);
	checkStackModifers(stack);
	for (int i = 0; i < 5; i++)
		stack.push(i);
	checkStackOperators(stack);

					/* COPY CONSTRUCTOR */
	heading("copy constructor");
	T copy(stack);
	printStack(stack, 0);
	printStack(copy, 1);
	
	stack.pop();
	
				/* OPERATOR = */
	heading("operator =");
	copy = stack;
	printStack(stack, 0);
	printStack(copy, 1);
	std::cout << std::endl;
}

#endif
