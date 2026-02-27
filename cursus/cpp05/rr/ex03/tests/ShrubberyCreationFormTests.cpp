#include "../ShrubberyCreationForm.hpp"


/**
 * Test 1: Grade not high enough to execute
 */
void sc_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, ShrubberyCreationForm form)
{
	std::cout << "\n---- Test 1: Grade not high enough to sign ----" << std::endl;
	try
	{
		std::cout << "Expected:\n" << bureaucrat.getName() << " couldn't sign Shrubbery Creation Form because Bureaucrat grade too low to sign the form\nGot:\n";
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
void sc_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, ShrubberyCreationForm form)
{
	std::cout << "\n---- Test 2: Grade not high enough to execute ----" << std::endl;
	try
	{
		bureaucrat.signAForm(form);
		std::cout << "Testing form execution ...\n";
		std::cout << "Expected:\n" << bureaucrat.getName() << " couldn't execute Shrubbery Creation Form because Bureaucrat grade too low to execute the form\nGot:\n";
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
void sc_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, ShrubberyCreationForm form)
{
	std::cout << "\n---- Test 3: Grade is high to sign and execute ----" << std::endl;
	std::cout << "Expected:\n" << bureaucrat.getName() << " signed Shrubbery Creation Form\n"
		<< form.getTarget() << " executed Shrubbery Creation Form\nGot:\n";

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
