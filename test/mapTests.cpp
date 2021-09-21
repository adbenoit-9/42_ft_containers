/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/21 19:58:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    mapTests(void)
{
	title("Map");
	
	std::map<std::string,int> stdMap;
	ft::map<std::string,int> ftMap;
	
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
				<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
				<< "-------------------------------------------------------------------------" << std::endl;


	for (int i = 48; i < 70; ++i) {
		std::string str(1, i);
		// std::cout << "added : " << str << std::endl;
		ft::pair<const std::string, int>	val = ft::make_pair<const std::string, int>(str, i);
		ftMap.insert(val);
		
	}
	for(ft::map<std::string,int>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;
	
	for (int i = 48; i < 70; ++i) {
		std::string str(1, i);
		// std::cout << "added : " << str << std::endl;
		std::pair<const std::string, int>	val = std::make_pair<const std::string, int>(str, i);
		stdMap.insert(val);
		
	}
	for(std::map<std::string,int>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;

	for (int i = 65; i < 70; ++i) {
		std::string str(1, i);
		ftMap.erase(str);
		stdMap.erase(str);
	}
	for(ft::map<std::string,int>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl;
	for(std::map<std::string,int>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	
	std::cout << (*ftMap.find("?")).second << " " << (*ftMap.find("ko")).second << std::endl;
	std::cout << (*stdMap.find("?")).second << " " << (*stdMap.find("ko")).second << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << ftMap.count("?") << " " << ftMap.count("ko") << std::endl;
	std::cout << stdMap.count("?") << " " << stdMap.count("ko") << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << (*ftMap.lower_bound("?")).first << std::endl;
	std::cout << (*stdMap.lower_bound("?")).first << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << (*ftMap.upper_bound("?")).first << std::endl;
	std::cout << (*stdMap.upper_bound("?")).first << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << (*ftMap.equal_range("5").first).first << " " << (*ftMap.equal_range("5").second).first << std::endl;
	std::cout << (*stdMap.equal_range("5").first).first << " " << (*stdMap.equal_range("5").second).first << std::endl;
	std::cout << (*ftMap.equal_range("50").first).first << " " << (*ftMap.equal_range("50").second).first << std::endl;
	std::cout << (*stdMap.equal_range("50").first).first << " " << (*stdMap.equal_range("50").second).first << std::endl;
	
	ft::map<std::string,int> ftcopy(ftMap.begin(), ftMap.end());
	std::map<std::string,int> stdcopy(stdMap.begin(), stdMap.end());
	std::cout << std::endl;
	for(ft::map<std::string,int>::iterator it = ftcopy.begin(); it != ftcopy.end(); it++)
		std::cout << " " << it->first;
	for(std::map<std::string,int>::iterator it = stdcopy.begin(); it != stdcopy.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	
	ftcopy.erase(ftcopy.begin(), ftcopy.end());
	for(ft::map<std::string,int>::iterator it = ftcopy.begin(); it != ftcopy.end(); it++)
		std::cout << " " << it->first;
	stdcopy.erase(stdcopy.begin(), stdcopy.end());
	for(std::map<std::string,int>::iterator it = stdcopy.begin(); it != stdcopy.end(); it++)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	ftcopy = ftMap;
	ft::map<std::string,int>::const_iterator cit(ftcopy.begin());
	std::map<std::string,int>::const_iterator cite(stdcopy.end());
	// cit->second = 1;
	for(ft::map<std::string,int>::iterator it = ftcopy.begin(); it != ftcopy.end(); it++)
		std::cout << " " << it->second;
	std::cout << std::endl << std::endl;
	ftcopy.erase(ftcopy.begin(), ftcopy.end());
	
	// ftcopy.erase(ftcopy.begin(), ftcopy.end());
	for(ft::map<std::string,int>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
	{
		ftcopy.insert(*it);
	}
	{
		ft::map<std::string, int> test = ftcopy;
		test.erase(ftcopy.begin(), ftcopy.end());
		test.clear();
		test.erase(ftcopy.begin(), ftcopy.end());
	}
	ftcopy.erase(ftcopy.begin(), ftcopy.end());
}
