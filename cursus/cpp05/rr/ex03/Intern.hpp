#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	/* Orthodox Canonical */
	Intern();
	~Intern();
	Intern(const Intern &old_obj);
	Intern &operator=(const Intern &old_obj);

	/* Member Functions */
	AForm *makeForm(std::string formName, std::string target);

	/* Exceptions */
	class FormNotFoundException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

#endif