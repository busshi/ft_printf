# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 14:41:14 by aldubar           #+#    #+#              #
#    Updated: 2021/03/23 23:18:26 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIB_DIR		=	libft/

SRCS_DIR	=	srcs/

LIB_SRCS	=	ft_strlen.c \
			ft_strdup.c \
			ft_strdup_nl.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_ischarset.c \
			ft_isblank.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_len_nbr.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_split.c \
			ft_islower.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_print_hex.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strlcpy.c \
			ft_strrev.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_print_list.c \
			ft_print_tab.c \
			ft_free_tab.c \
			get_next_line.c

SRCS		=	ft_printf.c \
			conversion.c \
			print_c.c \
			print_s.c \
			print_d.c \
			print_p.c \
			print_x.c \
			print_u.c

CC		=	@clang

CFLAGS		=	-Wall -Wextra -Werror

RM		=	rm -rf

LIB_OBJS	=	$(addprefix $(LIB_DIR), $(LIB_SRCS:.c=.o))

OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o))


$(NAME):	$(LIB_OBJS) $(OBJS)	
		@ar rcs $(NAME) $(LIB_OBJS) $(OBJS)
		@echo "Done !"

$(LIB_DIR)%.o:	$(LIB_DIR)%.c $(LIB_DIR)libft.h
		@$(CC) $(CFLAGS) -o $@ -c $< -I $(LIB_DIR)

all:		$(NAME)

bonus:		$(NAME)

test:		$(NAME) clean
		@echo "Compiling main.c ..."
		@$(CC) $(CFLAGS) main.c -L. -lftprintf && ./a.out

test2:		$(NAME) clean
		@echo "Compiling main2.c ..."
		@$(CC) main2.c -L. -lftprintf && ./a.out

clean:
		@$(RM) $(LIB_OBJS) $(OBJS)
		@echo "  ----  |      ----     -     |\    |  |  |\    |   ----"
		@echo " |      |     |        / \    | \   |  |  | \   |  |"
		@echo " |      |      ---    /___\   |  \  |  |  |  \  |  |  _ _"
		@echo " |      |     |      /     \  |   \ |  |  |   \ |  |    |"
		@echo "  ----   ----  ---- /       \ |    \|  |  |    \|   ----  °°°"

fclean:		clean
		@echo "Removing all files..."
		@$(RM) $(NAME) $(LIB_DIR)libft.a a.out
		@echo "fcleaned !"

re:		fclean all

.PHONY:		all clean fclean re test
