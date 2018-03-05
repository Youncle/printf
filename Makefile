# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcarstoc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 15:33:38 by vcarstoc          #+#    #+#              #
#    Updated: 2018/03/01 15:33:44 by vcarstoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_printf.c \
		datasetup/datasetup.c \
		datasetup/datasetup2.c \
		format/format_double.c \
		format/format_double2.c \
		format/format_num.c \
		format/ft_dtoa.c \
		format/insert_format.c \
		pad/pad_hex.c \
		pad/pad_num.c \
		pad/pad_oct.c \
		pad/pad_switch.c \
		pad/padcs.c \
		parse/parse_double.c \
		parse/parse_num.c \
		parse/parse_switch.c \
		parse/parse_str.c \
		parse/parse_zjt.c \
		parse/parse_unum.c 
SRC	=	$(addprefix srcs/, $(FILES))
OBJ	=	$(SRC:.c=.o)

INC	=	./includes
LIBFT	=	./libft

CC	=	gcc
AR	=	ar
ARFLAGS	=	rcs

ifdef FLAGS
    ifeq ($(FLAGS), no)
        CFLAGS	= 
    endif
    ifeq ($(FLAGS), debug)
        CFLAGS	= -Wall -Wextra -Werror -g
    endif
else
    CFLAGS      = -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@$(AR) r $(NAME) $(OBJ)
	@echo "Merged libft.a into libftprintf.a"

%.o: %.c
	@$(CC) -o $@ $(CFLAGS) -I $(INC) -c $<
	@echo "Building: $@"

clean:
	@/bin/rm -f $(OBJ)
	@echo "Deleted ft_printf objects"
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Deleted libftprintf.a"
	@make -C $(LIBFT) fclean

re: fclean all


