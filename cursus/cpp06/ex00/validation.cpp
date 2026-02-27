#include "ScalarConverter.hpp"

bool is_float(std::string &s)
{
	std::cout << YELLOW << "checking float\n" << RESET;
	bool dot_found = false;
	bool sign_found = false;
	size_t fpos = s.find("f");
	if (fpos == std::string::npos)
		return (false);
	for (size_t i = 0; i < s.length() - 1; i++)
	{
		if ((s[i] == '+' || s[i] == '-') && sign_found == false)
		{
			sign_found = true;
			continue;
		}
		if (s[i] == '.' && std::isdigit(s[i + 1]) && dot_found == false)
		{
			dot_found = true;
			continue;
		}
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool is_double(std::string &s)
{
	std::cout << YELLOW << "checking double\n" << RESET;
	bool dot_found = false;
	bool sign_found = false;

	for (size_t i = 0; i < s.length(); i++)
	{
		if ((s[i] == '+' || s[i] == '-') && sign_found == false)
		{
			sign_found = true;
			continue;
		}
		if (s[i] == '.' && std::isdigit(s[i + 1]) && s[i + 1] && dot_found == false)
		{
			dot_found = true;
			continue;
		}
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool is_int(std::string &s)
{
	std::cout << YELLOW << "checking int\n" << RESET;
	bool sign_found = false;

	for (size_t i = 0; i < s.length(); i++)
	{
		if ((s[i] == '+' || s[i] == '-') && sign_found == false)
		{
			sign_found = true;
			continue;
		}
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

t_datatype get_datatype(std::string& s)
{
	if (s.empty())
		return (NONE);
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (DOUBLE);
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (FLOAT);
	std::cout << YELLOW << "checking char\n" << RESET;
	if (s.length() <= 1 && !std::isdigit(s[0]))
		return (CHAR);
	if (is_int(s))
		return (INT);
	if (is_float(s))
		return (FLOAT);
	if (is_double(s))
		return (DOUBLE);
	return (NONE);
}