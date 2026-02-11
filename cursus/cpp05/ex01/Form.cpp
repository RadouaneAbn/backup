#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException("Grade required to sign is too high");
	else if (signGrade > 150)
		throw GradeTooLowException("Grade required to sign is too low");
	if (execGrade < 1)
		throw GradeTooHighException("Grade required to execute is too high");
	else if (execGrade > 150)
		throw GradeTooLowException("Grade required to execute is too low");
}

Form::~Form() {}

Form::Form(Form &old_obj) : _name(old_obj._name), _isSigned(old_obj._isSigned), _signGrade(old_obj._signGrade), _execGrade(old_obj._execGrade)
{
}

Form &Form::operator=(Form &old_obj)
{
	// name, signGrade and execGrade are const
	_isSigned = old_obj.getIsSigned();
	return (*this);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException("Bureaucrat grade too low to sign the form");
	_isSigned = true;
}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getIsSigned(void) const
{
	return (_isSigned);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

Form::GradeTooHighException::GradeTooHighException(const std::string message) : _message(message) {}
Form::GradeTooLowException::GradeTooLowException(const std::string message) : _message(message) {}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return (_message.c_str());
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return _message.c_str();
}

std::ostream &operator<<(std::ostream &o, Form &obj)
{
	if (obj.getIsSigned())
		o << GREEN << obj.getName() << RESET << " is signed. Sign grade: " << obj.getSignGrade() << ", Exec grade: " << obj.getExecGrade() << ".";
	else
		o << RED << obj.getName() << RESET << " is not signed. Sign grade: " << obj.getSignGrade() << ", Exec grade: " << obj.getExecGrade() << ".";
	return (o);
}