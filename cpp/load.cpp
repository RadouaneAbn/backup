#include <iostream>
#include <unistd.h>

int  main(void)
{
	int iter = 30;
	int index = 0;
	int direction = 1;
	std::string animate[] = {"0oooo", "o0ooo", "oo0oo", "ooo0o", "oooo0"};
	std::cout << "Driling ";
	for (int i = 0; i < iter; i++)
	{
		std::cout << animate[index] << std::flush;
		usleep(100000); 
		if (i != iter - 1)
			std::cout << "\b\b\b\b\b";
		
		index += direction;
		
		if (index == 4 || index == 0)
			direction *= -1;
	}
}

