#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("oussama", 150);
	Bureaucrat b2("walid", 1);
	Bureaucrat b3("radouane", 75);

	std::cout << "Testing Bureaucrat class" << std::endl;
	std::cout << b3 << std::endl;
	while (b3.getGrade() < 150)
	{
		b3.decGrade();
	}
	std::cout << b3 << std::endl;
	while (b3.getGrade() > 1)
	{
		b3.incGrade();
	}
	std::cout << b3 << std::endl;

	std::cout << "Testing GradeTooHighException" << std::endl;
	try
	{
		while (true)
		{
			b1.incGrade();
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Testing GradeTooLowException" << std::endl;
	try
	{
		while (true)
		{
			b2.decGrade();
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}