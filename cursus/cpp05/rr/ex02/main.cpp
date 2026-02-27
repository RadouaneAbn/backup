#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests/tests.h"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm sForm("home");
	RobotomyRequestForm rForm("Bender");
	PresidentialPardonForm pForm("Arthur Dent");
	Bureaucrat admin("Admin", 1);
	Bureaucrat newBureaucrat("New Bureaucrat", 150);
	Bureaucrat sBureaucratWithSignGrade("Shrubbery Bureaucrat", 140);
	Bureaucrat rBureaucratWithSignGrade("Robotomy Bureaucrat", 20);
	Bureaucrat pBureaucratWithSignGrade("Pardon Bureaucrat", 25);

	std::cout << "=======================================" << std::endl;
	std::cout << "==-- Testing ShrubberyCreationForm --==" << std::endl;
	std::cout << "=======================================" << std::endl;
	sc_test_grade_not_high_enough_to_sign(newBureaucrat, sForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	sc_test_grade_not_high_enough_to_execute(sBureaucratWithSignGrade, sForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	sc_test_grade_ok_to_sign_and_execute(admin, sForm);
	std::cout << "\n=======================================\n"
			  << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "==-- Testing PresidentialPardonForm --==" << std::endl;
	std::cout << "=======================================" << std::endl;
	pp_test_grade_not_high_enough_to_sign(newBureaucrat, pForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	pp_test_grade_not_high_enough_to_execute(pBureaucratWithSignGrade, pForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	pp_test_grade_ok_to_sign_and_execute(admin, pForm);
	std::cout << "\n=======================================\n"
			  << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "==-- Testing RobotomyRequestForm --==" << std::endl;
	std::cout << "=======================================" << std::endl;
	rr_test_grade_not_high_enough_to_sign(newBureaucrat, rForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	rr_test_grade_not_high_enough_to_execute(rBureaucratWithSignGrade, rForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	rr_test_grade_ok_to_sign_and_execute(admin, rForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	rr_test_grade_ok_to_sign_and_execute_multi(admin, rForm);
	std::cout << "\n=======================================\n"
			  << std::endl;
	return (0);
}