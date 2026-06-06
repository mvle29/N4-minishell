/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:38:41 by marvin            #+#    #+#             */
/*   Updated: 2026/06/05 14:38:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*typedef enum	e_token
{
	PIPE,
	GREATER,
	DGREATER,
	LESSER,
	DLESSER,
	EXPAND_VAR,
	DOUBLEQ,
	SINGLEQ,
	WORD,
	END,
	NONE,
}	t_token;*/
void	print_tokens(t_shell *shell)
{
	t_tokens	*tmp;
	char		*type;

	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->token == PIPE)
			type = "PIPE";
		else if (tmp->token == GREATER)
			type = "GREATER";
		else if (tmp->token == DGREATER)
			type = "DGREATER";
		else if (tmp->token == LESSER)
			type = "LESSER";
		else if (tmp->token == DLESSER)
			type = "DLESSER";
		else if (tmp->token == WORD)
			type = "WORD";
		else if (tmp->token == NONE)
			type = "NONE";
		printf("token_type: %s ; lexeme: %s\n", type, tmp->lexeme);
		tmp = tmp->next;
	}
}
