/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/25 16:03:20 by adbenoit         ###   ########.fr       */
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
void	checkVectorCapacity(const T &vect)
{
	T tmp = vect;
	T tmp1;
	
				/* EMPTY */
	heading("empty");
	std::cout << "0#  " << vect.empty() << std::endl; // 0#
	std::cout << "1#  " << tmp.empty() << std::endl; // 1#
	std::cout << "2#  " << tmp1.empty() << std::endl; // 2#
	
				/* RESIZE */
	heading("resize");
	tmp.resize(0, 42);
	printVector(tmp, 0); // 0#
	tmp.resize(3, 42);
	printVector(tmp, 1); // 1#
	tmp1.resize(3, 42);
	printVector(tmp, 2);  // 2#
	tmp1.clear();
	
				/* RESERVE */
	heading("reserve");
	tmp.reserve(0);
	printVector(tmp, 0); // 0#
	tmp.reserve(6);
	printVector(tmp, 1); // 1#
	tmp1.reserve(8);
	printVector(tmp, 2); // 2#
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

template<class T>
void	checkVectorIterators(T& vect)
{
				/* ITERATOR */
	heading("iterator");
	printVector(vect, 0); // 0#
	int i = 0;
	for (typename T::iterator it = vect.begin() ; it != vect.end(); ++it)
		*it = ++i;
	printVector(vect, 1); // 0#
	std::cout << "2#  " << vect.begin() - vect.begin() << std::endl; // 1#
	std::cout << "3#  " << *(vect.begin() + 2) << std::endl; // 2#
	std::cout << "4#  " << *(vect.end() - 1) << std::endl; // 3#
	typename T::iterator it = vect.begin();
	it += 3;
	std::cout << "5#  " << *it << std::endl; // 4#
	it -=2;
	std::cout << "6#  " << *it << std::endl; // 5#
	std::cout << "7#  " << *--it << *++it << std::endl; // 6#
	
				/* REVERSE ITERATOR */
	heading("reverse_iterator");
	printVector(vect, 0); // 1#
	i = 0;
	for (typename T::reverse_iterator rit = vect.rbegin(); rit != vect.rend(); ++rit)
		*rit = ++i;
	printVector(vect, 1); // 0#
	std::cout << "2#  " << vect.begin() - vect.begin() << std::endl; // 1#
	std::cout << "3#  " << *(vect.begin() + 2) << std::endl; // 2#
	std::cout << "4#  " << *(vect.end() - 1) << std::endl; // 3#
	typename T::reverse_iterator rit = vect.rbegin();
	rit += 3;
	std::cout << "5#  " << *rit << std::endl; // 4#
	rit -=2;
	std::cout << "6#  " << *rit << std::endl; // 5#
	std::cout << "7#  " << *--rit << *++rit << std::endl; // 6#
}

template<class T>
void	checkVectorElementAccess(const T& vect)
{
				/* AT */
	heading("at");
	try
	{
		std::cout << "0#  " << vect.at(1) << std::endl; // 0#
		vect.at(6);
		std::cout << "1#  Error\n"; // 1#
	}
	catch(const std::exception& e) {}
	
				/* FRONT */
	heading("front");
	std::cout << "0#  " << vect.front() << std::endl; // 0#
	T tmp(vect);
	tmp.erase(tmp.begin());
	std::cout << "1#  " << tmp.front() << std::endl; // 1#
	
				/* BACK */
	heading("back");
	std::cout << "0#  " << vect.back() << std::endl; // 0#
	tmp.push_back(1);
	std::cout << "1#  " << tmp.back() << std::endl; // 1#
	tmp.pop_back();
	std::cout << "2#  " << tmp.back() << std::endl; // 2#
}

template<class T>
void	checkVectorModifiers(T &vect)
{	
				/* ASSIGN */
	heading("assign");
	vect.assign(0, 9);
	printVector(vect, 0); // 0#
	vect.assign(1, 9);
	printVector(vect, 1); // 1#
	
	T toCopy(7, 42);
	vect.assign(toCopy.begin(), toCopy.end());
	printVector(vect, 2); // 2#
	
				/* PUSH_BACK */
	heading("push_back");
	vect.push_back(1);
	printVector(vect, 0); // 0#
  	std::cout << std::endl;
	
				/* POP_BACK */
	heading("pop_back");
	vect.pop_back();
	printVector(vect, 0); // 0#
  	std::cout << std::endl;

				/* INSERT */
	heading("insert");
	vect.assign(0, 0);
	for (int i = 0; i < 5; i++)
		vect.push_back(i);
	vect.insert(vect.end(), 42);
	printVector(vect, 0); // 0#
	vect.insert(vect.begin() + 4, 3, 10);
	printVector(vect, 1);  // 1#
	T tmp;
	vect.assign(0, 0);
	for (int i = 1; i < 5; i++)
		vect.push_back(i);
	tmp.resize(4);
	tmp.insert(tmp.begin() + 2, vect.begin(), vect.end());
	printVector(tmp, 2);  // 2#
	vect.insert(vect.begin(), 2, 42);
	printVector(vect, 3); // 3#

				/* ERASE */
	heading("erase");
	vect.erase(vect.begin() + 2);
	printVector(vect, 0); // 0#
	vect.erase(vect.begin() + 2, vect.end() - 1);
	printVector(vect, 1); // 1#
	
				/* SWAP */
	heading("swap");
	T toSwap(5, 8);
	vect.swap(toSwap);
	printVector(vect, 0); // 0#
	
				/* CLEAR */
	heading("clear");
	T copy(vect);
	copy.clear();
	printVector(vect, 0); // 0#
}

template<class T>
void	checkVectorOperators(const T& vect)
{
	heading("operators");
	
	T copy(vect);
	std::cout << "0#  == " << (vect == copy) << std::endl;
	std::cout << "1#  != " << (vect != copy) << std::endl;
	std::cout << "2#  <  " << (vect < copy) << std::endl;
	std::cout << "3#  <= " << (vect <= copy) << std::endl;
	std::cout << "4#  >  " << (vect > copy) << std::endl;
	std::cout << "5#  >= " << (vect >= copy) << std::endl;
	std::cout << "6#  [] " << vect[0] << std::endl;
	
	copy.erase(copy.begin());
	std::cout << "7#  == " << (vect == copy) << std::endl;
	std::cout << "8#  != " << (vect != copy) << std::endl;
	std::cout << "9#  <  " << (vect < copy) << std::endl;
	std::cout << "10# <= " << (vect <= copy) << std::endl;
	std::cout << "11# >  " << (vect > copy) << std::endl;
	std::cout << "12# >= " << (vect >= copy) << std::endl;
	std::cout << "13# [] " << vect[0] << std::endl;
}

template <class T>
void    vectorTests(T& vect)
{	
			/*** MEMBER FUNCTIONS ***/
			
	checkVectorCapacity(vect);
	checkVectorModifiers(vect);
	checkVectorIterators(vect);
	checkVectorElementAccess(vect);
	checkVectorOperators(vect);
	
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
