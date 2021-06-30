/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/06/30 23:43:07 by adbenoit         ###   ########.fr       */
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

// std::cout << "-------------------------------------------------------------------------" << std::endl
// 			<< "|\tOperators\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
// 			<< "-------------------------------------------------------------------------" << std::endl
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
}
