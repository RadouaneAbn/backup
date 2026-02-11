#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &old_obj)
	: AForm(old_obj), _target(old_obj._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &old_obj)
{
	// name, signGrade and execGrade are const
	AForm::operator=(old_obj);
	_target = old_obj._target;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void ShrubberyCreationForm::executingForm(Bureaucrat const &executor) const
{
	(void) executor;
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile.is_open())
		throw std::ios_base::failure("Failed to open: " + _target + "_shrubbery");
	outfile << TREE1;
	outfile.close();
	std::cout << BLUE << _target << RESET << " executed " << GREEN << getName() << RESET << std::endl;
}
