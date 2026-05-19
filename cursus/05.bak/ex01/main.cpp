#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main() {
	std::cout << "========== BUREAUCRAT TESTS ==========" << std::endl;

	Bureaucrat b1("oussama", 150);
	Bureaucrat b2("walid", 1);
	Bureaucrat b3("radouane", 75);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	std::cout << "\n--- Testing grade increment/decrement ---" << std::endl;
	std::cout << "Before: " << b3 << std::endl;
	b3.incGrade();
	std::cout << "After incGrade: " << b3 << std::endl;
	b3.decGrade();
	std::cout << "After decGrade: " << b3 << std::endl;

	std::cout << "\n--- Testing GradeTooHighException (increment) ---" << std::endl;
	try {
		Bureaucrat high("high", 1);
		high.incGrade(); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing GradeTooLowException (decrement) ---" << std::endl;
	try {
		Bureaucrat low("low", 150);
		low.decGrade(); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing invalid grade at construction ---" << std::endl;
	try {
		Bureaucrat invalid("invalid", 0); // Grade too high
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat invalid("invalid", 151); // Grade too low
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n========== FORM TESTS ==========" << std::endl;

	std::cout << "\n--- Creating valid forms ---" << std::endl;
	Form f1("Tax Form", 50, 25);
	Form f2("Leave Request", 100, 80);
	Form f3("Top Secret", 1, 1);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	std::cout << "\n--- Testing invalid form grades ---" << std::endl;
	try {
		Form invalid("Invalid", 0, 50); // signGrade too high
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Form invalid("Invalid", 50, 151); // execGrade too low
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing beSigned() ---" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);

	std::cout << "Attempting to sign forms..." << std::endl;

	// Boss should be able to sign all forms
	std::cout << "\nBoss (grade 1) tries to sign:" << std::endl;
	boss.signForm(f1);
	std::cout << f1 << std::endl;

	boss.signForm(f2);
	std::cout << f2 << std::endl;

	boss.signForm(f3);
	std::cout << f3 << std::endl;

	// Intern should fail to sign most forms
	std::cout << "\nIntern (grade 150) tries to sign:" << std::endl;
	Form f4("Easy Form", 150, 150);
	Form f5("Hard Form", 10, 5);

	intern.signForm(f4); // Should succeed
	std::cout << f4 << std::endl;

	intern.signForm(f5); // Should fail
	std::cout << f5 << std::endl;

	std::cout << "\n========== ALL TESTS COMPLETE ==========" << std::endl;

	return (0);
}