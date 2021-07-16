/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:46:31 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/16 18:01:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test/test.hpp"

int main(void)
{
	std::cout << std::endl << "\033[34m"
	<< "███████ ████████       ██████  ██████  ███    ██ ████████  █████  ██ ███    ██ ███████ ██████  ███████" << std::endl
	<< "██         ██         ██      ██    ██ ████   ██    ██    ██   ██ ██ ████   ██ ██      ██   ██ ██     " << std::endl
	<< "█████      ██         ██      ██    ██ ██ ██  ██    ██    ███████ ██ ██ ██  ██ █████   ██████  ███████" << std::endl
	<< "██         ██         ██      ██    ██ ██  ██ ██    ██    ██   ██ ██ ██  ██ ██ ██      ██   ██      ██" << std::endl
	<< "██         ██ ███████  ██████  ██████  ██   ████    ██    ██   ██ ██ ██   ████ ███████ ██   ██ ███████" << std::endl
	<< "\033[0m" << std::endl << std::endl;
	
	std::cout << "(Press enter to continue ...) ";
	std::string input;
	std::getline(std::cin, input);

	vectorTests();
	std::cout << std::endl
				<< "(Press enter to continue ...) ";
	std::getline(std::cin, input);

	stackTests();
	std::cout << std::endl
				<< "(Press enter to continue ...) ";
	std::getline(std::cin, input);

	mapTests();
	return (0);
}
