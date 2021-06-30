/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:46:31 by adbenoit          #+#    #+#             */
/*   Updated: 2021/06/30 16:46:40 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test/test.hpp"

int main(void)
{
	std::cout << "\033[34m"
	<< "███████ ████████       ██████  ██████  ███    ██ ████████  █████  ██ ███    ██ ███████ ██████  ███████     ████████ ███████ ███████ ████████ ███████ " << std::endl
	<< "██         ██         ██      ██    ██ ████   ██    ██    ██   ██ ██ ████   ██ ██      ██   ██ ██             ██    ██      ██         ██    ██      " << std::endl
	<< "█████      ██         ██      ██    ██ ██ ██  ██    ██    ███████ ██ ██ ██  ██ █████   ██████  ███████        ██    █████   ███████    ██    ███████ " << std::endl
	<< "██         ██         ██      ██    ██ ██  ██ ██    ██    ██   ██ ██ ██  ██ ██ ██      ██   ██      ██        ██    ██           ██    ██         ██ " << std::endl
	<< "██         ██ ███████  ██████  ██████  ██   ████    ██    ██   ██ ██ ██   ████ ███████ ██   ██ ███████        ██    ███████ ███████    ██    ███████ " << std::endl
	<< "\033[0m" << std::endl << std::endl;
	
	testStack();
	return (0);
}
