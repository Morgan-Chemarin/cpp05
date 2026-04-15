/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:23:40 by dev               #+#    #+#             */
/*   Updated: 2026/04/15 14:09:53 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():
	_name("dName"),
	_signed(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{
}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute):
	_name(name),
	_signed(false),
	_gradeRequiredToSign(gradeRequiredToSign),
	_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other):
	_name(other.getName()),
	_signed(other.getSigned()),
	_gradeRequiredToSign(other.getGradeRequiredToSign()),
	_gradeRequiredToExecute(other.getGradeRequiredToExecute())
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other.getSigned();
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return (_name);	
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

void AForm::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > this->getGradeRequiredToSign())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		this->_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	else if (this->getGradeRequiredToExecute() < executor.getGrade())
		throw GradeTooLowException();
	else
		doActionForm();
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
	std::string sign;
	if (form.getSigned())
		sign = "signed";
	else
		sign = "not signed";
	o << "Form: " << form.getName() << " is " << sign << ". Grade required to sign: " << form.getGradeRequiredToSign() << ". Grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
	return (o);
}