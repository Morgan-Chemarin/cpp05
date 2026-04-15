/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:00:40 by dev               #+#    #+#             */
/*   Updated: 2026/04/14 14:06:29 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	
	std::cout << "----------------------Too high----------------------" << std::endl;
	
	try
	{
		Bureaucrat a("Bob", 2);
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------------------Too low----------------------" << std::endl;
	
	try
	{
		Bureaucrat b("Harry", 149);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------------------Free exception----------------------" << std::endl;
	
	Bureaucrat *a = new Bureaucrat("Bob", 1);
	try
	{
		std::cout << *a;
		a->incrementGrade();
		delete a;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		delete a;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
		delete a;
	}
}