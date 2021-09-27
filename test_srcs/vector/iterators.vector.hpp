/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.vector.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 13:42:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_VECTOR_HPP
# define ITERATORS_VECTOR_HPP

# include "print.vector.hpp"

template<class T>
void	ft_iterators(ft::vector<T>& vect)
{
				/* ITERATOR */
	heading("iterator");
	print(vect, 0); // 0#
	int i = 0;
	for (typename ft::vector<T>::iterator it = vect.begin() ; it != vect.end(); ++it)
		*it = ++i;
	print(vect, 1); // 1#
	std::cout << "2#  " << vect.begin() - vect.begin() << std::endl; // 2#
	std::cout << "3#  " << *(vect.begin() + 2) << std::endl; // 3#
	std::cout << "4#  " << *(vect.end() - 1) << std::endl; // 4#
	typename ft::vector<T>::iterator it = vect.begin();
	it += 3;
	std::cout << "5#  " << *it << std::endl; // 5#
	it -=2;
	std::cout << "6#  " << *it << std::endl; // 6#
	std::cout << "7#  " << *--it << *++it << std::endl; // 7#
	std::cout << "8#  " << it[0] << std::endl; // 8#
	
				/* REVERSE ITERATOR */
	heading("reverse_iterator");
	print(vect, 0); // 0#
	i = 0;
	for (typename ft::vector<T>::reverse_iterator rit = vect.rbegin(); rit != vect.rend(); ++rit)
		*rit = ++i;
	print(vect, 1); // 1#
	std::cout << "2#  " << vect.begin() - vect.begin() << std::endl; // 2#
	std::cout << "3#  " << *(vect.begin() + 2) << std::endl; // 3#
	std::cout << "4#  " << *(vect.end() - 1) << std::endl; // 4#
	typename ft::vector<T>::reverse_iterator rit = vect.rbegin();
	rit += 3;
	std::cout << "5#  " << *rit << std::endl; // 5#
	rit -=2;
	std::cout << "6#  " << *rit << std::endl; // 6#
	std::cout << "7#  " << *--rit << *++rit << std::endl; // 7#
	std::cout << "8#  " << rit[0] << std::endl; // 8#
}

#endif
