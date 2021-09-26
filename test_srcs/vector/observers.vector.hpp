/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.vector.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:55:38 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 00:54:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVERS_VECTOR_HPP
# define OBSERVERS_VECTOR_HPP

# include "print.vector.hpp"

template<class T>
void	ft_observers(const ft::vector<T>& vect)
{
	ft::vector<T> tmp = vect;
	ft::vector<T> tmp1;
	
				/* EMPTY */
	heading("empty");
	std::cout << "0#  " << vect.empty() << std::endl; // 0#
	std::cout << "1#  " << tmp.empty() << std::endl; // 1#
	std::cout << "2#  " << tmp1.empty() << std::endl; // 2#
	
				/* RESIZE */
	heading("resize");
	tmp.resize(0, 42);
	print(tmp, 0); // 0#
	tmp.resize(3, 42);
	print(tmp, 1); // 1#
	tmp1.resize(3, 42);
	print(tmp, 2);  // 2#
	tmp1.clear();
	
				/* RESERVE */
	heading("reserve");
	tmp.reserve(0);
	print(tmp, 0); // 0#
	tmp.reserve(6);
	print(tmp, 1); // 1#
	tmp1.reserve(8);
	print(tmp, 2); // 2#
	tmp1.clear();
	
				/* SIZE */
	heading("size");
	std::cout << "0#  " << vect.size() << std::endl; // 0#
	std::cout << "1#  " << tmp.size() << std::endl; // 1#
	std::cout << "2#  " << tmp1.size() << std::endl; // 2#
	
				/* MAX_SIZE */
	heading("max_size");
	std::cout << "0#  " << vect.max_size() << std::endl; // 0#
	std::cout << "1#  " << tmp.max_size() << std::endl; // 1#
	std::cout << "2#  " << tmp1.max_size() << std::endl; // 2#
	
				/* CAPACITY */
	// heading("capacity");
	// std::cout << "0#  " << vect.capacity() << std::endl; // 0#
	// std::cout << "1#  " << tmp.capacity() << std::endl; // 1#
	// std::cout << "2#  " << tmp1.capacity() << std::endl; // 2#
}

#endif
