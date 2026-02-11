#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "colors.h"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

public:
	AForm(const std::string &name, int signGrade, int execGrade);
	virtual ~AForm(void);
	AForm(AForm &old_obj);
	AForm &operator=(AForm &old_obj);

	/* Member functions */
	void beSigned(const Bureaucrat &b);
	void checkExecutable(const Bureaucrat &executor) const;
	void execute(Bureaucrat const &executor) const;
	virtual void executingForm(Bureaucrat const &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	private:
		std::string _message;

	public:
		FormNotSignedException(const std::string message);
		~FormNotSignedException() throw() {}
		const char *what(void) const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm &obj);

#endif