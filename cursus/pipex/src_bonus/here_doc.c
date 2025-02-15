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

void	here_doc(int ac, char **av, char **env)
{
	t_list *head;
	t_cmd_v		commands;
	t_fd_holder	file_descriptors;
	
	// t_fd_holder file_desc;
	int pid[3];
	int i;
	// char *s;
	
	// ft_bzero(pid, sizeof(int) * 3);
	init_here_doc(&commands, &file_descriptors, av, ac);
	if (ac && env)
	{}
	i = 0;
	// TODO: guard the head if its NULL
	ft_bzero(pid, sizeof(int) * 3);
	pipe(file_descriptors.fd);
	pid[i] = fork();
	if (pid[i] == 0)
	{
		head = read_from_input(av[2], ft_strlen(av[2]));
		close(file_descriptors.fd[0]);
		dup2(file_descriptors.fd[1], STDOUT_FILENO);
		close(file_descriptors.fd[1]);
		while (head)
		{
			write(1, (char *)head->content, ft_strlen(head->content));
			head = head->next;
		}
		free_all();
	}
	close(file_descriptors.fd[1]);
	i++;
	pid[i] = fork();
	if (pid[i] == 0)
	{
		close(file_descriptors.fd[1]);
		dup2(file_descriptors.fd[0], STDIN_FILENO);
		close(file_descriptors.fd[0]);
		run_child_proccess(&commands, &file_descriptors, i, env);
	}
	close(file_descriptors.fd[0]);
	close(file_descriptors.fd[1]);
	wait_for_children(pid);
	free_all();
}
