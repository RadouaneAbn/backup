#include "../get_next_line/get_next_line.h"
#include "../includes/garbage_collector.h"
#include "../includes/pipex_bonus.h"
#include "../includes/utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (s1 == s2);
	while (s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	append_to_list(t_list **head, char *s)
{
	t_list	*new_node;

	new_node = ft_lstnew(s);
	if (new_node == NULL)
		exit_error("Malloc", MALLOC_R, 1);
	save_ptr(new_node);
	ft_lstadd_back(head, new_node);
}

t_list	*read_from_input(char *delimiter, int delimiter_len)
{
	t_list	*head;
	char	*s;

	head = NULL;
	while (1)
	{
		write(1, "here_doc> ", 11);
		s = get_next_line(0);
		if (s == NULL)
			break ;
		if (ft_strncmp(s, delimiter, delimiter_len) == 0)
		{
			if (ft_strncmp(s + delimiter_len, "\n", 2) == 0)
			{
				free(s);
				break ;
			}
		}
		save_ptr(s);
		append_to_list(&head, s);
	}
	return (head);
}

void	first_execution(char **env, t_execute_info *info, t_list **head)
{
	t_list	*current;

	current = *head;
	dup2(info->fd[1][1], STDOUT_FILENO);
	close(info->fd[1][1]);
	close(info->fd[1][0]);
	dup2(info->fd[0][0], STDIN_FILENO);
	close(info->fd[0][0]);
	while (current)
	{
		write(info->fd[0][1], (char *)current->content,
				ft_strlen((char *)current->content));
		current = current->next;
	}
	info->current_command = build_command(info->commands_list[0], info->path);
	close(info->fd[0][1]);
	execute_command(info->current_command, env);
}

void	second_execution(char **env, t_execute_info *info)
{
	int	output_fd;

	dup2(info->fd[1][0], STDIN_FILENO);
	close(info->fd[1][0]);
	close(info->fd[1][1]);
	if (file_is_directory(info->output_file))
		exit_error(info->output_file, DIR_ERR, 1);
	output_fd = open(info->output_file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (output_fd == -1)
		exit_error(info->output_file, OPEN_ERR, 1);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	info->current_command = build_command(info->commands_list[1], info->path);
	execute_command(info->current_command, env);
}

void	here_doc(int ac, char **av, char **env)
{
	t_execute_info	info;
	int				pid[3];
	t_list			*head;

	init_here_doc(&info, ac, av, env);
	pid[2] = 0;
	head = NULL;
	head = read_from_input(info.delimiter, ft_strlen(info.delimiter));
	pid[0] = fork();
	if (pid[0] == 0)
		first_execution(env, &info, &head);
	close(info.fd[0][0]);
	close(info.fd[0][1]);
	pid[1] = fork();
	if (pid[1] == 0)
		second_execution(env, &info);
	close(info.fd[1][0]);
	close(info.fd[1][1]);
	wait_for_children(pid);
}
