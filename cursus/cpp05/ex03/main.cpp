#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void sc_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, ShrubberyCreationForm form);
void sc_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, ShrubberyCreationForm form);
void sc_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, ShrubberyCreationForm form);

void pp_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, PresidentialPardonForm form);
void pp_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, PresidentialPardonForm form);
void pp_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, PresidentialPardonForm form);

void rr_test_grade_not_high_enough_to_sign(Bureaucrat bureaucrat, RobotomyRequestForm form);
void rr_test_grade_not_high_enough_to_execute(Bureaucrat bureaucrat, RobotomyRequestForm form);
void rr_test_grade_ok_to_sign_and_execute(Bureaucrat bureaucrat, RobotomyRequestForm form);
void rr_test_grade_ok_to_sign_and_execute_multi(Bureaucrat bureaucrat, RobotomyRequestForm form);

void intern_test_valid_shrubbery_creation(Intern intern);
void intern_test_valid_robotomy_request(Intern intern);
void intern_test_valid_presidential_pardon(Intern intern);
void intern_test_invalid_form_name(Intern intern);

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
	Intern intern;

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

	std::cout << "=======================================" << std::endl;
	std::cout << "==-- Testing Intern --==" << std::endl;
	std::cout << "=======================================" << std::endl;
	intern_test_valid_shrubbery_creation(intern);
	std::cout << "\n=======================================\n"
			  << std::endl;
	intern_test_valid_robotomy_request(intern);
	std::cout << "\n=======================================\n"
			  << std::endl;
	intern_test_valid_presidential_pardon(intern);
	std::cout << "\n=======================================\n"
			  << std::endl;
	intern_test_invalid_form_name(intern);
	std::cout << "\n=======================================\n"
			  << std::endl;

	return (0);
}

/**
 * Intern Tests:
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


/**
 * PresidentialPardonForm Tests:
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



/**
 * RobotomyRequestForm Tests
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


/**
 * ShrubberyCreationForm Tests:
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
