/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/09 14:22:36 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template< class T >
void	print_vector(T &v)
{
	for (typename T::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
}

template< class T, class T1 >
void check_attributs(T &myVector, T1 &stdVector)
{
	if (myVector.capacity() != stdVector.capacity())
		std::cout << "| KO : " << "capac. " << myVector.capacity() << " - " << stdVector.capacity()<< "\t|";
	else if (myVector.size() != stdVector.size())
		std::cout << "| KO : " << "size " << myVector.size() << " - " << stdVector.size()<< "\t|";
	else if (myVector.max_size() != stdVector.max_size())
		std::cout << "| KO : " << "max_size " << myVector.max_size() << " - " << stdVector.max_size()<< "\t|";
	else
		std::cout << "|\tOK\t\t|";
}

void    testVector(void)
{
	std::cout << "\033[33;1m"
				<< "*************************************************************************" << std::endl
				<< "*                                  Vector                               *" << std::endl
				<< "*************************************************************************" << std::endl
				<< "\033[0m" << std::endl;

	std::vector<int> stdVector;
	ft::vector<int> myVector;

	stdVector.resize(3, 42);
	myVector.resize(3, 42);

	std::cout << "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << "\tattributs\t|" << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tsize()\t\t|\t\t" << stdVector.size()
			<< "\t|\t\t" << myVector.size() << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tmax_size()\t|  " << stdVector.max_size()
			<< "\t|  " << myVector.max_size() << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl;

	stdVector.reserve(6);
	myVector.reserve(6);

	std::cout << "|\tcapacity()\t|\t\t" << stdVector.capacity()
			<< "\t|\t\t" << myVector.capacity() << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tempty()\t\t|\t\t" << stdVector.empty()
			<< "\t|\t\t" << myVector.empty() << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|    begin() + end()\t|\t";

	int i = 0;
	for (std::vector<int>::iterator it = stdVector.begin() ; it != stdVector.end(); ++it)
	{
		*it = ++i;
    	std::cout << ' ' << *it;
	}
	std::cout << "\t\t|\t";
	i = 0;
	for (ft::vector<int>::iterator it = myVector.begin() ; it != myVector.end(); ++it)
	{
		*it = ++i;
    	std::cout << ' ' << *it;
	}
  	std::cout << "\t\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|    rbegin() + rend()\t|\t";

	std::vector<int>::reverse_iterator rit = stdVector.rbegin();

	i = 0;
	for (rit = stdVector.rbegin(); rit != stdVector.rend(); ++rit)
		*rit = ++i;
	print_vector(stdVector);

	std::cout << "\t\t|\t";

	ft::vector<int>::reverse_iterator rit1 = myVector.rbegin();

	i = 0;
	for (rit1 = myVector.rbegin(); rit1 != myVector.rend(); ++rit1)
		*rit1 = ++i;
	print_vector(myVector);
	
  	std::cout << "\t\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tat()\t\t|\t";

	try
	{
		std::cout << stdVector.at(1)
					<< " " << stdVector.at(6);
	}
	catch(const std::out_of_range& oor)
	{
		std::cerr << oor.what();
	}
	
	std::cout << "\t|\t";

	try
	{
		std::cout << myVector.at(1)
					<< " " << myVector.at(6);
	}
	catch(const std::out_of_range& oor)
	{
		std::cerr << oor.what();
	}
  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tfront()\t\t|\t\t" << stdVector.front() << "\t|\t\t" << myVector.front()
			<< "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tback()\t\t|\t\t" << stdVector.back() << "\t|\t\t" << myVector.back()
			<< "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tassign()\t|\t\t";
	stdVector.assign(1, 9);
	myVector.assign(1, 9);
	print_vector(stdVector);
	std::cout << "\t|\t\t";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tassign()\t|";
	ft::vector<int> toCopy(7, 42);
	stdVector.assign(toCopy.begin(), toCopy.end());
	myVector.assign(toCopy.begin(), toCopy.end());
	print_vector(stdVector);
	std::cout << "\t|";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tpush_back()\t|";
	stdVector.push_back(1);
	print_vector(stdVector);
	myVector.push_back(1);
	std::cout << "|";
	print_vector(myVector);

	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tpop_back()\t|";
	stdVector.pop_back();
	myVector.pop_back();
	print_vector(stdVector);
	std::cout << "\t|";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (1)\t|\t";
	stdVector.assign(0, 0);
	myVector.assign(0, 0);
	for (int i = 0; i < 5; i++)
	{
		stdVector.push_back(i);
		myVector.push_back(i);
	}
	stdVector.insert(stdVector.begin() + 2, 42);
	myVector.insert(myVector.begin() + 2, 42);
	print_vector(stdVector);
	std::cout << "\t|\t";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (2)\t|";
	stdVector.insert(stdVector.begin() + 4, 3, 10);
	myVector.insert(myVector.begin() + 4, 3, 10);
	print_vector(stdVector);
	std::cout << "\t|";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (3)\t|";
	stdVector.assign(0, 0);
	myVector.assign(0, 0);
	for (int i = 0; i < 5; i++)
	{
		stdVector.push_back(i);
		myVector.push_back(i);
	}
	stdVector.insert(stdVector.begin() + 4, toCopy.begin(), toCopy.end() - 3);
	myVector.insert(myVector.begin() + 4, toCopy.begin(), toCopy.end() - 3);
	print_vector(stdVector);
	std::cout << "\t|";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\terase() (1)\t|";
	stdVector.erase(stdVector.begin() + 2);
	myVector.erase(myVector.begin() + 2);
	print_vector(stdVector);
	std::cout << "\t|";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\terase() (2)\t|\t\t";
	stdVector.erase(stdVector.begin() + 2, stdVector.end() - 1);
	myVector.erase(myVector.begin() + 2, myVector.end() - 1);
	print_vector(stdVector);
	std::cout << "\t|\t\t";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tswap()\t\t|\t";
	ft::vector<int> ftSwap(5, 8);
	std::vector<int> stdSwap(5, 8);
	myVector.swap(ftSwap);
	stdVector.swap(stdSwap);
	print_vector(stdVector);
	std::cout << "\t|\t";
	print_vector(myVector);

  	std::cout << "\t";
	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------" << std::endl
			<< "|\tclear()\t\t|";
	std::vector<int> stdCpy(stdVector);
	ft::vector<int> myCpy(myVector);
	stdCpy.clear();
	myCpy.clear();
	print_vector(stdCpy);
	std::cout << "\t\t\t|\t\t\t";
	print_vector(stdCpy);

	check_attributs(myVector, stdVector);
	std::cout << std::endl
			<< "-------------------------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "\n-------------------------------------------------------------------------" << std::endl
			<< "|\tOperators\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t[]\t\t|\t\t" << stdVector[1]
			<< "\t|\t\t" << myVector[1] << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t==\t\t|\t\t" << (stdVector == stdSwap)
			<< "\t|\t\t" << (myVector == ftSwap) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t!=\t\t|\t\t" << (stdVector != stdSwap)
			<< "\t|\t\t" << (myVector != ftSwap) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t<\t\t|\t\t" << (stdVector < stdSwap)
			<< "\t|\t\t" << (myVector < ftSwap) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t<=\t\t|\t\t" << (stdVector <= stdSwap)
			<< "\t|\t\t" << (myVector <= ftSwap) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t>\t\t|\t\t" << (stdVector > stdSwap)
			<< "\t|\t\t" << (myVector > ftSwap) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t>=\t\t|\t\t" << (stdVector >= stdSwap)
			<< "\t|\t\t" << (myVector >= ftSwap) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< std::endl;
			
	swap(myVector, ftSwap);
	swap(stdVector, stdSwap);
	std::cout << "-- swap() --\nstd::vector\t:";
	print_vector(stdVector);
	std::cout << " -"; 
	print_vector(stdSwap);
	std::cout << "\nft::vector\t:";
	print_vector(myVector);
	std::cout << " -"; 
	print_vector(ftSwap);
	std::cout << std::endl << std::endl;
	
	const ft::vector<int> v(10, 42);
	const std::vector<int> v1(10, 42);
	std::cout << "-- const_iterator() --\nstd::vector\t:";
	for (std::vector<int>::const_iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\nft::vector\t:";
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << std::endl;

	ft::vector<int> v2(1, 1);
	ft::vector<int>::const_iterator it = v2.begin();
}
