#include "ScalarConverter.hpp"

void display_char_as_main(std::string &s)
{
	char c = s[0];

	/* Print char repr */
	if (c < 0)
		std::cout << "char: Imposible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	
	/* Print int repr */
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	/* Print float repr */
	std::cout << "float: " << std::fixed << static_cast<float>(c) << "f" << std::endl;

	/* Print double repr */
	std::cout << "double: " << std::fixed << static_cast<double>(c) << std::endl;
}

void display_int_as_main(std::string &s)
{
	long i = atol(s.c_str());

	/* Print char repr */
	if (i > CHAR_MAX || i < CHAR_MIN)
		std::cout << "char: Imposible" << std::endl;
	else
	{
		char c = static_cast<char>(i);
		if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}

	/* Print int repr */
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: Imposible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;

	/* Print float repr */
	if (i - static_cast<int>(i) == 0)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;

	/* Print double repr */
	if (i - static_cast<int>(i) == 0)
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << std::endl;
	else
		std::cout << "double: " << static_cast<float>(i) << std::endl;
}

void display_float_as_main(std::string &s)
{
	float f = atof(s.c_str());

	/* Print char repr */
	if (f > CHAR_MAX || f < CHAR_MIN || std::isnan(f))
		std::cout << "char: Imposible" << std::endl;
	else
	{
		char c = static_cast<char>(f);
		if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}

	/* Print int repr */
	if (f > INT_MAX || f < INT_MIN || std::isnan(f))
		std::cout << "int: Imposible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	/* Print float repr */
	if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: "  << f << "f" << std::endl;

	/* Print double repr */
	if (f - static_cast<int>(f) == 0)
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	else
		std::cout << "double: "  << static_cast<double>(f) << std::endl;
}

void display_double_as_main(std::string &s)
{
	double d = atof(s.c_str());

	/* Print char repr */
	if (d > CHAR_MAX || d < CHAR_MIN || std::isnan(d))
		std::cout << "char: Imposible" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}

	/* Print int repr */
	if (d > INT_MAX || d < INT_MIN || std::isnan(d))
		std::cout << "int: Imposible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	/* Print float repr */
	if (d - static_cast<int>(d) == 0)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << static_cast<float>(d) << "f" << std::endl;

	/* Print double repr */
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "double: " << std::fixed << d << std::endl;
}

void ScalarConverter::convert(char *str)
{
	std::string s = str;
	t_datatype datatype = get_datatype(s);
	std::string arr[] = {
		"char found",
		"int found",
		"float found",
		"double found",
		"wrong input"
	};

	std::cout << RED << arr[datatype] << RESET << std::endl;

	switch (datatype)
	{
	case CHAR:
		display_char_as_main(s);
		break;
	case INT:
		display_int_as_main(s);
		break;
	case FLOAT:
		display_float_as_main(s);
		break;
	case DOUBLE:
		display_double_as_main(s);
		break;
	default:
		std::cout << "Conversion impossible" << std::endl;
	}
}