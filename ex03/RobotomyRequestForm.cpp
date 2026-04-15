/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:03:54 by dev               #+#    #+#             */
/*   Updated: 2026/04/15 16:09:29 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

static int robotomized_success = 0;

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("Robotomy Request Form", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other),
	_target(other.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::doActionForm() const
{
	if (robotomized_success % 2 == 0)
		std::cout << "VUUUUUUUUUUUUDBGFBGSBGRGEIHG " << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
	robotomized_success++;
}