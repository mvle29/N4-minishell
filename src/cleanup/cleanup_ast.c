/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:43:54 by marvin            #+#    #+#             */
/*   Updated: 2026/06/06 21:43:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ast(t_ast *ast)
{
	(void)ast;
}

void	cleanup_ast(t_shell *shell)
{
	if (shell->ast)
		free_ast(shell->ast);
	shell->ast = NULL;
}
