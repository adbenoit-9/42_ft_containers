/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:51:32 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/22 15:32:06 by adbenoit         ###   ########.fr       */
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

void		drawTree(TREE::Node* root);

template< class T, class T1 >
void checkAttributs(T &ft, T1 &std)
{
	typename T1::iterator sit = std.begin();
	for (typename T::iterator it = ft.begin(); it != ft.end() && sit != std.end(); it++, sit++)
	{
		if (*it != *sit)
		{
			std::cout	<< " ❌ : " << "vectors != " << std::endl;
			return ;
		}
	}
	if (ft.size() != std.size())
		std::cout << " ❌ : " << "size " << std.size() << " - " << ft.size()<< "\t|";
	else if (ft.max_size() != std.max_size())
		std::cout << " ❌ : " << "max_size " << std.max_size() << " - " << ft.max_size()<< "\t|";
	else
		std::cout << " ✅";
	std::cout << std::endl;
}

template< class T, class T1 >
void checkMapAttributs(T &ft, T1 &std)
{
	typename T1::iterator sit = std.begin();
	for (typename T::iterator it = ft.begin(); it != ft.end() && sit != std.end(); it++, sit++)
	{
		if (it->first != sit->first && it->second != sit->second)
		{
			std::cout	<< " ❌ : " << "maps != " << std::endl;
			return ;
		}
	}
	if (ft.size() != std.size())
		std::cout << " ❌ : " << "size " << std.size() << " - " << ft.size()<< "\t|";
	// else if (ft.max_size() != std.max_size())
	// 	std::cout << " ❌ : " << "max_size " << std.max_size() << " - " << ft.max_size()<< "\t|";
	else
		std::cout << " ✅";
	std::cout << std::endl;
}

template<typename T>
void	compareOperators(T std, T ft)
{
	if (std == ft)
		std::cout << " ✅" << std::endl;
	else
		std::cout << " ❌" << std::endl;
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
