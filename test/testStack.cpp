/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/09 00:22:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    testStack(void)
{
	std::cout << "\033[33;1m"
				<< "*************************************************************************" << std::endl
				<< "*                                  Stack                                *" << std::endl
				<< "*************************************************************************" << std::endl
				<< "\033[0m" << std::endl;

	std::stack<int, std::vector<int> > stdStack;
	ft::stack<int, ft::vector<int> > myStack;

	std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tempty()\t\t|\t\t" << stdStack.empty()
			<< "\t|\t\t" << myStack.empty() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\tsize()\t\t|\t\t" << stdStack.size()
			<< "\t|\t\t" << myStack.size() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		stdStack.push(i);
		myStack.push(i);
	}

	std::cout << "|  size() after push()  |\t\t" << stdStack.size()
			<< "\t|\t\t" << myStack.size() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\ttop()\t\t|\t\t" << stdStack.top()
			<< "\t|\t\t" << myStack.top() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl;

	stdStack.pop();
	myStack.pop();

	std::cout << "|  top() after pop()\t|\t\t" << stdStack.top()
			<< "\t|\t\t" << myStack.top() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl;

	ft::stack<int, ft::vector<int> > myCopy(myStack);
	std::stack<int, std::vector<int> > stdCopy(stdStack);
	
	std::cout << "|  size() of copy\t|\t\t" << stdCopy.size()
			<< "\t|\t\t" << myCopy.size() << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< std::endl;

std::cout << "-------------------------------------------------------------------------" << std::endl
			<< "|\tOperators\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t==\t\t|\t\t" << (stdStack == stdCopy)
			<< "\t|\t\t" << (myStack == myCopy) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t!=\t\t|\t\t" << (stdStack != stdCopy)
			<< "\t|\t\t" << (myStack != myCopy) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t<\t\t|\t\t" << (stdStack < stdCopy)
			<< "\t|\t\t" << (myStack < myCopy) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t<=\t\t|\t\t" << (stdStack <= stdCopy)
			<< "\t|\t\t" << (myStack <= myCopy) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t>\t\t|\t\t" << (stdStack > stdCopy)
			<< "\t|\t\t" << (myStack > myCopy) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< "|\t>=\t\t|\t\t" << (stdStack >= stdCopy)
			<< "\t|\t\t" << (myStack >= myCopy) << "\t|" << std::endl
			<< "-------------------------------------------------------------------------" << std::endl
			<< std::endl;
}
