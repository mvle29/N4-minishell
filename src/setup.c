/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:12:25 by marvin            #+#    #+#             */
/*   Updated: 2026/04/23 19:12:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// exit code 3 :
// Invalid argument: An incorrect or missing argument was provided
// to the script

void	setup(int agc, char **agv, char **envp, t_shell *shell)
{
	(void)agc;
	(void)agv;
	(void)envp;
	shell->last_line = NULL;
	shell->ast = NULL;
	shell->envp = NULL;
	shell->last_status = 0;
	shell->line = NULL;
	shell->tokens = NULL;
	/*if (agc != 1 || !envp || !*envp)
		exit_shell(shell, 3)
	shell->env = get_env(envp); //malloc = exit;	pas normal ?			3 lignes = setup?
	if (!shell->env)
		exit_shell(shell, 71);	// exit malloc*/
	def_signals(shell); //erreur de signal exi;
}
