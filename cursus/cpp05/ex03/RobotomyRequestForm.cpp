#include "RobotomyRequestForm.hpp"
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form", 25, 5), _target(target)
{
	srand(time(0));
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &old_obj)
	: AForm(old_obj), _target(old_obj._target)
{
	srand(time(0));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &old_obj)
{
	// name, signGrade and execGrade are const
	AForm::operator=(old_obj);
	_target = old_obj._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void RobotomyRequestForm::executingForm(Bureaucrat const &executor) const
{
	int iter = 20;
	int index = 0;
	int direction = 1;
	(void)executor;
	std::string animate[] = {"0oooo", "o0ooo", "oo0oo", "ooo0o", "oooo0"};
	std::cout << "Driling ";
	for (int i = 0; i < iter; i++)
	{
		std::cout << animate[index] << std::flush;
		usleep(100000);
		std::cout << "\b\b\b\b\b";

		index += direction;

		if (index == 4 || index == 0)
			direction *= -1;
	}
	std::cout << "\r"
			  << ((rand() % 2) ? (GREEN + _target + RESET + " has been robotomized successfully") : "robotomy failed") << std::endl;
}
