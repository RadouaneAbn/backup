#include <iostream>

int main () {
	bool ignore = false;
	int age;
	std::string name;
	char initial, initial_2;

	std::cout << "Enter your age: ";
	std::cin >> age;


	// std::cout << "cin status: " << std::cin.fail() << std::endl;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}

	// if (std::cin.fail())

	// if (!ignore)
	// 	std::cin.ignore();

	std::cout << "Enter your name: ";
	std::cin >> name;

	// if (!ignore)
	// 	std::cin.ignore();

	std::cout << "Enter the first letter of your firstname: ";
	std::cin >> initial;

	// if (!ignore)
	// 	std::cin.ignore();

	std::cout << "Enter the first letter of your lastname: ";
	std::cin >> initial_2;

	if (!ignore)
		std::cin.ignore();

	std::cout << (char)std::toupper(initial) << "." << (char)std::toupper(initial_2) << " " << name <<
		" (" << age << ")" << std::endl;
}
