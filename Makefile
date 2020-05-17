# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 17:46:05 by charmstr          #+#    #+#              #
#    Updated: 2020/02/20 21:00:12 by charmstr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
########################## COLOR CODES ########################################
REMOVE_FG = \033[38;5;196m 
CREAT_FG = \033[38;5;46m
BLACK_FG = \033[38;5;0m
BLACK_BG = \033[48;5;0m
CLEAR_COLOR = \033[m
NAME_BG = \033[48;5;39m 
OBJECTS_BG = \033[48;5;121m
COUNTER_FG = \033[38;5;121m
BONUS_BG = \033[48;5;219m
BONUS_FG = \033[38;5;219m
###############################################################################

############################ PARAMETERS #######################################
###############################################################################
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = rpn_calculator
IFLAGS = -I $(INCLUDE_PATH)
.PHONY: all clean fclean re break_implicit_r
LDFLAGS = -lft

LIBFT = libft/libft.a 
DEPENDENCIES = $(INCLUDES) $(LIBFT)
###############################################################################
###############################################################################


############################# OPTIONS #########################################
###############################################################################
ifeq ($(f), n)
CFLAGS 		=
VALGRIND 	=
else ifeq ($(f), f)
CFLAGS 		+=  -fsanitize=address,undefined -g3
VALGRIND 	=
else ifeq ($(f), v)
CFLAGS 		+= -g3
SHOW_LEAK 	= --show-leak-kinds=definite
VALGRIND 	= valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif
###############################################################################
###############################################################################


############################ PATHS ############################################
###############################################################################
OBJ_PATH = ./objects/
SRC_PATH = ./sources/
INCLUDE_PATH = ./includes/
LIB_PATH = -L ./libft/ 
###############################################################################
###############################################################################


########################### HEADER FILES ######################################
###############################################################################
H_FILES = infix_to_rpn\
			debug\
		  
INCLUDES := $(patsubst %, $(INCLUDE_PATH)%.h, $(H_FILES))
###############################################################################
###############################################################################


########################### SRC/OBJ FILES #####################################
###############################################################################
SRC_FILES = main\
			tokenize_infix\
			tokenize_infix2\
			debug_functions\
			parser\
			parser2\
			parser3\
			parser_creat_tokens\
			parser_atoi_operand\
			parser_infix_to_rpn\
			tree_build\
			tree_creat_nodes\
			tree_calculate\
			free_functions\
			
FILE_NUMBER=21
FILE_COUNTER=0
SRC = $(patsubst %, $(SRC_PATH)%.c, $(SRC_FILES))
OBJ = $(patsubst %, $(OBJ_PATH)%.o, $(basename $(notdir $(SRC))))
###############################################################################
###############################################################################

###############################################################################
############################# RECEIPIES #######################################
all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "\n\t\t$(CREAT_FG)Created the $(OBJECTS_BG)$(BLACK_FG) $@ $(BLACK_BG)$(CREAT_FG) repository for $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG)$(CLEAR_COLOR)\n"

$(NAME): $(DEPENDENCIES) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB_PATH) $(OBJ) -o $@ $(LDFLAGS)
	@echo "\n\t\t$(CREAT_FG)Binary $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG) has been created.$(CLEAR_COLOR)\n"
	@echo "\t\t$(CREAT_FG)used the flags: $(CFLAGS)$(CLEAR_COLOR)\n"

$(OBJ): $(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	$(eval FILE_COUNTER=$(shell echo $$(($(FILE_COUNTER)+1))))
	@echo " $(COUNTER_FG)[$(FILE_COUNTER)/$(FILE_NUMBER)] $(CREAT_FG)>>......... $@$(CLEAR_COLOR)"

$(LIBFT): break_implicit_r
	@make -C ./libft

break_implicit_r: 

clean:
	@echo "\t\t$(REMOVE_FG)deleting $(OBJECTS_BG)$(BLACK_FG)$(OBJ_PATH) $(BLACK_BG)$(REMOVE_FG) containing all the .o files for $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CLEAR_COLOR)"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\t\t$(REMOVE_FG)deleting $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(REMOVE_FG)...$(CLEAR_COLOR)" 
	@make fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all
###############################################################################
