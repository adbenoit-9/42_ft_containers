/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by adbenoit          #+#    #+#             */
/*   Updated: 2120/19/25 14:31:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

# include <iostream>
# include <string.h>

#if 1
    # define NAMESPACE "STD"
    # include <stack>
    # include <vector>
    # include <map>
    namespace ft = std;
#else
    # define NAMESPACE "FT"
    # include "../includes/ft.hpp"
#endif

void heading(std::string name);

#endif
