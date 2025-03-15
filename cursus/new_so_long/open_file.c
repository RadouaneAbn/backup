#include "so_long.h"
#include "messages.h"

static int ft_isdirectory(char *path)
{
	int fd;

	fd = open(path, __O_DIRECTORY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int file_is_dot_ber(char *file_path)
{
	int file_path_len;

	file_path_len = ft_strlen(file_path);
	if (ft_strncmp(file_path + (file_path_len - 4), ".ber", 5) == 0)
		return (1);
	return (0);
}

static int file_is_regulare(char *map_path)
{
	int slen;

	slen = ft_strlen(map_path);
	while (slen > 0 && map_path[slen] != '/')
		slen--;
	if (map_path[slen] == '/')
		slen++;
	if (map_path[slen] == '.')
		return (0);
	return (1);
}

int open_file(char *map_path)
{
	int fd;

	if (file_is_regulare(map_path) == FALSE)
		exit_error(1, REGULAR_FILE_ERR);
	if (ft_isdirectory(map_path))
		exit_error(1, MAP_IS_DIR_ERR);
	if (file_is_dot_ber(map_path) == FALSE)
		exit_error(1, WRONG_EXT_MSG);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error(1, NULL);
	return (fd);
}