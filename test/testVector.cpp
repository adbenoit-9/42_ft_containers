/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/13 23:53:18 by adbenoit         ###   ########.fr       */
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
void	ft_capacity(T &std, T1 &ft)
{
	std.resize(3, 42);
	ft.resize(3, 42);

	std::cout	<< "|\tsize()\t\t|\t\t" << std.size()
			<< "\t|\t\t" << ft.size() << "\t|";
	checkAttributs(ft, std);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tmax_size()\t|  " << std.max_size()
			<< "\t|  " << ft.max_size() << "\t|";
	checkAttributs(ft, std);

	std.reserve(6);
	ft.reserve(6);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tcapacity()\t|\t\t" << std.capacity()
			<< "\t|\t\t" << ft.capacity() << "\t|";
	checkAttributs(ft, std);

	std::cout	<< "-------------------------------------------------------------------------" << std::endl
				<< "|\tempty()\t\t|\t\t" << std.empty()
				<< "\t|\t\t" << ft.empty() << "\t|";
	checkAttributs(ft, std);
}

template< class T, class T1 >
void	ft_iterators(T &std, T1 &ft)
{
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|    begin() + end()\t|\t";

	int i = 0;
	for (std::vector<int>::iterator it = std.begin() ; it != std.end(); ++it)
	{
		*it = ++i;
    	std::cout << ' ' << *it;
	}
	std::cout << "\t\t|\t";
	i = 0;
	for (ft::vector<int>::iterator it = ft.begin() ; it != ft.end(); ++it)
	{
		*it = ++i;
    	std::cout << ' ' << *it;
	}
  	std::cout << "\t\t|";
	checkAttributs(ft, std);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|    rbegin() + rend()\t|\t";

	std::vector<int>::reverse_iterator rit = std.rbegin();

	i = 0;
	for (rit = std.rbegin(); rit != std.rend(); ++rit)
		*rit = ++i;
	print_vector(std);

	std::cout << "\t\t|\t";

	ft::vector<int>::reverse_iterator rit1 = ft.rbegin();

	i = 0;
	for (rit1 = ft.rbegin(); rit1 != ft.rend(); ++rit1)
		*rit1 = ++i;
	print_vector(ft);
	
  	std::cout << "\t\t|";
	checkAttributs(ft, std);
}

template< class T, class T1 >
void	ft_elementAccess(T &std, T1 &ft)
{
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tat()\t\t|\t";
	try
	{
		std::cout << std.at(1)
					<< " " << std.at(6);
	}
	catch(const std::out_of_range& oor)
	{
		std::cerr << oor.what();
	}
	std::cout << "\t|\t";
	try
	{
		std::cout << ft.at(1)
					<< " " << ft.at(6);
	}
	catch(const std::out_of_range& oor)
	{
		std::cerr << oor.what();
	}
  	std::cout << "\t|";
	checkAttributs(ft, std);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tfront()\t\t|\t\t" << std.front() << "\t|\t\t" << ft.front()
			<< "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tback()\t\t|\t\t" << std.back() << "\t|\t\t" << ft.back()
			<< "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tassign()\t|\t\t";
	std.assign(1, 9);
	ft.assign(1, 9);
	print_vector(std);
	std::cout << "\t|\t\t";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
}

template< class T, class T1 >
void	ft_modifiers(T &std, T1 &ft)
{
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tassign()\t|";
	ft::vector<int> toCopy(7, 42);
	std.assign(toCopy.begin(), toCopy.end());
	ft.assign(toCopy.begin(), toCopy.end());
	print_vector(std);
	std::cout << "\t|";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tpush_back()\t|";
	std.push_back(1);
	print_vector(std);
	ft.push_back(1);
	std::cout << "|";
	print_vector(ft);
	std::cout << "|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tpop_back()\t|";
	std.pop_back();
	ft.pop_back();
	print_vector(std);
	std::cout << "\t|";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (1)\t|\t";
	std.assign(0, 0);
	ft.assign(0, 0);
	for (int i = 0; i < 5; i++)
	{
		std.push_back(i);
		ft.push_back(i);
	}
	std.insert(std.end(), 42);
	ft.insert(ft.end(), 42);
	print_vector(std);
	std::cout << "\t|\t";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (2)\t|";
	std.insert(std.begin() + 4, 3, 10);
	ft.insert(ft.begin() + 4, 3, 10);
	print_vector(std);
	std::cout << "\t|";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
	
	std::vector<int> std0;
	ft::vector<int> ft0;
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (3)\t|";
	std.assign(0, 0);
	ft.assign(0, 0);
	for (int i = 1; i < 5; i++)
	{
		std.push_back(i);
		ft.push_back(i);
	}
	ft0.resize(4);
	std0.resize(4);
	std0.insert(std0.begin() + 2, std.begin(), std.end());
	ft0.insert(ft0.begin() + 2, ft.begin(), ft.end());
	print_vector(std0);
	std::cout << "\t|";
	print_vector(ft0);
  	std::cout << "\t|";
	checkAttributs(ft0, std0);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tinsert() (3)\t|\t";
	std.insert(std.begin(), 2, 42);
	ft.insert(ft.begin(), 2, 42);
	print_vector(std);
	std::cout << "\t|\t";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\terase() (1)\t|\t";
	std.erase(std.begin() + 2);
	ft.erase(ft.begin() + 2);
	print_vector(std);
	std::cout << "\t|\t";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\terase() (2)\t|\t";
	std.erase(std.begin() + 2, std.end() - 1);
	ft.erase(ft.begin() + 2, ft.end() - 1);
	print_vector(std);
	std::cout << "\t|\t";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tswap()\t\t|\t";
	ft::vector<int> ftSwap(5, 8);
	std::vector<int> stdSwap(5, 8);
	ft.swap(ftSwap);
	std.swap(stdSwap);
	print_vector(std);
	std::cout << "\t|\t";
	print_vector(ft);
  	std::cout << "\t|";
	checkAttributs(ft, std);
	
	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tclear()\t\t|";
	std::vector<int> stdCpy(std);
	ft::vector<int> myCpy(ft);
	stdCpy.clear();
	myCpy.clear();
	print_vector(stdCpy);
	std::cout << "\t\t\t|\t\t\t";
	print_vector(stdCpy);
	std::cout << '|';
	checkAttributs(ft, std);
}

void    testVector(void)
{
	title("Vector");

	std::cout	<< "-------------------------------------------------------------------------" << std::endl
				<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
				<< "-------------------------------------------------------------------------" << std::endl;
	
	std::vector<int> stdVector;
	ft::vector<int> myVector;

	ft_capacity(stdVector, myVector);
	ft_iterators(stdVector, myVector);
	ft_elementAccess(stdVector, myVector);
	ft_modifiers(stdVector, myVector);
	
	std::cout << "-------------------------------------------------------------------------\n" << std::endl;
	
	ft::vector<int> vct(4);
	ft::vector<int> vct2(4);

	vct2.resize(10);
	std::vector<int> vct0(4);
	std::vector<int> vct1(4);

	vct1.resize(10);

	std::cout << "\n-------------------------------------------------------------------------" << std::endl
			<< "|\tOperators\t|" << "\tstd::stack\t|" << "\tft::stack\t|"  << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t[]\t\t|\t\t" << stdVector[1]
			<< "\t|\t\t" << myVector[1] << "\t|";
	compareOperators(stdVector[1], myVector[1]);
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t==\t\t|\t\t" << (vct1 == vct0)
			<< "\t|\t\t" << (vct == vct2) << "\t|";
	compareOperators((vct1 == vct0), (vct == vct2));
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t!=\t\t|\t\t" << (stdVector != vct1)
			<< "\t|\t\t" << (myVector != vct2) << "\t|";
	compareOperators((stdVector != vct1), (myVector != vct2));
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t<\t\t|\t\t" << (stdVector < vct1)
			<< "\t|\t\t" << (myVector < vct2) << "\t|";
	compareOperators((stdVector < vct1), (myVector < vct2));
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t<=\t\t|\t\t" << (stdVector <= vct1)
			<< "\t|\t\t" << (myVector <= vct2) << "\t|";
	compareOperators((stdVector <= vct1), (myVector <= vct2));
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t>\t\t|\t\t" << (stdVector > vct1)
			<< "\t|\t\t" << (myVector > vct2) << "\t|";
	compareOperators((stdVector > vct1), (myVector > vct2));
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t>=\t\t|\t\t" << (stdVector >= vct1)
			<< "\t|\t\t" << (myVector >= vct2) << "\t|";
	compareOperators((stdVector >= vct1), (myVector >= vct2));
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
			<< std::endl;
	
	swap(myVector, vct2);
	swap(stdVector, vct1);
	std::cout << "-- swap() --\nstd::vector\t:";
	print_vector(stdVector);
	std::cout << " -"; 
	print_vector(vct2);
	std::cout << "\nft::vector\t:";
	print_vector(myVector);
	std::cout << " -"; 
	print_vector(vct2);
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
