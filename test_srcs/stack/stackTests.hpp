/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:47:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKTESTS_HPP
# define STACKTESTS_HPP

# include "modifiersStack.hpp"
# include "observersStack.hpp"
# include "operatorsStack.hpp"
# include "printStack.hpp"

template<class T>
void    stackTests(T& stack)
{
	stackObservers(stack);
	
				/* MODIFIERS = */
	stackPush(stack);
	stackPop(stack);
	for (int i = 0; i < 5; i++)
		stack.push(i);

	stackOperators(stack);

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
