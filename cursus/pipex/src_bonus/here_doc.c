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

void first_execution(char **env, t_execute_info *info)
{
	t_list *head;

	head = read_from_input(info->delimiter, ft_strlen(info->delimiter));
	dup2(info->fd[0][0], STDIN_FILENO);
	close(info->fd[0][0]);
	dup2(info->fd[1][1], STDOUT_FILENO);
	close(info->fd[1][1]);
	close(info->fd[1][0]);
	info->current_command = build_command(info->commands_list[0], info->path);
	while (head)
	{
		write(info->fd[0][1], (char *)head->content, ft_strlen((char *)head->content));
		head = head->next;
	}
	close(info->fd[0][1]);
	execute_command(info->current_command, env);
}

void second_execution(char **env, t_execute_info *info)
{
	int output_fd;

	output_fd = open(info->output_file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (output_fd == -1)
		exit(1);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	dup2(info->fd[1][0], STDIN_FILENO);
	close(info->fd[1][0]);
	close(info->fd[1][1]);
	info->current_command = build_command(info->commands_list[1], info->path);
	execute_command(info->current_command, env);
}

void here_doc(int ac, char **av, char **env)
{
	t_execute_info info;
	int pid[3];

	init_here_doc(&info, ac, av, env);
	pid[2] = 0;
	pid[0] = fork();
	if (pid[0] == 0)
		first_execution(env, &info);
	close(info.fd[0][0]);
	close(info.fd[0][1]);
	pid[1] = fork();
	if (pid[1] == 0)
		second_execution(env, &info);
	close(info.fd[1][0]);
	close(info.fd[1][1]);
	wait_for_children(pid);
}
