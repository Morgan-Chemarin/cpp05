/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:23:40 by dev               #+#    #+#             */
/*   Updated: 2026/04/14 18:35:01 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
	_name("dName"),
	_signed(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{
}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute):
	_name(name),
	_signed(false),
	_gradeRequiredToSign(gradeRequiredToSign),
	_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other):
	_name(other.getName()),
	_signed(other.getSigned()),
	_gradeRequiredToSign(other.getGradeRequiredToSign()),
	_gradeRequiredToExecute(other.getGradeRequiredToExecute())
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other.getSigned();
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
	return (_name);	
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

void Form::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > this->getGradeRequiredToSign())
		throw Form::GradeTooLowException();
	else if (this->getSigned() == false)
		this->_signed = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	std::string sign;
	if (form.getSigned())
		sign = "signed";
	else
		sign = "not signed";
	o << "Form: " << form.getName() << " is " << sign << ". Grade required to sign: " << form.getGradeRequiredToSign() << ". Grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
	return (o);
}