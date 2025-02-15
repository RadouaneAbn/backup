#include "../includes/garbage_collector.h"
#include "../includes/utils.h"
#include "../includes/pipex_bonus.h"
#include "../get_next_line/get_next_line.h"

int ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (s1 == s2);
	while (s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void exit_error(int error_code)
{
	if (error_code == MALLOC_R)
		print_error("malloc", ": Malloc failed!");
	free_all();
	exit(1);
}

void append_to_list(t_list **head, char *s)
{
	t_list *new_node;

	new_node = ft_lstnew(s);
	if (new_node == NULL)
		exit_error(MALLOC_R);
	ft_lstadd_back(head, new_node);
}

t_list *read_from_input(char *delimiter, int delimiter_len)
{
	t_list *head;
	char *s;

	head = NULL;
	while (1)
	{
		write(1, "here_doc> ", 11);
		s = get_next_line(0);
		if (s == NULL)
			break;
		if (ft_strncmp(s, delimiter, delimiter_len) == 0)
		{
			if (ft_strncmp(s + delimiter_len, "\n", 2) == 0)
			{
				free(s);
				break;
			}
		}
		save_ptr(s);
		append_to_list(&head, s);
	}
	return (head);
}

// $> ./pipex here_doc LIMITER cmd cmd1 file

void	here_doc(int ac, char **av, char **env)
{
	t_list *head;
	// t_fd_holder file_descriptors;
	char	**command;
	char **path;
	int fd[2][2];
	int pid[3];
	int i;
	int output_file;
	
	// init_here_doc(&commands, &file_descriptors, av, ac);
	i = 0;
	if (ac) {}
	path = export_path_var(env);
	ft_bzero(pid, sizeof(int) * 3);
	// TODO: guard the head if its NULL
	pipe(fd[0]);
	pipe(fd[1]);
	pid[i] = fork();
	if (pid[i] == 0)
	{
		head = read_from_input(av[2], ft_strlen(av[2]));
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[1][1]);
		close(fd[1][0]);
		command = build_command(av[3], path);
		while (head)
		{
			write(fd[0][1], (char *)head->content, ft_strlen(head->content));
			head = head->next;
		}
		close(fd[0][1]);
		execute_command(command, env);
	}
	close(fd[0][1]);
	close(fd[0][0]);
	i++;
	pid[i] = fork();
	if (pid[i] == 0)
	{
		output_file = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		dup2(output_file, STDOUT_FILENO);
		close(output_file);
		dup2(fd[1][0], STDIN_FILENO);
		close(fd[1][0]);
		close(fd[1][1]);
		command = build_command(av[4], path);
		execute_command(command, env);
	}

	close(fd[1][1]);
	close(fd[1][0]);

	// close(file_descriptors.fd[0]);
	// close(file_descriptors.fd[1]);
	wait_for_children(pid);
	free_all();
}


// void	here_doc(int ac, char **av, char **env)
// {
// 	t_list *head;
// 	// t_fd_holder file_descriptors;
// 	char	**command;
// 	char **path;
// 	int fd[2][2];
// 	int pid[4];
// 	int i;
	
// 	// init_here_doc(&commands, &file_descriptors, av, ac);
// 	i = 0;
// 	if (ac) {}
// 	path = export_path_var(env);
// 	ft_bzero(pid, sizeof(int) * 4);
// 	// TODO: guard the head if its NULL
// 	pipe(fd[0]);
// 	pipe(fd[1]);
// 	pid[i] = fork();
// 	if (pid[i] == 0)
// 	{
// 		head = read_from_input(av[2], ft_strlen(av[2]));
// 		close(fd[0][0]);
// 		close(fd[1][0]);
// 		close(fd[1][1]);
// 		// dup2(fd[0][0], STDIN_FILENO);
// 		// dup2(fd[1][1], STDOUT_FILENO);
// 		command = build_command(av[3], path);
// 		while (head)
// 		{
// 			write(fd[0][1], (char *)head->content, ft_strlen((char *)head->content));
// 			head = head->next;
// 		}
// 		close(fd[0][1]);
// 		// execute_command(command, env);
// 		exit(1);
// 	}
// 	close(fd[0][1]);
// 	close(fd[0][0]);
// 	i++;
// 	pid[i] = fork();
// 	if (pid[i] == 0)
// 	{
// 		close(fd[0][1]);
// 		close(fd[1][0]);
// 		dup2(fd[0][0], STDIN_FILENO);
// 		dup2(fd[1][1], STDOUT_FILENO);
// 		close(fd[0][0]);
// 		close(fd[1][1]);
// 		command = build_command(av[4], path);
// 		execute_command(command, env);
// 		exit(1);
// 	}

// 	close(fd[0][1]);
// 	close(fd[0][0]);

// 	// close(file_descriptors.fd[0]);
// 	// close(file_descriptors.fd[1]);
// 	wait_for_children(pid);
// 	free_all();
// }
