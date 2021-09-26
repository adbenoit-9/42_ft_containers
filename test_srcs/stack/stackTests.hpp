/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 01:11:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKTESTS_HPP
# define STACKTESTS_HPP

# include "modifiers.stack.hpp"
# include "observers.stack.hpp"
# include "operators.stack.hpp"

template<class T, class C>
void    stackTests(ft::stack<T,C>& stack)
{
	ft_observers(stack);
	
				/* MODIFIERS = */
	ft_push(stack);
	ft_pop(stack);
	for (int i = 0; i < 5; i++)
		stack.push(i);

	ft_operators(stack);

				/* COPY CONSTRUCTOR */
	heading("copy constructor");
	ft::stack<T,C> copy(stack);
	print(stack, 0);
	print(copy, 1);
	
	stack.pop();
	
				/* OPERATOR = */
	heading("operator =");
	copy = stack;
	print(stack, 0);
	print(copy, 1);
	std::cout << std::endl;
}

#endif
