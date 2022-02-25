# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 10:30:01 by iderighe          #+#    #+#              #
#    Updated: 2022/02/24 12:15:07 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

#PATH_O	=	Objects/
INC		=	Includes/minishell.h

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I Includes
CFA		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -rf

LIB		=	-L./Libft -lft -L./local/lib -lreadline -lcurses

vpath %.c Srcs #va chercher les fichiers .c dans ts les dossiers repertories

SRC		=	Srcs/main_bis.c \
			Srcs/builtin.c \
			#Srcs/main.c \

OBJ		=	$(SRC:Srcs/%.c=Objects/%.o)

#OBJS	=	$(addprefix $(PATH_O), $(OBJ))


all		:	$(NAME)

$(NAME)	:	libft obj $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

libft	:
			$(MAKE) -C Libft

obj		:	
			mkdir -p Objects

Objects/%.o		:	%.c $(INC)
			$(CC) -o $@ -c $< $(CFLAGS)

norm	:
			norminette $(SRC)
			norminette $(INC)
			$(MAKE) -C Libft norm

clean	:
			$(RM) $(OBJ)
			$(RM) Objects
			$(MAKE) -C Libft clean

fclean	:	clean
			$(RM) $(NAME)
			$(MAKE) -C Libft fclean

fsa		:	libft obj $(OBJ)
			$(CC) $(CFLAGS) $(CFA) -o $(NAME) $(SRC) $(LIB)

re		:	fclean all

.PHONY	:	all libft norm clean fclean fsa re
