/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/26 19:54:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "../containers.hpp"
# include "iteratorsV.hpp"
# include "modifiersV.hpp"
# include "operatorsV.hpp"
# include "observersV.hpp"
# include "elementAccess.hpp"
# include "printVector.hpp"

template <class T>
void    vectorTests(T& vect)
{	
		/*** MEMBER FUNCTIONS ***/
			
	vectorObservers(vect);
	vectorModifiers(vect);
	vectorIterators(vect);
	vectorElementAccess(vect);
	vectorOperators(vect);
	
			/* COPY CONSTRUCTOR */
	heading("copy constructor");
	T copy(vect);
	printVector(copy, 0); // 0#
	copy.clear();
	printVector(vect, 1); // 1#
	
	vect.insert(vect.end(), 42);
	
			/* OPERATOR = */
	heading("operator =");
	copy = vect;
	printVector(copy, 0); // 0#
	copy.clear();
	printVector(vect, 1); // 1#
	std::cout << std::endl;
	
		/*** NON-MEMBER FUNCTION ***/

			/* SWAP */
	std::cout	<< "~ non_member funtion ~" << std::endl;
	heading("swap");
	T swap(4);
	swap.resize(10);
	ft::swap(vect, swap);
	printVector(vect, 0); // 0#
	printVector(swap, 1); // 1#
	std::cout << std::endl;
}

#endif
