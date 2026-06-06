/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:39:17 by marvin            #+#    #+#             */
/*   Updated: 2026/04/23 02:39:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	main(int agc, char **agv, char **envp)
{
	t_shell	shell;

	setup(agc, agv, envp, &shell);
	(void)agc;
	(void)envp;
	(void)agv;
	while (1)
	{
		shell.line = get_line(&shell);
		if (!shell.line)
			cleanup_and_exit(&shell, "exit\n", STDOUT_FILENO, 0);
		if (str_empty(shell.line)) //
			continue ;
		//write(1, shell.line, ft_strlen(shell.line));
		//write(1, "\n", 1);
		shell.tokens = tokens_get(&shell, shell.line); //			malloc = exit; free line dedans ?
		if (!shell.tokens || tokens_error_syntax(shell.tokens))
		{
			if (!shell.tokens)
				ft_printf("tokens failed to be allocated : if this problem persists, try restarting minishell by pressing Ctrl+D on an empty line.\n");
			cleanup_loop(&shell);
			continue ;
		}
		/*if (tokens_invalid(shell.tokens)) //aucun token ici	error token syntax ? dans la fonction -bash: syntax error near unexpected token `;'
			continue ;*/
		print_tokens(&shell);
		cleanup_loop(&shell);
		//shell.ast = parse_into_ast(shell.tokens);//					malloc = exit
		//free_tokens(shell.tokens);
		//if (ast_invalid(shell.ast)) //aucun tree
		//	continue ;
		//expand_ast(shell.ast);
		//resolve_heredocs(shell.ast);
		//executor(shell.ast);
		//free_ast(shell.ast);
	}
}

