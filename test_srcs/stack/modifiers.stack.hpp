/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.stack.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 00:48:48 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_STACK_HPP
# define MODIFIERS_STACK_HPP

# include "print.stack.hpp"

template<class T, class C>
void	ft_push(ft::stack<T,C>& stack)
{
	heading("push");
	print(stack, 0); // #0
	for (int i = 0; i < 5; i++)
	{
		stack.push(i);
		print(stack, i + 1); // i+1#
	}
}

template<class T, class C>
void	ft_pop(ft::stack<T,C>& stack)
{
	heading("pop");
	print(stack, 0); // #0
	for (int i = 0; i < 5; i++)
	{
		stack.pop();
		print(stack, i + 1); // i+1#
	}
}

#endif
