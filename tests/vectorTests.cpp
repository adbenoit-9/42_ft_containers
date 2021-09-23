/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/23 03:28:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template< class T, class T1 >
void	checkVector(T &ftV, T1 &stdV)
{
	typename T1::iterator sit = stdV.begin();
	for (typename T::iterator it = ftV.begin(); it != ftV.end() && sit != stdV.end(); it++, sit++)
	{
		if (*it != *sit)
		{
			std::cout	<< "❌";
			return ;
		}
	}
	if (ftV.size() != stdV.size() || ftV.max_size() != stdV.max_size())
		std::cout << "❌";
	else
		std::cout << "✅";
}

template< class T, class T1 >
void	checkCapacity(T &stdV, T1 &ftV)
{
				/* SIZE */
	std::cout	<< "size()\t\t⬜";
	// #0
	stdV.resize(3, 42);
	ftV.resize(3, 42);
	checkVector(ftV, stdV);
	// #1
	stdV.reserve(6);
	ftV.reserve(6);
	checkVector(ftV, stdV);
	std::cout << std::endl;
	
				/* MAX_SIZE */
	std::cout	<< "max_size()\t⬜";
	// #0
	stdV.resize(3, 41);
	ftV.resize(3, 42);
	checkVector(ftV, stdV);
	// #1
	stdV.reserve(6);
	ftV.reserve(6);
	checkVector(ftV, stdV);
	std::cout << std::endl;
	
				/* CAPACITY */
	std::cout	<< "capacity()\t⬜";
	// #0
	stdV.resize(3, 42);
	ftV.resize(3, 42);
	checkVector(ftV, stdV);
	// #1
	stdV.reserve(6);
	ftV.reserve(6);
	checkVector(ftV, stdV);
	std::cout << std::endl;
}

template< class T, class T1 >
void	checkIterators(T &stdV, T1 &ftV)
{
				/* ITERATOR */
	std::cout << "iterator\t⬜";
	// #0
	int i = 0;
	for (std::vector<int>::iterator it = stdV.begin() ; it != stdV.end(); ++it)
		*it = ++i;
	i = 0;
	for (ft::vector<int>::iterator it = ftV.begin() ; it != ftV.end(); ++it)
		*it = ++i;
	checkVector(ftV, stdV);
  	std::cout << std::endl;
	
				/* CONST ITERATOR */
	const ft::vector<int> v(10, 42);
	const std::vector<int> v1(10, 42);
	for (std::vector<int>::const_iterator it = v1.begin(); it != v1.end(); ++it)
		*it;
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		*it;
	ft::vector<int> v2(1, 1);
	ft::vector<int>::const_iterator it = v2.begin();

				/* REVERSE ITERATOR */
	std::cout << "rev_it\t\t⬜";
	// #0
	std::vector<int>::reverse_iterator rit = stdV.rbegin();
	i = 0;
	for (rit = stdV.rbegin(); rit != stdV.rend(); ++rit)
		*rit = ++i;
	ft::vector<int>::reverse_iterator rit1 = ftV.rbegin();
	i = 0;
	for (rit1 = ftV.rbegin(); rit1 != ftV.rend(); ++rit1)
		*rit1 = ++i;
	checkVector(ftV, stdV);
  	std::cout << std::endl;
}

template< class T, class T1 >
void	checkElementAccess(T &stdV, T1 &ftV)
{
				/* AT */
	std::cout << "at()\t\t⬜";
	compareRet(ftV.at(1), stdV.at(1)); // #0
	typename T::value_type ret1 = 0;
	typename T1::value_type ret2 = 0;
	try
	{
		ret1 = ftV.at(6);
		ret2 = stdV.at(6);
	}
	catch(const std::exception& e) {}
	compareRet(ret1, ret2); // #1
	
  	std::cout << std::endl;
	
				/* FRONT */
	std::cout << "front()\t\t⬜";
	compareRet(ftV.front(), stdV.front()); // #0
	ftV.erase(ftV.begin());
	stdV.erase(stdV.begin());
	compareRet(ftV.front(), stdV.front()); // #1
  	std::cout << std::endl;
	
				/* BACK */
	std::cout << "back()\t\t⬜";
	compareRet(ftV.back(), stdV.back()); // #0
	ftV.push_back(ret1);
	stdV.push_back(ret2);
	compareRet(ftV.back(), stdV.back()); // #1
  	std::cout << std::endl;
	
}

template< class T, class T1 >
void	checkModifiers(T &stdV, T1 &ftV)
{	
				/* ASSIGN */
	std::cout << "assign()\t⬜";
	stdV.assign(0, 9);
	ftV.assign(0, 9);
	checkVector(ftV, stdV); // #0
	stdV.assign(1, 9);
	ftV.assign(1, 9);
	checkVector(ftV, stdV); // #1
	
	ft::vector<int> toCopy(7, 42);
	std::vector<int> toCopy0(7, 42);
	stdV.assign(toCopy0.begin(), toCopy0.end());
	ftV.assign(toCopy.begin(), toCopy.end());
	checkVector(ftV, stdV); // #2
  	std::cout << std::endl;
	
				/* PUSH_BACK */
	std::cout << "push_back()\t⬜";
	stdV.push_back(1);
	ftV.push_back(1);
	checkVector(ftV, stdV); // #0
  	std::cout << std::endl;
	
				/* POP_BACK */
	std::cout << "pop_back()\t⬜";
	stdV.pop_back();
	ftV.pop_back();
	checkVector(ftV, stdV); // #0
  	std::cout << std::endl;

				/* INSERT */
	std::cout << "insert()\t⬜";
	// #0
	stdV.assign(0, 0);
	ftV.assign(0, 0);
	for (int i = 0; i < 5; i++)
	{
		stdV.push_back(i);
		ftV.push_back(i);
	}
	stdV.insert(stdV.end(), 42);
	ftV.insert(ftV.end(), 42);
	checkVector(ftV, stdV);
	// #1
	stdV.insert(stdV.begin() + 4, 3, 10);
	ftV.insert(ftV.begin() + 4, 3, 10);
	checkVector(ftV, stdV);
	// #2
	std::vector<int> std0;
	ft::vector<int> ftV0;
	stdV.assign(0, 0);
	ftV.assign(0, 0);
	for (int i = 1; i < 5; i++)
	{
		stdV.push_back(i);
		ftV.push_back(i);
	}
	ftV0.resize(4);
	std0.resize(4);
	std0.insert(std0.begin() + 2, stdV.begin(), stdV.end());
	ftV0.insert(ftV0.begin() + 2, ftV.begin(), ftV.end());
	checkVector(ftV0, std0);
	// #3
	stdV.insert(stdV.begin(), 2, 42);
	ftV.insert(ftV.begin(), 2, 42);
	checkVector(ftV, stdV);
  	std::cout << std::endl;

				/* ERASE */
	std::cout << "erase()\t\t⬜";
	// #0
	stdV.erase(stdV.begin() + 2);
	ftV.erase(ftV.begin() + 2);
	checkVector(ftV, stdV);
	// #1
	stdV.erase(stdV.begin() + 2, stdV.end() - 1);
	ftV.erase(ftV.begin() + 2, ftV.end() - 1);
	checkVector(ftV, stdV);
  	std::cout << std::endl;
	
				/* SWAP */
	std::cout << "swap()\t\t⬜";
	ft::vector<int> ftVSwap(5, 8);
	std::vector<int> stdSwap(5, 8);
	ftV.swap(ftVSwap);
	stdV.swap(stdSwap);
	checkVector(ftV, stdV); // #0
  	std::cout << std::endl;
	
				/* CLEAR */
	std::cout << "clear()\t\t⬜";
	std::vector<int> stdCpy(stdV);
	ft::vector<int> myCpy(ftV);
	stdCpy.clear();
	myCpy.clear();
	checkVector(ftV, stdV); // #0
  	std::cout << std::endl;
}

template<class T, class T1>
void	checkOperators(T stdVect, T1 ftVect)
{
	std::cout << "operators\t⬜";
	
	T stdCopy(stdVect);
	T1 ftCopy(ftVect);
	compareRet((stdVect == stdCopy), (ftVect == ftCopy)); // #0
	compareRet((stdVect != stdCopy), (ftVect != ftCopy)); // #1
	compareRet((stdVect < stdCopy), (ftVect < ftCopy)); // #2
	compareRet((stdVect <= stdCopy), (ftVect <= ftCopy)); // #3
	compareRet((stdVect > stdCopy), (ftVect > ftCopy)); // #4
	compareRet((stdVect >= stdCopy), (ftVect >= ftCopy)); // #5
	
	stdCopy.erase(stdCopy.begin());
	ftCopy.erase(ftCopy.begin());
	compareRet((stdVect == stdCopy), (ftVect == ftCopy)); // #6
	compareRet((stdVect != stdCopy), (ftVect != ftCopy)); // #7
	compareRet((stdVect < stdCopy), (ftVect < ftCopy)); // #8
	compareRet((stdVect <= stdCopy), (ftVect <= ftCopy)); // #9
	compareRet((stdVect > stdCopy), (ftVect > ftCopy)); // #10
	compareRet((stdVect >= stdCopy), (ftVect >= ftCopy)); // #11
	compareRet(stdVect[1], ftVect[1]); //#12
}

void    vectorTests(void)
{
	title("Vector");
	std::cout << "Test n˚\t\t⬜0️⃣ 1️⃣ 2️⃣ 3️⃣ 4️⃣ 5️⃣ 6️⃣ 7️⃣ 8️⃣ 9️⃣ 🔟\n" 
			<< "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<< std::endl;
	
			/* MEMBER FUNCTIONS */
	std::vector<int> stdVect;
	ft::vector<int> ftVect;

	checkCapacity(stdVect, ftVect);
	checkIterators(stdVect, ftVect);
	checkElementAccess(stdVect, ftVect);
	checkModifiers(stdVect, ftVect);
	
	stdVect.insert(stdVect.end(), 42);
	ftVect.insert(ftVect.end(), 42);
	checkOperators(stdVect, ftVect);
	std::cout << std::endl;
	
			/* NON-MEMBER FUNCTION */
	// SWAP
	std::cout	<< "\033[2mnon_member funtion\033[0m\n"
				<< "swap()\t\t⬜";
	ft::vector<int> vct2(4);
	std::vector<int> vct1(4);
	vct2.resize(10);
	vct1.resize(10);
	swap(ftVect, vct2);
	swap(stdVect, vct1);
	checkVector(ftVect, stdVect); // #0
	checkVector(vct2, vct1); // #1
	std::cout << std::endl;
	
}
