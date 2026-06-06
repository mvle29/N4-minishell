/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:40:33 by marvin            #+#    #+#             */
/*   Updated: 2026/04/26 19:40:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_shell(t_shell *shell)
{
	if (shell)
	{
		cleanup_tokens(shell);
		cleanup_ast(shell);
		if (shell->line)
			free(shell->line);
		if (shell->last_line)
			free(shell->last_line);
	}
}

void	cleanup_loop(t_shell *shell)
{
	cleanup_tokens(shell);
	cleanup_ast(shell);
}

void	cleanup_and_exit(t_shell *shell, char *msg, int fd, int status)
{
	cleanup_shell(shell);
	if (msg)
		write(fd, msg, ft_strlen(msg));
	rl_clear_history();
	exit(status);
}
