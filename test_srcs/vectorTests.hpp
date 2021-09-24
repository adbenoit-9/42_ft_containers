/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/25 01:47:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTS_HPP
# define VECTORTESTS_HPP

# include "test.hpp"

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

template<class T>
void	checkVectorCapacity(T &vect)
{
				/* SIZE */
	std::cout	<< "⬜  size:" << std::endl;
	// 0#
	vect.resize(3, 42);
	printVector(vect, 0);
	// 1#
	vect.reserve(6);
	printVector(vect, 1);
	std::cout << std::endl;
	
				/* MAX_SIZE */
	std::cout	<< "⬜  max_size:" << std::endl;
	// 0#
	vect.resize(3, 41);
	printVector(vect, 0);
	// 1#
	vect.reserve(6);
	printVector(vect, 1);
	std::cout << std::endl;
	
				/* CAPACITY */
	std::cout	<< "⬜  capacity:" << std::endl;
	// 0#
	vect.resize(3, 42);
	printVector(vect, 0);
	// 1#
	vect.reserve(6);
	printVector(vect, 1);
	std::cout << std::endl;
}

template<class T>
void	checkVectorIterators(T &vect)
{
				/* ITERATOR */
	std::cout << "⬜  iterator:" << std::endl;
	// 0#
	int i = 0;
	for (typename T::iterator it = vect.begin() ; it != vect.end(); ++it)
		*it = ++i;
	i = 0;
	printVector(vect, 0);
  	std::cout << std::endl;
	
				/* CONST ITERATOR */
	const T constVect(10, 42);
	for (typename T::const_iterator it = constVect.begin(); it != constVect.end(); ++it)
		*it;

				/* REVERSE ITERATOR */
	std::cout << "⬜  rev_it:" << std::endl;
	// 0#
	i = 0;
	for (typename T::reverse_iterator rit = vect.rbegin(); rit != vect.rend(); ++rit)
		*rit = ++i;
	printVector(vect, 0);
  	std::cout << std::endl;
}

template<class T>
void	checkVectorElementAccess(T &vect)
{
				/* AT */
	std::cout << "⬜  at:" << std::endl;
	try
	{
		std::cout << "0#  " << vect.at(1) << std::endl; // 0#
		vect.at(6);
		std::cout << "1#  Error\n";
	}
	catch(const std::exception& e) {}
  	std::cout << std::endl;
	
				/* FRONT */
	std::cout << "⬜  front:" << std::endl;
	std::cout << "0#  " << vect.front() << std::endl; // 0#
	vect.erase(vect.begin());
	std::cout << "1#  " << vect.front() << std::endl; // 1#
  	std::cout << std::endl;
	
				/* BACK */
	std::cout << "⬜  back:" << std::endl;
	std::cout << "0#  " << vect.back() << std::endl; // 0#
	vect.push_back(1);
	std::cout << "1#  " << vect.back() << std::endl; // 1#
	vect.pop_back();
	std::cout << "2#  " << vect.back() << std::endl; // 2#
  	std::cout << std::endl;
	
}

template<class T>
void	checkVectorModifiers(T &vect)
{	
				/* ASSIGN */
	std::cout << "⬜  assign:" << std::endl;
	vect.assign(0, 9);
	printVector(vect, 0); // 0#
	vect.assign(1, 9);
	printVector(vect, 1); // 1#
	
	T toCopy(7, 42);
	vect.assign(toCopy.begin(), toCopy.end());
	printVector(vect, 2); // 2#
  	std::cout << std::endl;
	
				/* PUSH_BACK */
	std::cout << "⬜  push_back:" << std::endl;
	vect.push_back(1);
	printVector(vect, 0); // 0#
  	std::cout << std::endl;
	
				/* POP_BACK */
	std::cout << "⬜  pop_back:" << std::endl;
	vect.pop_back();
	printVector(vect, 0); // 0#
  	std::cout << std::endl;

				/* INSERT */
	std::cout << "⬜  insert:" << std::endl;
	// 0#
	vect.assign(0, 0);
	for (int i = 0; i < 5; i++)
		vect.push_back(i);
	vect.insert(vect.end(), 42);
	printVector(vect, 0);
	// 1#
	vect.insert(vect.begin() + 4, 3, 10);
	printVector(vect, 1);
	// 2#
	T tmp;
	vect.assign(0, 0);
	for (int i = 1; i < 5; i++)
		vect.push_back(i);
	tmp.resize(4);
	tmp.insert(tmp.begin() + 2, vect.begin(), vect.end());
	printVector(tmp, 2);
	// 3#
	vect.insert(vect.begin(), 2, 42);
	printVector(vect, 3);
  	std::cout << std::endl;

				/* ERASE */
	std::cout << "⬜  erase:" << std::endl;
	// 0#
	vect.erase(vect.begin() + 2);
	printVector(vect, 0);
	// 1#
	vect.erase(vect.begin() + 2, vect.end() - 1);
	printVector(vect, 1);
  	std::cout << std::endl;
	
				/* SWAP */
	std::cout << "⬜  swap:" << std::endl;
	T toSwap(5, 8);
	vect.swap(toSwap);
	printVector(vect, 0); // 0#
  	std::cout << std::endl;
	
				/* CLEAR */
	std::cout << "⬜  clear:" << std::endl;
	T copy(vect);
	copy.clear();
	printVector(vect, 0); // 0#
  	std::cout << std::endl;
}

template<class T>
void	checkVectorOperators(const T& vect)
{
	std::cout << "⬜  operators:" << std::endl;
	
	T copy(vect); // 0#
	std::cout << "0#  ";
	std::cout << (vect == copy) << " ";
	std::cout << (vect != copy) << " ";
	std::cout << (vect < copy) << " ";
	std::cout << (vect <= copy) << " ";
	std::cout << (vect > copy) << " ";
	std::cout << (vect >= copy) << " ";
	std::cout << vect[0] << std::endl;
	
	copy.erase(copy.begin()); // 1#
	std::cout << "1#  ";
	std::cout << (vect == copy) << " ";
	std::cout << (vect != copy) << " ";
	std::cout << (vect < copy) << " ";
	std::cout << (vect <= copy) << " ";
	std::cout << (vect > copy) << " ";
	std::cout << (vect >= copy) << " ";
	std::cout << vect[0] << std::endl;
}

template <class T>
void    vectorTests(T& vect)
{	
			/* MEMBER FUNCTIONS */
			
	checkVectorCapacity(vect);
	checkVectorIterators(vect);
	checkVectorElementAccess(vect);
	checkVectorModifiers(vect);
	
	vect.insert(vect.end(), 42);
	checkVectorOperators(vect);
	std::cout << std::endl;
	
			/* NON-MEMBER FUNCTION */
	// SWAP
	std::cout	<< "#### non_member funtion ####" << std::endl
				<< "⬜  swap:" << std::endl;
	T swap(4);
	swap.resize(10);
	ft::swap(vect, swap);
	printVector(vect, 0); // 0#
	printVector(swap, 1); // 1#
	std::cout << std::endl;
}

#endif
