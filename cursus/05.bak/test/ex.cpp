#include <iostream>

class NewException : public std::exception
{
private:
	std::string _message;

public:
	NewException(const std::string &message) : _message(message) {}
	~NewException() throw() {}
	const char *what() const throw()
	{
		return _message.c_str();
	}
};

int main()
{
	try
	{
		throw NewException("new exceptipn");
	}
	catch(const std::exception& e)
	{
		std::cerr << "catched: " << e.what() << '\n';
	}
	
}