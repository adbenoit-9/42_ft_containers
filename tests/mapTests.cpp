/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/23 04:19:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template< class T, class T1 >
void checkMap(T &ftM, T1 &stdM)
{
	typename T1::iterator sit = stdM.begin();
	for (typename T::iterator it = ftM.begin(); it != ftM.end() && sit != stdM.end(); it++, sit++)
	{
		if (it->first != sit->first && it->second != sit->second)
		{
			std::cout	<< "❌";
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
	// #0
	for (int i = 0; i < 5; i++)
	{
		std::pair<int,int> val1 = std::make_pair(i, i);
		ft::pair<int,int> val2 = ft::make_pair(i, i);
		stdM.insert(val1);
		ftM.insert(val2);
	}
	checkMap(ftM, stdM);

  	std::cout << std::endl;

				/* ERASE */
	std::cout << "erase()\t\t⬜";
	// #0
	stdM.erase(stdM.begin()++);
	ftM.erase(ftM.begin()++);
	checkMap(ftM, stdM);
	// #1
	stdM.erase(3);
	ftM.erase(3);
	checkMap(ftM, stdM);
	// #1
	stdM.erase(stdM.begin(), stdM.end());
	ftM.erase(ftM.begin(), ftM.end());
	checkMap(ftM, stdM);
  	std::cout << std::endl;
	
				/* SWAP */
	for (int i = 0; i < 5; i++)
	{
		std::pair<int,int> val1 = std::make_pair(i, i);
		ft::pair<int,int> val2 = ft::make_pair(i, i);
		stdM.insert(val1);
		ftM.insert(val2);
	}
	std::cout << "swap()\t\t⬜";
	T1 ftSwap;
	T stdSwap;
	ftSwap.insert(ftM.begin()++, ftM.end());
	stdSwap.insert(stdM.begin()++, stdM.end());
	ftM.swap(ftSwap);
	stdM.swap(stdSwap);
	checkMap(ftM, stdM); // #0
  	std::cout << std::endl;
	
				/* CLEAR */
	std::cout << "clear()\t\t⬜";
	ftSwap.clear();
	stdSwap.clear();
	checkMap(ftM, stdM); // #0
  	std::cout << std::endl;
}

void    mapTests(void)
{
	title("Map");
	
	std::cout << "Test n˚\t\t⬜0️⃣ 1️⃣ 2️⃣ 3️⃣ 4️⃣ 5️⃣ 6️⃣ 7️⃣ 8️⃣ 9️⃣ 🔟\n" 
			<< "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜"<< std::endl;
			
	std::map<int,int> stdMap;
	ft::map<int,int> ftMap;

	for (int i = 0; i < 6; ++i) {
		ft::pair<int, int>	val = ft::make_pair(i, i);
		ftMap.insert(val);
	}
	for (int i = 0; i < 6; ++i) {
		std::pair<int, int>	val = std::make_pair(i, i);
		stdMap.insert(val);
	}
	
	checkIterators(stdMap, ftMap);
	checkModifiers(stdMap, ftMap);
	
		
	// for(std::map<std::string,int>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
	// 	std::cout << " " << it->first;
	// std::cout << std::endl;

	// for (int i = 65; i < 70; ++i) {
	// 	std::string str(1, i);
	// 	ftMap.erase(str);
	// 	stdMap.erase(str);
	// }
	// for(ft::map<std::string,int>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
	// 	std::cout << " " << it->first;
	// std::cout << std::endl;
	// for(std::map<std::string,int>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
	// 	std::cout << " " << it->first;
	// std::cout << std::endl << std::endl;
	
	// std::cout << (*ftMap.find("?")).second << " " << (*ftMap.find("ko")).second << std::endl;
	// std::cout << (*stdMap.find("?")).second << " " << (*stdMap.find("ko")).second << std::endl;
	// std::cout << std::endl << std::endl;
	// std::cout << ftMap.count("?") << " " << ftMap.count("ko") << std::endl;
	// std::cout << stdMap.count("?") << " " << stdMap.count("ko") << std::endl;
	// std::cout << std::endl << std::endl;
	// std::cout << (*ftMap.lower_bound("?")).first << std::endl;
	// std::cout << (*stdMap.lower_bound("?")).first << std::endl;
	// std::cout << std::endl << std::endl;
	// std::cout << (*ftMap.upper_bound("?")).first << std::endl;
	// std::cout << (*stdMap.upper_bound("?")).first << std::endl;
	// std::cout << std::endl << std::endl;
	// std::cout << (*ftMap.equal_range("5").first).first << " " << (*ftMap.equal_range("5").second).first << std::endl;
	// std::cout << (*stdMap.equal_range("5").first).first << " " << (*stdMap.equal_range("5").second).first << std::endl;
	// std::cout << (*ftMap.equal_range("50").first).first << " " << (*ftMap.equal_range("50").second).first << std::endl;
	// std::cout << (*stdMap.equal_range("50").first).first << " " << (*stdMap.equal_range("50").second).first << std::endl;
	
	// ft::map<std::string,int> ftcopy(ftMap.begin(), ftMap.end());
	// std::map<std::string,int> stdcopy(stdMap.begin(), stdMap.end());
	// std::cout << std::endl;
	// for(ft::map<std::string,int>::iterator it = ftcopy.begin(); it != ftcopy.end(); it++)
	// 	std::cout << " " << it->first;
	// for(std::map<std::string,int>::iterator it = stdcopy.begin(); it != stdcopy.end(); it++)
	// 	std::cout << " " << it->first;
	// std::cout << std::endl << std::endl;
	
	// ftcopy.erase(ftcopy.begin(), ftcopy.end());
	// for(ft::map<std::string,int>::iterator it = ftcopy.begin(); it != ftcopy.end(); it++)
	// 	std::cout << " " << it->first;
	// stdcopy.erase(stdcopy.begin(), stdcopy.end());
	// for(std::map<std::string,int>::iterator it = stdcopy.begin(); it != stdcopy.end(); it++)
	// 	std::cout << " " << it->first;
	// std::cout << std::endl << std::endl;
	// ftcopy = ftMap;
	// ft::map<std::string,int>::const_iterator cit(ftcopy.begin());
	// std::map<std::string,int>::const_iterator cite(stdcopy.end());
	// // cit->second = 1;
	// for(ft::map<std::string,int>::iterator it = ftcopy.begin(); it != ftcopy.end(); it++)
	// 	std::cout << " " << it->second;
	// std::cout << std::endl << std::endl;
	// ftcopy.erase(ftcopy.begin(), ftcopy.end());
	
	// // ftcopy.erase(ftcopy.begin(), ftcopy.end());
	// for(ft::map<std::string,int>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
	// {
	// 	ftcopy.insert(*it);
	// }
	// {
	// 	ft::map<std::string, int> test = ftcopy;
	// 	test.erase(ftcopy.begin(), ftcopy.end());
	// 	test.clear();
	// 	test.erase(ftcopy.begin(), ftcopy.end());
	// }
	// ftcopy.erase(ftcopy.begin(), ftcopy.end());
}
