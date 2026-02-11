#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm &old_obj);
	RobotomyRequestForm &operator=(RobotomyRequestForm &old_obj);

	std::string getTarget(void) const;
	void executingForm(Bureaucrat const &executor) const;
};

#endif