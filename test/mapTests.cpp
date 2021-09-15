/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTests.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:53:15 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/15 17:42:51 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    mapTests(void)
{
	title("Map");
	
	ft::Tree<std::string,int> tree;
	std::map<std::string,int> stdMap;
	ft::map<std::string,int> ftMap;
	
	std::cout	<< "-------------------------------------------------------------------------" << std::endl
				<< "|\tMethodes\t|" << "\tstd::stack\t|" << "\tft::stack\t|" << std::endl
				<< "-------------------------------------------------------------------------" << std::endl;


	{
		for (int i = 0; i < 50; ++i) {
			std::string str(1, rand() % 40 + 48);
			ft::pair<const std::string, int>	val = ft::make_pair<const std::string, int>(str, 5);
			ftMap.insert(val);
		}
		std::cout << ftMap;
	}

	// {
	// 	for (int i = 0; i < 50; ++i) {
	// 		std::string str(1, rand() % 40 + 48);
	// 		ft::pair<const std::string, int>	val = ft::make_pair<const std::string, int>(str, 5);
	// 		tree.root = tree.insertNode(tree.root, val);
	// 	}
	// 	std::cout << tree;
	// }

	// {
	// 	for (int i = 0; i < 10; ++i) {
	// 		std::string str(1, rand() % 40 + 48);
	// 		tree.root = tree.deleteNode(tree.root, str);
	// 	}
	// 	std::cout << tree;
	// }
}
