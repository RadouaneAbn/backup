#include "../Intern.hpp"

/**
 * Test 1: Valid form name - shrubbery creation
 */
void intern_test_valid_shrubbery_creation(Intern intern)
{
	std::cout << "\n---- Test 1: Valid form - shrubbery creation ----" << std::endl;
	try
	{
		std::cout << "Expected:\n"
				  << GREEN << "Intern created Shrubbery Creation Form" << RESET << "\nGot:\n";
		AForm *form = intern.makeForm("shrubbery creation", "home");
		std::cout << GREEN << "Intern created Shrubbery Creation Form" << RESET << std::endl;
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/**
 * Test 2: Valid form name - robotomy request
 */
void intern_test_valid_robotomy_request(Intern intern)
{
	std::cout << "\n---- Test 2: Valid form - robotomy request ----" << std::endl;
	try
	{
		std::cout << "Expected:\n"
				  << GREEN << "Intern created Robotomy Request Form" << RESET << "\nGot:\n";
		AForm *form = intern.makeForm("robotomy request", "Bender");
		std::cout << GREEN << "Intern created Robotomy Request Form" << RESET << std::endl;
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/**
 * Test 3: Valid form name - presidential pardon
 */
void intern_test_valid_presidential_pardon(Intern intern)
{
	std::cout << "\n---- Test 3: Valid form - presidential pardon ----" << std::endl;
	try
	{
		std::cout << "Expected:\n"
				  << GREEN << "Intern created Presidential Pardon Form" << RESET << "\nGot:\n";
		AForm *form = intern.makeForm("presidential pardon", "Arthur Dent");
		std::cout << GREEN << "Intern created Presidential Pardon Form" << RESET << std::endl;
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/**
 * Test 4: Invalid form name
 */
void intern_test_invalid_form_name(Intern intern)
{
	std::cout << "\n---- Test 4: Invalid form name ----" << std::endl;
	try
	{
		std::cout << "Expected:\n"
				  << RED << "Intern Exception: Form not found" << RESET << "\nGot:\n";
		AForm *form = intern.makeForm("invalid form", "target");
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
