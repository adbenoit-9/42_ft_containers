/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:59 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTSTACK_HPP
# define PRINTSTACK_HPP

# include <iostream>

template<class T>
void	printStack(const T &stack, int n)
{
	std::cout << n << "#  size: " << stack.size();
	if (stack.empty() == 1)
		std::cout << std::endl << "    empty stack";
	std::cout << std::endl;	
}

#endif
