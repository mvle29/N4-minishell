/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:22:47 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 22:22:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(t_tokens *start, t_tokens *end)
{
	int i;

	i = 0;
	while (start && start != end)
	{
		if (start->token == WORD)
			i++;
		start = start->next;
	}
	return (i);
}

int	count_redirs(t_tokens *start, t_tokens *end)
{
	int	i;

	i = 0;
	while (start && start != end)
	{
		if (start->token != WORD)
			i++;
		start = start->next;
	}
	return (i);
}

int	get_redirs(t_ast **ast, t_tokens *start, t_tokens *end)
{
	t_tokens	*tmp;
	int	count;
	int	i;

	count = count_redirs(start, end);
	(*ast)->redirs[count] = NULL;
	i = 0;
	while (start && start != end && i < count)
	{
		if (start->token != WORD && start->token != PIPE)
		{
			(*ast)->redirs[i] = malloc(sizeof(t_redirs));
			if (!(*ast)->redirs[i])
			{
				while (--i && i >= 0)
					free((*ast)->redirs[i]);
				return (0);
			}
			(*ast)->redirs[i]->tokens = start;
			tmp = start;
			while (tmp->token != WORD)
				tmp = tmp->next;
			(*ast)->redirs[i]->file = tmp->lexeme;
			i++;
		}
		start = start->next;
	}
	return (1);
}

int	get_args(t_ast **ast, t_tokens *start, t_tokens *end)
{
	int	count;
	int	i;

	count = count_args(start, end);
	(*ast)->args[count] = NULL;
	i = 0;
	while (start && start != end && i < count)
	{
		if (start->token == WORD)
		{
			(*ast)->args[i] = start->lexeme;
			i++;
		}
		start = start->next;
	}
	return (1);
}
