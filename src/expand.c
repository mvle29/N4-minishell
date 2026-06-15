/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mat <mat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:33:10 by mat               #+#    #+#             */
/*   Updated: 2026/06/15 14:02:56 by mat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//start : "$USER is a fool" -> saber is a fool 

/*int expand_redirs(t_ast *ast, t_redirs **redirs)
{
    int i;

    i = 0;
    while (redirs[i])
    {
        if (redirs[i]->tokens->token == DLESSER)
        {
            if (!expand_hd(redirs))
                return (0);
        }
        else
        {
            if (!expand_file(redirs))
                return (0);
        }
        i++;
    }
    return (1);
}
//add_lst_expanded

int expand_args(t_ast *ast)
{
    while (start->)
    
}

int expand_recursive(t_ast *ast)
{
    if (ast->ast_type == AST_PIPE)
    {
        if (!expand_recursive(ast->left))
            return (0);
        if (!expand_recursive(ast->right))
            return (0);
        return (1);
    }
    if (!expand_redirs(ast, ast->redirs) || !expand_args(ast))
        return (0);
    return (1);
}
*/