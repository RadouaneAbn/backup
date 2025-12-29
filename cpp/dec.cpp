#include <iostream>
#include <cstring>

class a {
	public:
	std::string _s = "";
	char *_ss;
	
	// Constructor
	a(std::string s) {
		std::cout << "Constructor called for: " << s << std::endl;
		_s = s;
		_ss = strdup(_s.c_str());
	}
	
	// Destructor - called when object is destroyed
	~a() {
		std::cout << "Destructor called for: " << _s << std::endl;
		// Free the dynamically allocated memory
		free(_ss);
		// std::cout << "Memory freed!" << std::endl;
	}
	
	void pr(void) {
		std::cout << "_s = " << _s << std::endl;
		std::cout << "_ss = " << _ss << std::endl;
	}
};

void test_scope() {
	std::cout << "\n--- Entering test_scope function ---" << std::endl;
	a local_obj("local");
	local_obj.pr();
	std::cout << "--- Exiting test_scope function ---" << std::endl;
	// Destructor will be called here when local_obj goes out of scope
}

int main() {
	std::cout << "=== Creating object in main ===" << std::endl;
	a s("hello");
	s.pr();

	std::cout << "\n=== Calling test_scope ===" << std::endl;
	test_scope();
	std::cout << "\n=== Back in main ===" << std::endl;

	std::cout << "\n=== Creating object with new ===" << std::endl;
	a *ptr = new a("dynamic");
	ptr->pr();
	
	std::cout << "\n=== Deleting dynamic object ===" << std::endl;
	delete ptr;  // Destructor called here manually

	std::cout << "\n=== End of main ===" << std::endl;
	// Destructor for 's' will be called here when main exits
}