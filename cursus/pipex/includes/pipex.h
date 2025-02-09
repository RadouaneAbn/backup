#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../libft/libft.h"

// typedef struct s_list {
//     void *data;
//     struct s_list *next;
// } t_list;

typedef struct s_cmd_list {
    char ***cmd_list;
    int cmd_count;
} t_cmd_list;

int clean_all(char ***cmds, char **path);
void	free_command(char **list);
void	print_error(char *name, char *error);
void	print_perror(char *name);
char	*find_path(char **env);
char	**export_path_var(char **env);
int	open_input_file(char *filename);
int	file_exists(char *file_path);
int	file_executable(char *file_path);
int	ft_strcat(char *dest, const char *src);


#endif
