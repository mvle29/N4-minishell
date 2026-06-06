/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:57:45 by marvin            #+#    #+#             */
/*   Updated: 2026/06/05 13:57:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tokens_error_syntax4(t_tokens *iterate)
{
	t_tokens	*tmp;
	char		*error;

	error = NULL;
	if (iterate->token == PIPE)
	{
		tmp = iterate->next;
		while (tmp && !error)
		{
			if (tmp->token == WORD)
				return (NULL);
			if (tmp->token == PIPE)
				error = "|";
			tmp = tmp->next;
		}
	}
	return (error);
}

char	*tokens_error_syntax3(t_tokens *iterate)
{
	t_mode	mode;
	char	*error;
	int		i;

	mode = NORMAL;
	error = NULL;
	i = 0;
	while (iterate->lexeme[i])
	{
		if ((iterate->lexeme[i] == '\"' && mode == DOUBLEQ) ||
		(iterate->lexeme[i] == '\'' && mode == SINGLEQ))
			mode = NORMAL;
		else if (iterate->lexeme[i] == '\'' && mode == NORMAL)
			mode = SINGLEQ;
		else if (iterate->lexeme[i] == '\"' && mode == NORMAL)
			mode = DOUBLEQ;
		i++;
	}
	if (mode == SINGLEQ)
		error = "'";
	if (mode == DOUBLEQ)
		error = "\"";
	return (error);
}

char	*tokens_error_syntax2(t_tokens *tokens, t_tokens *iterate)
{
	char		*error;

	error = NULL;
	if (iterate->token == PIPE && (iterate == tokens || !iterate->next))
		error = iterate->lexeme;
	else if ((iterate->token == LESSER || iterate->token == DLESSER)
		&& (!iterate->next || iterate->next->token != WORD))
		error = iterate->lexeme;
	else if ((iterate->token == GREATER || iterate->token == DGREATER)
		&& (!iterate->next || iterate->next->token != WORD))
		error = iterate->lexeme;
	return (error);
}

int	tokens_error_syntax(t_tokens *tokens)
{
	char		*error;
	t_tokens	*tmp;

	tmp = tokens;
	error = NULL;
	while (tmp && !error)
	{
		error = tokens_error_syntax2(tokens, tmp);
		if (error)
			break ;
		error = tokens_error_syntax3(tmp);
		if (error)
			break ;
		error = tokens_error_syntax4(tmp);
		if (error)
			break ;
		tmp = tmp->next;
	}
	if (error)
	{
		ft_printf("syntax error near token `%s`\n", error);
		return (1);
	}
	return (0);
}
