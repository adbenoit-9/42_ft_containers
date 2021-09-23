/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:51:32 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/23 04:02:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include "../includes/ft.hpp"
# include <stack>
# include <vector>
# include <map>
# include <iostream>
# include <iomanip>
# include <time.h> 

# define TREE ft::Tree< ft::pair<const std::string, int> >
# define VECT ft::vector<ft::pair<std::string, int> >

void    stackTests(void);
void    vectorTests(void);
void    mapTests(void);

void    title(std::string name);
void	drawTree(TREE::Node* root);

template<class T>
void	compareRet(T stdRet, T ftRet)
{
	if (stdRet == ftRet)
		std::cout << "✅";
	else
		std::cout << "❌";
}

template<typename T>
void	print_vector(T &c)
{
	for (typename T::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << ' ' << *it;
}
template<typename T>
void	print_map(T &c)
{
	for (typename T::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " (" << it->first << ", " << it->second << ")";

}

#endif
