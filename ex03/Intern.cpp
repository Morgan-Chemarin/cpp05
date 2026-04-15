/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:09:39 by dev               #+#    #+#             */
/*   Updated: 2026/04/15 17:39:45 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	
}

AForm* Intern::makeShrubbery(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobot(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*functions[3])(std::string target) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobot,
		&Intern::makePresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*functions[i])(target));
		}
	}
	std::cout << "Intern can't create form because he doesn't exist." << std::endl;
	return NULL;
}