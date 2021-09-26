/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiersStack.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:45:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERSSTACK_HPP
# define MODIFIERSSTACK_HPP

# include "printStack.hpp"

template<class T>
void	stackPush(T& stack)
{
	heading("push");
	printStack(stack, 0); // #0
	for (int i = 0; i < 5; i++)
	{
		stack.push(i);
		printStack(stack, i + 1); // i+1#
	}
}

template<class T>
void	stackPop(T& stack)
{
	heading("pop");
	printStack(stack, 0); // #0
	for (int i = 0; i < 5; i++)
	{
		stack.pop();
		printStack(stack, i + 1); // i+1#
	}
}

#endif
