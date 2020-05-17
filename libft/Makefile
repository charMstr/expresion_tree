# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charmstr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 21:40:12 by charmstr          #+#    #+#              #
#    Updated: 2020/01/30 16:04:00 by charmstr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
########################## PARAMETERS #########################################
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a
.PHONY = clean fclean re all bonus
FT_H = ./libft.h
OBJ_PATH = ./objects/
INCLUDE_PATH = ./
I_FLAGS = -I $(INC_PATH)
###############################################################################

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

###############################################################################
########################## SOURCE FILES #######################################
# display
FILES += putchar_fd\
	putendl_fd\
	putnbr_fd\
	putstr_fd\
	putbits_fd\
	putbytes_fd\

# malloc / free
FILES += calloc\
	free\

# memory manipulation
FILES += bzero\
	memset\
	memccpy\
	memchr\
	memcmp\
	memcpy\
	memmove\
	swap\

# char ID related
FILES += isalnum\
	isalpha\
	isascii\
	isdigit\
	isprint\
	tolower\
	toupper\

# str
FILES += strlen\
	strcmp\
	strncmp\
	strchr\
	strrchr\
	strichr\
	stristr\
	strnstr\
	strlcat\
	strlcpy\
	strrev\
	atoi\
	size_num_base_signed\

# str + malloc
FILES += strdup\
	substr\
	strjoin\
	strcdel\
	strcadd\
	strappend\
	strtrim\
	itoa\
	itoa_base\
	strmapi\
	stringify\
	split\

# char** manipulation
FILES += array_dup\
	array_free\
	array_len\
	array_debug\
	array_add\
	array_to_lst\

# simple linked list
FILES += lstnew\
	lstadd_front\
	lstadd_back\
	lstadd_cmp\
	lstget_front\
	lstget_back\
	lstget_cmp\
	lstdel_front\
	lstdel_back\
	lstdel_cmp\
	lstuniq\
	lstclear\
	lstdelone\
	lstiter\
	lstiter_cmp\
	lstmap\
	lstsize\
	lstlast\
	lstfind\
	lstrev\
	lstsort\
	lstmerge\
	lstloop_proof\
	lst_to_dlst\

# double linked list
FILES += dlstnew\
	dlstadd_back\
	dlstadd_front\
	dlstfirst\
	dlstlast\
	dlstclear\
	dlstdelone\
	dlstdel_back\
	dlstdel_front\

FILE_NUMBER=87
FILE_COUNTER=0
SRC = $(patsubst %, $(OBJ_PATH)ft_%.c, $(FILES))
OBJ = $(SRC:.c=.o)
###############################################################################


###############################################################################
############################# RECEIPIES #######################################
all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "\n\t\t$(CREAT_FG)Created the $(OBJECTS_BG)$(BLACK_FG) $@ $(BLACK_BG)$(CREAT_FG) repository for $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG)$(CLEAR_COLOR)\n"

$(NAME): $(OBJ)
	@ar -src $@ $(OBJ)
	@echo "\n\t\t$(CREAT_FG)Library $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CREAT_FG) has been created.$(CLEAR_COLOR)\n"

$(OBJ): $(OBJ_PATH)%.o: %.c $(FT_H) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	$(eval FILE_COUNTER=$(shell echo $$(($(FILE_COUNTER)+1))))
	@echo " $(COUNTER_FG)[$(FILE_COUNTER)/$(FILE_NUMBER)] $(CREAT_FG)>>......... $@$(CLEAR_COLOR)"

clean:
	@echo "\t\t$(REMOVE_FG)deleting $(OBJECTS_BG)$(BLACK_FG)$(OBJ_PATH) $(BLACK_BG)$(REMOVE_FG) containing all the .o files for $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(CLEAR_COLOR)"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\t\t$(REMOVE_FG)deleting $(NAME_BG)$(BLACK_FG)$(NAME) $(BLACK_BG)$(REMOVE_FG)...$(CLEAR_COLOR)" 
	@rm -rf $(NAME)

re: fclean all
###############################################################################
