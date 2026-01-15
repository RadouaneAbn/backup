#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <cmath>

#define RESET   "\033[0m"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define CHAR_MAX std::numeric_limits<char>::max()
#define CHAR_MIN std::numeric_limits<char>::min()

#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()

#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()

#define DOUBLE_MAX std::numeric_limits<double>::max()
#define DOUBLE_MIN std::numeric_limits<double>::min()

typedef enum e_datatype
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
} t_datatype;

t_datatype get_datatype(std::string &s);

class ScalarConverter
{
	public:
		virtual ~ScalarConverter() = 0;
		static void convert(char* s);
};

#endif
