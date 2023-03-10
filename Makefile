# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:33:56 by mmariani          #+#    #+#              #
#    Updated: 2023/02/14 18:59:47 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher
CC = gcc -pthread
FLAGS = -g 
# -Wall -Wextra -Werror
# LINKS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS = philosopher.c utility.c action.c routine.c philthred.c mutex.c
OBJS = $(SRCS:.c=.o)

# LIBFT = ./libft/libft.a

# LIBFT_SRCS= libft/ft_isalpha.c		\
# 		libft/ft_isdigit.c		\
# 		libft/ft_isalnum.c		\
# 		libft/ft_isascii.c		\
# 		libft/ft_isprint.c		\
# 		libft/ft_strlen.c		\
# 		libft/ft_memset.c		\
# 		libft/ft_bzero.c		\
# 		libft/ft_memcpy.c		\
# 		libft/ft_memmove.c		\
# 		libft/ft_strlcpy.c		\
# 		libft/ft_strlcat.c		\
# 		libft/ft_toupper.c		\
# 		libft/ft_tolower.c		\
# 		libft/ft_strchr.c		\
# 		libft/ft_strrchr.c		\
# 		libft/ft_strncmp.c		\
# 		libft/ft_memchr.c		\
# 		libft/ft_memcmp.c		\
# 		libft/ft_strnstr.c		\
# 		libft/ft_atoi.c		\
# 		libft/ft_calloc.c		\
# 		libft/ft_strdup.c		\
# 		libft/ft_substr.c		\
# 		libft/ft_strjoin.c 	\
# 		libft/ft_strtrim.c 	\
# 		libft/ft_split.c		\
# 		libft/ft_itoa.c		\
# 		libft/ft_strmapi.c		\
# 		libft/ft_striteri.c	\
# 		libft/ft_putchar_fd.c	\
# 		libft/ft_putstr_fd.c	\
# 		libft/ft_putendl_fd.c	\
# 		libft/ft_putnbr_fd.c	\
# 		libft/get_next_line.c	\
# 		libft/get_next_line_utils.c \
# 		libft/ft_printstrmatrix.c	\
# 		libft/ft_freeintmatrix.c \
# 		libft/ft_freestrmatrix.c \
# 		libft/ft_lstnew.c			\
# 		libft/ft_lstadd_front.c	\
# 		libft/ft_lstsize.c		\
# 		libft/ft_lstlast.c		\
# 		libft/ft_lstadd_back.c	\
# 		libft/ft_lstdelone.c		\
# 		libft/ft_lstclear.c		\
# 		libft/ft_lstiter.c		\
# 		libft/ft_lstmap.c

# LIBFT_INC=libft/libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

# $(LIBFT): $(LIBFT_SRCS) $(LIBFT_INC)
# 	@$(MAKE) -C ./libft

# $(NAME): $(LIBFT) $(OBJS)
# 	$(CC) $(FLAGS) $(LINKS) $(LIBFT) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
clean:
	rm -f $(OBJS)
# make -C libft clean

fclean: clean
	rm -f $(NAME)
# rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
