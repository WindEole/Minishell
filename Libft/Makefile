# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 12:23:59 by iderighe          #+#    #+#              #
#    Updated: 2022/02/23 15:35:01 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_split.c \
			ft_split_add.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_putstr_fd.c \
			ft_strcmp.c \
			ft_strncmp.c \

SRCS_B	=	ft_atoi.c \
			ft_atoi_base.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_convert_base.c \
			ft_div_mod.c \
			ft_is_negative.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_print_alphabet.c \
			ft_print_comb.c \
			ft_print_numbers.c \
			ft_print_reverse_alphabet.c \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putnbr_base.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putstr_non_printable.c \
			ft_putstr.c \
			ft_str_is_alpha.c \
			ft_str_is_lowercase.c \
			ft_str_is_numeric.c \
			ft_str_is_printable.c \
			ft_str_is_uppercase.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlowcase.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strtrim.c \
			ft_strupcase.c \
			ft_substr.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \

OBJ		=	$(SRCS:.c=.o)

#OBJ_B	=	$(SRCS_B:.c=.o)

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f



all		:	$(NAME)

.c.o	:	
			$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJ)
			ar rcs $(NAME) $(OBJ)

#bonus	:	$(OBJ) $(OBJ_B)
#			ar rcs $(NAME) $(OBJ) $(OBJ_B)

clean	:	
			$(RM) $(OBJ) #$(OBJ_B)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
