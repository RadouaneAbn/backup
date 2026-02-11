#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "colors.h"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

public:
	Form(const std::string &name, int signGrade, int execGrade);
	~Form(void);
	Form(Form &old_obj);
	Form &operator=(Form &old_obj);

	/* Member functions */
	void beSigned(const Bureaucrat &b);

	/* Getters */
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	/* Exceptions */
	class GradeTooHighException : public std::exception
	{
	private:
		std::string _message;

	public:
		GradeTooHighException(const std::string message);
		~GradeTooHighException() throw() {}
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string _message;

	public:
		GradeTooLowException(const std::string message);
		~GradeTooLowException() throw() {}
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form &obj);

#endif