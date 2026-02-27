#include "../RobotomyRequestForm.hpp"

/**
 * Test 1: Grade not high enough to sign
 */
void rr_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, RobotomyRequestForm form)
{
	std::cout << "\n---- Test 1: Grade not high enough to sign ----" << std::endl;
	try
	{
		std::cout << "Expected:\n"
				  << bureaucrat.getName() << " couldn't sign Robotomy Request Form because Bureaucrat grade too low to sign the form\nGot:\n";
		bureaucrat.signAForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/**
 * Test 2: Grade not high enough to execute
 */
void rr_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, RobotomyRequestForm form)
{
	std::cout << "\n---- Test 2: Grade not high enough to execute ----" << std::endl;
	try
	{
		bureaucrat.signAForm(form);
		std::cout << "Testing form execution ...\n";
		std::cout << "Expected:\n"
				  << bureaucrat.getName() << " couldn't execute Robotomy Request Form because Bureaucrat grade too low to execute the form\nGot:\n";
		bureaucrat.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/**
 * Test 3: Grade ok to sign and execute
 */
void rr_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, RobotomyRequestForm form)
{
	std::cout << "\n---- Test 3: Grade is high to sign and execute ----" << std::endl;
	std::cout << "The RobotomyRequestForm execution has a 50% chance to succeed.\n";

	try
	{
		bureaucrat.signAForm(form);
		bureaucrat.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/**
 * Test 4: Grade ok to sign and execute multiple times
 */
void rr_test_grade_ok_to_sign_and_execute_multi(Bureaucrat bureaucrat, RobotomyRequestForm form)
{
	std::cout << "\n---- Test 4: Grade is high to sign and execute multiple times ----" << std::endl;
	std::cout << "The RobotomyRequestForm execution has a 50% chance to succeed.\n";
	bureaucrat.signAForm(form);
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n-- Iteration " << i + 1 << " --" << std::endl;
		try
		{
			bureaucrat.executeForm(form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
