/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:00:40 by dev               #+#    #+#             */
/*   Updated: 2026/04/17 14:04:06 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "stdlib.h"
#include "time.h"

int main()
{
	srand (time(NULL));

	std::cout << "----------------------Shrubbery Form----------------------" << std::endl;
	try
	{
		Bureaucrat exec("Bob", 10);
		ShrubberyCreationForm form("Tree");
		std::cout << form;
		exec.signForm(form);
		form.execute(exec);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "----------------------Robotomy Request Form----------------------" << std::endl;
	try
	{
		Bureaucrat exec("Bob", 10);
		RobotomyRequestForm form("Max");
		std::cout << form;
		exec.signForm(form);
		form.execute(exec);
		form.execute(exec);
		form.execute(exec);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "----------------------Presidential Pardon Form----------------------" << std::endl;
	try
	{
		Bureaucrat exec("Bob", 1);
		PresidentialPardonForm form("Axel");
		std::cout << form;
		exec.signForm(form);
		form.execute(exec);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "----------------------executeForm----------------------" << std::endl;
	try
	{
		Bureaucrat exec("Bob", 10);
		RobotomyRequestForm form("Morgan");
		std::cout << form;
		exec.signForm(form);
		exec.executeForm(form);
		// exec.incrementGrade();
		exec.executeForm(form);
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
}