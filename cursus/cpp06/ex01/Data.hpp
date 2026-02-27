#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		int _value;
	public:
		Data();
		Data(const Data &oldObj);
		Data &operator=(const Data &oldObj);
		~Data();
	
		void	setValue(int value);
		int		getValue() const;
};

#endif
