#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	std::string err;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(Bureaucrat &old_obj) : _name(old_obj._name), _grade(old_obj._grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &old_obj)
{
	// name is a const
	_grade = old_obj.getGrade();
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incGrade(void)
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::decGrade(void)
{
	_grade++;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signAForm(AForm &AForm) const
{
	try
	{
		AForm.beSigned(*this);
		std::cout << BLUE << _name << RESET << " signed " << GREEN << AForm.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLUE << _name << RESET << " couldn't sign " << RED << AForm.getName() << RESET << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		// std::cout << BLUE << _name << RESET << " executed " << GREEN << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLUE << _name << RESET << " couldn't execute " << RED << form.getName() << RESET << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &obj)
{
	o << RED << obj.getName() << RESET << ", bureaucrat grade " << obj.getGrade() << ".";
	return (o);
}
