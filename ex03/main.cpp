/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:00:40 by dev               #+#    #+#             */
/*   Updated: 2026/04/15 17:42:46 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat bur("Bob", 1);
	Intern someRandomIntern;
	AForm* robotForm;
	AForm* falseForm;

	robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
	falseForm = someRandomIntern.makeForm("useless form", "Tomy");
	
	bur.signForm(*robotForm);
	std::cout << *robotForm;
	
	if (falseForm)
	{
		bur.signForm(*falseForm);
		std::cout << *falseForm;
	}

	delete robotForm;
	delete falseForm;
}