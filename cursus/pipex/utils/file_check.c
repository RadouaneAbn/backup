#include "../includes/utils.h"

int file_missing_argument(char *filename)
{
	if (ft_strncmp(filename, ".", 2) == 0)
	{
		print_error(filename, ": Filename argument required\n");
		return (1);
	}
	return (0);
}

int file_missing(char *filename)
{
    if (file_exists(filename) == 0)
    {
        if (ft_strchr(filename, '/') == NULL)
            print_error(filename, ": Command not found\n");
        else
            print_error(filename, ": No such file or directory\n");
        return (1);
    }
    return (0);
}