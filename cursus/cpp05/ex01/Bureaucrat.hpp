#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
#include "colors.h"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat &old_obj);
	Bureaucrat& operator=(Bureaucrat &old_obj);

	/* Getters */
	int getGrade(void) const;
	std::string getName(void) const;

	/* Member function */
	void incGrade(void);
	void decGrade(void);
	void signForm(Form &form) const;

	/* Exceptions */
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &obj);

#endif