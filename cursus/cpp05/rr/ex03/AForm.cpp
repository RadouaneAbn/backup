#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException("Sign grade required to sign is too high");
	if (signGrade > 150)
		throw GradeTooLowException("Sign grade required to sign is too low");
	if (execGrade < 1)
		throw GradeTooHighException("Exec grade required to execute is too high");
	if (execGrade > 150)
		throw GradeTooLowException("Exec grade required to execute is too low");
}

AForm::~AForm() {}

AForm::AForm(AForm &old_obj) : _name(old_obj._name), _isSigned(old_obj._isSigned), _signGrade(old_obj._signGrade), _execGrade(old_obj._execGrade)
{
}

AForm &AForm::operator=(AForm &old_obj)
{
	// name, signGrade and execGrade are const
	_isSigned = old_obj.getIsSigned();
	return (*this);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (_isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException("Bureaucrat grade too low to sign the form");
	_isSigned = true;
}

void AForm::checkExecutable(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException("Form is not signed");
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException("Bureaucrat grade too low to execute the form");
}

void AForm::executingForm(Bureaucrat const &executor) const
{
	(void)executor;
	// Pure virtual function to be implemented in derived classes
}

void AForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);
	executingForm(executor);
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (_execGrade);
}

AForm::GradeTooHighException::GradeTooHighException(const std::string message) : _message(message) {}
AForm::GradeTooLowException::GradeTooLowException(const std::string message) : _message(message) {}
AForm::FormNotSignedException::FormNotSignedException(const std::string message) : _message(message) {}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return (_message.c_str());
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return _message.c_str();
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return _message.c_str();
}

const char *AForm::FormAlreadySignedException::what(void) const throw()
{
	return "Form is already signed";
}

std::ostream &operator<<(std::ostream &o, AForm &obj)
{
	if (obj.getIsSigned())
		o << GREEN << obj.getName() << RESET << " is signed. Sign grade: " << obj.getSignGrade() << ", Exec grade: " << obj.getExecGrade() << ".";
	else
		o << RED << obj.getName() << RESET << " is not signed. Sign grade: " << obj.getSignGrade() << ", Exec grade: " << obj.getExecGrade() << ".";
	return (o);
}