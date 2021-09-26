/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/27 01:11:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "iterators.vector.hpp"
# include "modifiers.vector.hpp"
# include "operators.vector.hpp"
# include "observers.vector.hpp"
# include "elementAccess.vector.hpp"

template <class T>
void    vectorTests(ft::vector<T>& vect)
{	
		/*** MEMBER FUNCTIONS ***/
			
	ft_observers(vect);
	ft_modifiers(vect);
	ft_iterators(vect);
	ft_elementAccess(vect);
	ft_operators(vect);
	
			/* COPY CONSTRUCTOR */
	heading("copy constructor");
	ft::vector<T> copy(vect);
	print(copy, 0); // 0#
	copy.clear();
	print(vect, 1); // 1#
	
	vect.insert(vect.end(), 42);
	
			/* OPERATOR = */
	heading("operator =");
	copy = vect;
	print(copy, 0); // 0#
	copy.clear();
	print(vect, 1); // 1#
	std::cout << std::endl;
	
		/*** NON-MEMBER FUNCTION ***/

			/* SWAP */
	std::cout	<< "~ non_member funtion ~" << std::endl;
	heading("swap");
	ft::vector<T> swap(4);
	swap.resize(10);
	ft::swap(vect, swap);
	print(vect, 0); // 0#
	print(swap, 1); // 1#
	std::cout << std::endl;
}

#endif
