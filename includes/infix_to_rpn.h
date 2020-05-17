#ifndef INFIX_TO_RPN_H
# define INFIX_TO_RPN_H


# include <stdio.h>
# include "../libft/libft.h"

typedef enum {ADD = '+', SUB = '-', DIV = '/', MUL = '*', EXP = '^'} type_op;

typedef enum { OPERAND_NODE, OPERATOR_NODE
} t_tag;

typedef struct	s_bc_nodes
{
	t_tag tag;
	union {
		int		integer;
		struct {
			type_op	op;
			struct s_bc_nodes *left;
			struct s_bc_nodes *right;
		}		operator_exp;
	}			taged;
}				t_bc_nodes;

typedef struct	s_token
{
	enum {
		OPERAND_STR,
		OPERAND_INT,
		OPERATOR,
		L_BRACE,
		R_BRACE
	} 			type;
	union {
		char	*operand_str;
		int		operand_int;
		type_op	op;
	}			thing;
}				t_token;

# include "debug.h"

t_list		*tokenize_infix(char *str);
int			close_operator_token(t_list **token_list, char *str, int i);
int			close_operator_token_assist(t_list **token_list, char *str, int i);
int			close_word_token(t_list **token_list, char *str, int i, int start);
int			is_in_grammar(char c);

void		*free_token_list(t_list *token_list);
void		free_link_and_token(t_list *token);
void 		free_token_content(void *token);

int			iswhitespaces_only(char *str, int start, int len);
t_list		*creat_token_link_operator(char operator);
t_list		*creat_token_link_operand_str(char *str);
int			very_first_char_is_operator(t_list **token_list, char *str, int i);

int			parser(t_list **tokens);
int			parser_assist1(t_list *tokens);
int			parser_2_op_in_a_row(t_list *tokens);
int			parser_next_to_operator(t_token *current, t_token *next);
int			parser_next_to_non_operator(t_token *current, t_token *next);

int			parser_assist2(t_list **tokens);
int			is_combo_add_sub(t_list *tokens, int *first_is_add);

int			parser_assist3(t_list *tokens);
int			is_operator_sub_combo(t_list *link, int *situation);
int			op_sub_combo_situation1(t_list *token);
int			op_sub_combo_situation2(t_list *token);
t_list		*find_matching_right_brace(t_list *tokens);

int			parser_assist4(t_list *tokens);
int			is_lbrace_sub_combo(t_list *tokens);

t_list		*create_link_with_minus_one_token(void);
t_list		*create_link_with_rbrace_token(void);
t_list		*create_link_with_mul_token(void);

int			valid_opstr(char *str);
int			parser_operand_str(t_list *tokens);
void		operand_str_to_int(t_token *token);


t_list		*parser_infix_to_rpn(t_list **tokens);
int			unpile_stack_to_rpn(t_list *stack, t_list **rpn);
int			infix_to_rpn_braces(t_list **tokens, t_list **rpn, t_list **stack);
void		infix_to_rpn_operator(t_list **tokens, t_list **rpn, \
		t_list **stack);


t_bc_nodes	*build_tree(t_list **token_list);
void		free_tree(void *node);
int			consume_token(t_list *link, t_list **stack);
int			add_node_operator_to_stack(t_list **stack, type_op op);
int			add_node_operand_to_stack(t_list **stack, int operand);
t_bc_nodes	*creat_operand_node(int operand);
t_bc_nodes	*creat_operator_node(type_op op, t_bc_nodes* right, \
		t_bc_nodes* left);

int			calculate_tree(t_bc_nodes *root);
int			calculate_operator(type_op op, int left, int right);
#endif
