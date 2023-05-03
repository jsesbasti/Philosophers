# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:21:25 by jsebasti          #+#    #+#              #
#    Updated: 2023/05/03 02:34:44 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
INC_DIR		= inc/
MKFL		= Makefile
OBJ_DIR		= obj/


# ----Libraryes----
PHILO_HEADE	= $(INC_DIR)/philo.h
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -O2 #-fsanitize=address
LIBC = ar -rcs
# =============

SRC	=	src/philo.c 				\
		src/parse.c					\
		src/utils.c					\
		src/utils_philo.c			\
		src/threading.c				\

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME)::
	@echo "Hello, Philo already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re
