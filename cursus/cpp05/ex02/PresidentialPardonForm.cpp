#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &old_obj)
	: AForm(old_obj), _target(old_obj._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &old_obj)
{
	// name, signGrade and execGrade are const
	AForm::operator=(old_obj);
	_target = old_obj._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void PresidentialPardonForm::executingForm(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << BLUE << _target << RESET << " has been pardoned by " << RED << BIG_FELLO << RESET << std::endl;
}
