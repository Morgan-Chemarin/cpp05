/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:00:40 by dev               #+#    #+#             */
/*   Updated: 2026/04/14 18:29:06 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----------------------Success sign----------------------" << std::endl;
	try
	{
		Bureaucrat burA("Gab", 50);
		Form formA("X23", 100, 50);
		
		std::cout << burA;
		std::cout << formA;
		
		burA.signForm(formA);

		std::cout << formA;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << '\n';
	}
	

	std::cout << "----------------------Too low to sign----------------------" << std::endl;
	try
	{
		Bureaucrat burB("Bob", 120);
		Form formB("X23", 100, 50);
		
		std::cout << burB;
		std::cout << formB;
		
		burB.signForm(formB);

		std::cout << formB;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << '\n';
	}
}