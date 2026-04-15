/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:23:32 by dev               #+#    #+#             */
/*   Updated: 2026/04/14 16:05:55 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdbool.h>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
		
	public:
		Form();
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		void beSigned(Bureaucrat& bur);

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
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif