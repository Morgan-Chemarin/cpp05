/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:03:54 by dev               #+#    #+#             */
/*   Updated: 2026/04/15 16:09:33 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation Form", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target(other.getTarget())
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::doActionForm() const
{
	std::string outputFile = _target + ".shrubbery";
	std::ofstream ofs(outputFile.c_str());
	if (!ofs)
	{
		std::cout << "can't create output file" << std::endl;
		return ;
	}
	std::ostringstream oss;
    oss << 
	"	     ccee88oo" << std::endl <<
	"  C8O8O8Q8PoOb o8oo" << std::endl <<
	" dOB69QO8PdUOpugoO9bD" << std::endl <<
	"CgggbU8OU qOp qOdoUOdcb" << std::endl <<
	"    6OuU  /p u gcoUodpP" << std::endl <<
	"      \\\\//  /douUP" << std::endl <<
	"        \\\\////" << std::endl <<
	"         |||/\\" << std::endl <<
	"         |||\\/" << std::endl <<
	"         |||||" << std::endl <<
	"   .....//||||\\....";
    ofs << oss.str();
}