/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/23 21:23:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template< class T, class T1 >
void checkMap(const T &ftM, const T1 &stdM)
{
	typename T1::const_iterator sit = stdM.begin();
	for (typename T::const_iterator it = ftM.begin(); it != ftM.end() && sit != stdM.end(); it++, sit++)
	{
		if (it->first != sit->first || it->second != sit->second)
		{
			std::cout	<< "❌" << it->first << "|" << sit->first;
			return ;
		}
	}
	if (ftM.size() != stdM.size())
		std::cout << "❌";
	else
		std::cout << "✅";
}

template< class T, class T1 >
void	checkIterators(T &stdM, T1 &ftM)
{
	T stdTmp;
	T1 ftTmp;
					/* ITERATOR */
	std::cout << "iterator\t⬜";
	// #0
	for (typename T1::iterator it = ftM.begin() ; it != ftM.end(); ++it)
		ftTmp.insert(*it);
	for (typename T::iterator it = stdM.begin() ; it != stdM.end(); ++it)
		stdTmp.insert(*it);
	checkMap(ftM, stdM);
  	std::cout << std::endl;
	
	stdTmp.clear();
	ftTmp.clear();
			/* REVERSE ITERATOR */
	std::cout << "rev_it\t\t⬜";
	// #0
	for (typename T1::reverse_iterator rit = ftTmp.rbegin(); rit != ftTmp.rend(); ++rit)
		ftTmp.insert(*rit.base());
	for (typename T::reverse_iterator rit = stdTmp.rbegin(); rit != stdTmp.rend(); ++rit)
		stdTmp.insert(*rit.base());
	checkMap(ftTmp, stdTmp);
  	std::cout << std::endl;
}


template< class T, class T1 >
void	checkModifiers(T &stdM, T1 &ftM)
{
				/* INSERT */
	std::cout << "insert()\t⬜";
	T stdTmp;
	T1 ftTmp;
	std::pair<typename T::iterator,bool> ret1;
	ft::pair<typename T1::iterator,bool> ret2;
	for (int i = 6; i < 10; i++)
	{
		std::pair<int,int> val1 = std::make_pair(i, i);
		ft::pair<int,int> val2 = ft::make_pair(i, i);
		ret1 = stdTmp.insert(val1);
		ret2 = ftTmp.insert(val2);
	}
	compareRet(ret1.first->first, ret2.first->first); // #0
	compareRet(ret1.second, ret2.second); // #1
	checkMap(ftTmp, stdTmp); // #2
	stdM.insert(stdTmp.begin(), stdTmp.end());
	ftM.insert(ftTmp.begin(), ftTmp.end());
	checkMap(ftM, stdM); //#3
	T stdTmp1;
	T1 ftTmp2;
	stdM.insert(stdTmp1.begin(), stdTmp1.end());
	ftM.insert(ftTmp2.begin(), ftTmp2.end());
	checkMap(ftM, stdM); // #4
	{
		std::pair<int,int> val1 = std::make_pair(-15, 42);
		ft::pair<int,int> val2 = ft::make_pair(-15, 42);
		stdTmp.insert(val1);
		ftTmp.insert(val2);
	}
	stdM.insert(stdTmp.begin(), stdTmp.begin());
	ftM.insert(ftTmp.begin(), ftTmp.begin());
	checkMap(ftM, stdM); // #5
	stdM.insert(stdTmp.begin(), ++stdTmp.begin());
	ftM.insert(ftTmp.begin(), ++ftTmp.begin());
	checkMap(ftM, stdM); // #6
	{
		std::pair<int,int> val1 = std::make_pair(-42, 42);
		ft::pair<int,int> val2 = ft::make_pair(-42, 42);
		stdTmp.insert(val1);
		ftTmp.insert(val2);
	}
	stdM.insert(stdM.begin(), *stdTmp.begin());
	ftM.insert(ftM.begin(), *ftTmp.begin());
	checkMap(ftM, stdM); // #7
	ret1.first = stdM.insert(stdTmp.begin(), *stdTmp.begin());
	ret2.first = ftM.insert(ftTmp.begin(), *ftTmp.begin());
	compareRet(ret1.first->first, ret2.first->first); // #8
	checkMap(ftM, stdM); // #9
	{
		std::pair<int,int> val1 = std::make_pair(-52, 42);
		ft::pair<int,int> val2 = ft::make_pair(-52, 42);
		stdTmp.insert(val1);
		ftTmp.insert(val2);
	}
	stdM.insert(stdM.begin(), *stdTmp.begin());
	ftM.insert(ftM.begin(), *ftTmp.begin());
	checkMap(ftM, stdM); // #10
  	std::cout << std::endl;

				/* ERASE */
	std::cout << "erase()\t\t⬜";
	stdM.erase(stdM.begin());
	ftM.erase(ftM.begin());
	checkMap(ftM, stdM); // #0
	stdM.erase(stdM.begin()++);
	ftM.erase(ftM.begin()++);
	checkMap(ftM, stdM); // #1
	size_t ret3 = stdM.erase(3);
	size_t ret4 = ftM.erase(3);
	compareRet(ret3, ret4); // #2
	checkMap(ftM, stdM); // #3
	ret3 = stdM.erase(404);
	ret4 = ftM.erase(404);
	compareRet(ret3, ret4); // #4
	checkMap(ftM, stdM); // #5
	stdM.erase(stdM.begin(), stdM.end());
	ftM.erase(ftM.begin(), ftM.end());
	checkMap(ftM, stdM); // #6
	stdM.erase(stdM.begin(), stdM.begin());
	ftM.erase(ftM.begin(), ftM.begin());
	checkMap(ftM, stdM); // #7
  	std::cout << std::endl;
	
				/* SWAP */
	std::cout << "swap()\t\t⬜";
	for (int i = 0; i < 5; i++)
	{
		std::pair<int,int> val1 = std::make_pair(i, i);
		ft::pair<int,int> val2 = ft::make_pair(i, i);
		stdM.insert(val1);
		ftM.insert(val2);
	}
	T1 ftSwap;
	T stdSwap;
	ftM.swap(ftSwap);
	stdM.swap(stdSwap);
	checkMap(ftM, stdM); // #0
	ftM.insert(ftSwap.begin()++, ftSwap.end());
	stdM.insert(stdSwap.begin()++, stdSwap.end());
	ftM.swap(ftSwap);
	stdM.swap(stdSwap);
	checkMap(ftM, stdM); // #1
  	std::cout << std::endl;
	
				/* CLEAR */
	std::cout << "clear()\t\t⬜";
	ftSwap.clear();
	stdSwap.clear();
	checkMap(ftM, stdM); // #0
	ftTmp.clear();
	stdTmp.clear();
	checkMap(ftM, stdM); // #1
	T1 ftemp;
	T stdemp;
	ftemp.clear();
	stdemp.clear();
	checkMap(ftM, stdM); // #2
  	std::cout << std::endl;
}

template<class T, class T1>
void	checkOperators(const T& stdM, const T1& ftM)
{
				/* FIND */
	std::cout << "find()\t\t⬜";
	compareRet((ftM.find(0))->first, (stdM.find(0))->first); // #0
	compareRet((ftM.find(4))->first, (stdM.find(4))->first); // #1
	compareRet((ftM.find(2))->first, (stdM.find(2))->first); // #2
	std::cout << std::endl;
	
	// 			/* COUNT */
	std::cout << "count()\t\t⬜";
	compareRet(ftM.count(2), stdM.count(2)); // #0
	compareRet(ftM.count(404), stdM.count(404)); // #1
	compareRet(ftM.count(0), stdM.count(0)); // #2
	compareRet(ftM.count(4), stdM.count(4)); // #3
	std::cout << std::endl;
	
				/* LOWER_BOUND */
	std::cout << "lower_bound()\t⬜";
	compareRet((ftM.lower_bound(0))->first, (stdM.lower_bound(0))->first); // #0
	compareRet((ftM.lower_bound(2))->first, (stdM.lower_bound(2))->first); // #1
	compareRet((ftM.lower_bound(4))->first, (stdM.lower_bound(4))->first); // #2
	std::cout << std::endl;
	
				/* UPPER_BOUND */
	std::cout << "upper_bound()\t⬜";
	compareRet((ftM.upper_bound(0))->first, (stdM.upper_bound(0))->first); // #0
	compareRet((ftM.upper_bound(3))->first, (stdM.upper_bound(3))->first); // #1
	std::cout << std::endl;
	
				/* EQUAL_RANGE */
	std::cout << "equal_range()\t⬜";
	compareRet((ftM.equal_range(0)).first->first, (stdM.equal_range(0)).first->first); // #0
	compareRet((ftM.equal_range(2)).first->first, (stdM.equal_range(2)).first->first); // #1
	compareRet((ftM.equal_range(4)).first->first, (stdM.equal_range(4)).first->first); // #2
	std::cout << std::endl;
}

void    mapTests(void)
{
	title("Map");
	
	std::cout << "Test n˚\t\t⬜0️⃣ 1️⃣ 2️⃣ 3️⃣ 4️⃣ 5️⃣ 6️⃣ 7️⃣ 8️⃣ 9️⃣ 🔟\n" 
			<< "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<< std::endl;
			
	std::map<int,int> stdM;
	ft::map<int,int> ftM;

	for (int i = 0; i < 6; ++i) {
		ft::pair<int, int>	val = ft::make_pair(i, i);
		ftM.insert(val);
	}
	for (int i = 0; i < 6; ++i) {
		std::pair<int, int>	val = std::make_pair(i, i);
		stdM.insert(val);
	}
	
	checkIterators(stdM, ftM);
	checkModifiers(stdM, ftM);
	checkOperators(stdM, ftM);
	
				/* OPERATOR [] */
	std::cout << "operator []\t⬜";
	compareRet(stdM[1], ftM[1]); // #0
	compareRet(stdM[404], ftM[404]); // #1
	stdM[404] = 0;
	ftM[404] = 0;
	compareRet(stdM[404], ftM[404]); // #2
	std::cout << std::endl;
	
				/* CONST MAP */
	std::cout	<< "\033[2mconst map\033[0m\n";
	const std::map<int,int> stdConst(stdM);
	const ft::map<int,int> ftConst(ftM);
	checkOperators(stdConst, ftConst);
}
