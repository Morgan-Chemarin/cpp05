/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:23:32 by dev               #+#    #+#             */
/*   Updated: 2026/04/15 14:09:47 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdbool.h>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;	
		
	public:
		AForm();
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		void beSigned(Bureaucrat& bur);

		void execute(Bureaucrat const& executor) const; 
		virtual void doActionForm() const = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high.");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low.");
				}
		};

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form isn't signed.");
				}
		};
};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif