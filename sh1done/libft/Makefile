# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/16 16:34:17 by aiwanesk          #+#    #+#              #
#    Updated: 2015/06/16 16:55:51 by aiwanesk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDIR = ./includes/
SDIR = ./sources/
ODIR = ./objects/

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_count_digits.c\
	  ft_dec_to_bin.c\
	  ft_dec_to_hex.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_iscntrl.c\
	  ft_isdigit.c\
	  ft_isgraph.c\
	  ft_islower.c\
	  ft_isprint.c\
	  ft_ispunct.c\
	  ft_isspace.c\
	  ft_isupper.c\
	  ft_isxdigit.c\
	  ft_itoa.c\
	  ft_lstadd.c\
	  ft_lstcountelem.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstnew.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_er.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_er.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_er.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_er.c\
	  ft_putstr_fd.c\
	  ft_realloc.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strrev.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_swapc.c\
	  ft_swapi.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

SRC_C := $(addprefix $(SDIR), $(SRC))
SRC_O := $(addprefix $(ODIR), $(OBJ))

CC		=		clang
CFLAGS	=		-Wall -Werror -Wextra

RED = \033[31m
CYAN = \033[36m
NORMAL = \033[00m
GREY = \033[90m

.PHONY: clean fclean all re propre

all: $(NAME)

$(NAME): $(SRC_O)
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)
	@echo "$(CYAN)[$(NAME)]$(GREY) Library created.$(NORMAL)"

$(SRC_O): $(SRC_C)
	@$(CC) $(FLAGS) -c $(SRC_C) -I $(HDIR)
	@if [ -d $(ODIR) ]; then\
		echo "$(CYAN)[$(NAME)]$(GREY) Objects Directory already exists.$(NORMAL)";\
	else\
		mkdir $(ODIR);\
	fi
	@mv $(OBJ) $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(GREY) Objects created.$(NORMAL)"

clean:
	@rm -f $(SRC_O)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)[$(NAME)]$(RED) Executable deleted.$(NORMAL)"

propre: all clean

re: fclean all
