/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/07 19:54:23 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

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

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tsize()\t\t|\t\t" << stdVector.size()
			<< "\t|\t\t" << myVector.size() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tmax_size()\t|  " << stdVector.max_size()
			<< "\t|  " << myVector.max_size() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl;

	stdVector.reserve(6);
	myVector.reserve(6);

	std::cout << "|\tcapacity()\t|\t\t" << stdVector.capacity()
			<< "\t|\t\t" << myVector.capacity() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tempty()\t\t|\t\t" << stdVector.empty()
			<< "\t|\t\t" << myVector.empty() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
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
  	std::cout << "\t\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|    rbegin() + rend()\t|\t";

	std::vector<int>::reverse_iterator rit = stdVector.rbegin();

	i = 0;
	for (rit = stdVector.rbegin(); rit != stdVector.rend(); ++rit)
		*rit = ++i;

	for (std::vector<int>::iterator it = stdVector.begin(); it != stdVector.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << "\t\t|\t";

	ft::vector<int>::reverse_iterator rit1 = myVector.rbegin();

	i = 0;
	for (rit1 = myVector.rbegin(); rit1 != myVector.rend(); ++rit1)
		*rit1 = ++i;

	for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << "\t\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t\tat()\t|\t";

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
  	std::cout << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t\tfront()\t|\t\t" << stdVector.front() << "\t|\t\t" << myVector.front()
			<< "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t\tback()\t|\t\t" << stdVector.back() << "\t|\t\t" << myVector.back()
			<< "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tassign()\t|";

	stdVector.assign(1, 9);
	myVector.assign(1, 9);
	for (std::vector<int>::iterator it = stdVector.begin(); it != stdVector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\t|";
	for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tassign()\t|";

	ft::vector<int> toCopy(7, 42);
	stdVector.assign(toCopy.begin(), toCopy.end());
	myVector.assign(toCopy.begin(), toCopy.end());
	for (std::vector<int>::iterator it = stdVector.begin(); it != stdVector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\t|";
	for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		std::cout << ' ' << *it;

  	std::cout << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		stdVector.push(i);
// 		myVector.push(i);
// 	}

// 	std::cout << "|  size() after push()  |\t\t" << stdVector.size()
// 			<< "\t|\t\t" << myVector.size() << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\ttop()\t\t|\t\t" << stdVector.top()
// 			<< "\t|\t\t" << myVector.top() << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl;

// 	stdVector.pop();
// 	myVector.pop();

// 	std::cout << "|  top() after pop()\t|\t\t" << stdVector.top()
// 			<< "\t|\t\t" << myVector.top() << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl;

// 	ft::stack<int, std::vector<int> > myCopy(myVector);
// 	std::stack<int, std::vector<int> > stdCopy(stdVector);
	
// 	std::cout << "|  size() of copy\t|\t\t" << stdCopy.size()
// 			<< "\t|\t\t" << myCopy.size() << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< std::endl;

std::cout << "\n-------------------------------------------------------------------------" << std::endl
			<< "|\tOperators\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t[]\t\t|\t\t" << stdVector[1]
			<< "\t|\t\t" << myVector[1] << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\t==\t\t|\t\t" << (stdVector == stdCopy)
// 			<< "\t|\t\t" << (myVector == myCopy) << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\t!=\t\t|\t\t" << (stdVector != stdCopy)
// 			<< "\t|\t\t" << (myVector != myCopy) << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\t<\t\t|\t\t" << (stdVector < stdCopy)
// 			<< "\t|\t\t" << (myVector < myCopy) << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\t<=\t\t|\t\t" << (stdVector <= stdCopy)
// 			<< "\t|\t\t" << (myVector <= myCopy) << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\t>\t\t|\t\t" << (stdVector > stdCopy)
// 			<< "\t|\t\t" << (myVector > myCopy) << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< "|\t>=\t\t|\t\t" << (stdVector >= stdCopy)
// 			<< "\t|\t\t" << (myVector >= myCopy) << "\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
// 			<< std::endl;
			;
}
