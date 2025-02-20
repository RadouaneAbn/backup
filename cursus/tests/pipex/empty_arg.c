#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("' ' ->%d\n", access(" ", F_OK));
	printf("'' ->%d\n", access("", F_OK));
	printf("' ' ->%d\n", access(" ", X_OK));
	printf("'' ->%d\n", access("", X_OK));
}