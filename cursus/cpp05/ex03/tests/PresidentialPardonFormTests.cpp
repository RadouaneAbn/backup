#include "../PresidentialPardonForm.hpp"

/**
 * Test 1: Grade not high enough to execute
 */
void pp_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, PresidentialPardonForm form)
{
	std::cout << "\n---- Test 1: Grade not high enough to sign ----" << std::endl;
	try
	{
		bureaucrat.signAForm(form);
		std::cout << "Expected:\n"
				  << bureaucrat.getName() << " couldn't sign Presidential Pardon Form because Bureaucrat grade too low to sign the form\nGot:\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/**
 * Test 2: Grade not high enough to execute
 */
void pp_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, PresidentialPardonForm form)
{
	std::cout << "\n---- Test 2: Grade not high enough to execute ----" << std::endl;
	try
	{
		bureaucrat.signAForm(form);
		std::cout << "Testing form execution ...\n";
		std::cout << "Expected:\n"
				  << bureaucrat.getName() << " couldn't execute Presidential Pardon Form because Bureaucrat grade too low to execute the form\nGot:\n";
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
void pp_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, PresidentialPardonForm form)
{
	std::cout << "\n---- Test 3: Grade is high to sign and execute ----" << std::endl;
	std::cout << "Expected:\n"
			  << bureaucrat.getName() << " signed Presidential Pardon Form\n"
			  << form.getTarget() << " has been pardoned by Zaphod Beeblebrox\nGot:\n";

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
