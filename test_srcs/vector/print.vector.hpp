/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 00:27:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_VECTOR_HPP
# define PRINT_VECTOR_HPP

# include "../containers.hpp"

template<class T>
void	print(const ft::vector<T>& vect, int n)
{
	std::cout << n << "#  size: " << vect.size() << std::endl << "    ";
	for (typename ft::vector<T>::const_iterator it = vect.begin() ; it != vect.end(); ++it)
		std::cout  << *it << " ";
	if (vect.empty() == 1)
		std::cout << "empty vector";
	std::cout << std::endl;	
}

#endif
