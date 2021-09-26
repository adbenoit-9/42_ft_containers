/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printMap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:17:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTVECTOR_HPP
# define PRINTVECTOR_HPP

# include <iostream>

template<class T>
void	printVector(const T &vect, int n)
{
	std::cout << n << "#  size: " << vect.size() << std::endl << "    ";
	for (typename T::const_iterator it = vect.begin() ; it != vect.end(); ++it)
		std::cout  << *it << " ";
	if (vect.empty() == 1)
		std::cout << "empty vector";
	std::cout << std::endl;	
}

#endif
