#include "infix_to_rpn.h"

/*
** note:	this function will browse an input infix string, and Return a
**			linked list of tokens.
*/

t_list *tokenize_infix(char *str)
{
	int i;
	int word_start;
	t_list *token_list;

	i = 0;
	token_list = NULL;
	word_start = 0;
	while (str[i])
	{
		if (is_in_grammar(str[i]))
		{
			if (i != word_start && \
					!close_word_token(&token_list, str, i, word_start))
				return (free_token_list(token_list));
			if (!close_operator_token(&token_list, str, i))
				return (free_token_list(token_list));
			word_start = i + 1;
		}
		i++;
	}
	if (word_start < i)
		if (!close_word_token(&token_list, str, i, word_start))
			return (free_token_list(token_list));
	return (token_list);
}

/*
** note:	this function will Return true if the character is part of the
**			"grammar", basically eiter one of the following char: +,-,*,/,^.
*/

int		is_in_grammar(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '('\
			|| c == ')')
		return (1);
	else
		return (0);
}

/*
** note:	this function will add a token of type operator to the token list
**
** note:	we get rid of the case when we have two consecutive minus signs
**			without a whitespace in between.
**
** intputs:	str, index, both give us the character we are at.
**
** RETURN:	1 OK
**			0 KO
*/

int		close_operator_token(t_list **token_list, char *str, int i)
{
	t_token *token;
	t_list	*new_link;

	if (!*token_list && str[i] != '(' && str[i] != ')')
		return (very_first_char_is_operator(token_list, str, i));
	if (!(token = malloc(sizeof(t_token))))
		return (0);
	if (str[i] == '(' || str[i] == ')')
	{
		if (str[i] == '(')
			token->type = L_BRACE;
		else
			token->type = R_BRACE;
		if (!(new_link = ft_lstnew(token)))
		{
			free(token);
			return (0);
		}
		ft_lstadd_back(token_list, new_link);
		return (1);
	}
	else
		return (close_operator_token_assist(token_list, str, i));
}

int	close_operator_token_assist(t_list **token_list, char *str, int i)
{
	t_list *new;

	if (!(new = creat_token_link_operator(str[i])))
		return (0);
	if (i != 0 && str[i - 1] == '-')
	{
		free(new->content);
		free(new);
		return (0);
	}
	ft_lstadd_back(token_list, new);
	return (1);
}

/*
** note:	this function will add a token that is not an operator to the
**			current token linked list. inputs are the token_list, the string
**			the current index in the string, the start index of the word in
**			the string.
**
** RETURN:	1 OK
**			0 failure
*/

int		close_word_token(t_list **token_list, char *str, int i, int start)
{
	char *word;
	t_list *new_link;

	if (iswhitespaces_only(str, start, i - start))
		return (1);
	if (!(word = ft_substr(str, start, i - start)))
		return (0);
	if (!(new_link = creat_token_link_operand_str(word)))
	{
		free(word);
		return (0);
	}
	ft_lstadd_back(token_list, new_link);
	return (1);
}
