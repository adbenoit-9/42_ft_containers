/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observersStack.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVERSSTACK_HPP
# define OBSERVERSSTACK_HPP

# include "printStack.hpp"

template<class T>
void	stackObservers(const T& stack)
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

#endif
