#include "Intern.hpp"

/* Orthodox Canonical */
Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &old_obj)
{
	(void)old_obj;
}

Intern &Intern::operator=(const Intern &old_obj)
{
	(void)old_obj;
	return (*this);
}

AForm *createShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *createRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *createPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

/* Member Functions */
AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	AForm *(*formCreators[3])(const std::string target) = {
		&createShrubberyCreationForm,
		&createRobotomyRequestForm,
		&createPresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
			return (formCreators[i](target));
	}
	throw Intern::FormNotFoundException();
}

/* Exceptions */
const char *Intern::FormNotFoundException::what(void) const throw()
{
	return ("Intern Exception: Form not found");
}