/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/16 15:45:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    mapTests(void)
{
	title("Map");
	
	ft::Tree<std::string,int> tree;
	ft::Tree<std::string,int> tree2;
	std::map<std::string,int> stdMap;
	ft::map<std::string,int> ftMap;
	
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
				<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
				<< "-------------------------------------------------------------------------" << std::endl;


	{
		for (int i = 0; i < 50; ++i) {
			std::string str(1, rand() % 40 + 48);
			std::cout << "added : " << str << std::endl;
			ft::pair<const std::string, int>	val = ft::make_pair<const std::string, int>(str, i);
			ftMap.insert(val);
			
			std::cout << ftMap;
		}
	}

	// for (int i = 0; i < 50; ++i) {
	// 	std::string str(1, rand() % 40 + 48);
	// 	ft::pair<const std::string, int>	val = ft::make_pair<const std::string, int>(str, 5);
	// 	tree.root = tree.insertNode(tree.root, val);
	// }
	// tree2 = tree;
	// std::cout << tree2;

	{
		// for (int i = 0; i < 10; ++i) {
		// 	std::string str(1, rand() % 40 + 48);
		// 	tree.root = tree.deleteNode(tree.root, str);
		// }
	}
}
