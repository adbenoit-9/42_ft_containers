/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:51:32 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/15 16:29:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include "../stack.hpp"
# include "../vector.hpp"
# include "../includes/Tree.hpp"
# include "../includes/pair.hpp"
# include "../map.hpp"
# include <stack>
# include <vector>
# include <map>
# include <iostream>
# include <iomanip>
# include <time.h> 

void    stackTests(void);
void    vectorTests(void);
void    mapTests(void);

void    title(std::string name);

template< class T, class T1 >
void checkAttributs(T &ft, T1 &std)
{
	for (size_t i = 0; i < ft.size() && i < std.size(); i++)
	{
		if (ft[i] != std[i])
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

template<typename T>
void	compareOperators(T std, T ft)
{
	if (std == ft)
		std::cout << " ✅" << std::endl;
	else
		std::cout << " ❌" << std::endl;
}

#endif
