# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:21:25 by jsebasti          #+#    #+#              #
#    Updated: 2023/07/09 20:41:04 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
INC_DIR		= inc/
OBJ_DIR		= obj/
SRC_DIR		= src/


# ----Libraryes----
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -g -O2 #-fsanitize=thread

# =============

UTILS =	utils/ft_calloc.c		\
		utils/ft_atoi.c			\
		utils/ft_isdigit.c		\
		utils/ft_strlen.c		\
		utils/ft_strisdigit.c	\
		utils/ft_putstr_fd.c

TIME =	time/utils_philo.c

THREADING = threading/threading.c	\
			threading/philo.c

INIT =	init/parse.c \
		init/initialize.c

SRC	=	$(addprefix $(SRC_DIR), $(UTILS))	\
		$(addprefix $(SRC_DIR), $(TIME))	\
		$(addprefix $(SRC_DIR), $(THREADING)) \
		$(addprefix $(SRC_DIR), $(INIT))

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.c
	@$(MP) $(dir $@)
	$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@

all:
	@$(MAKE) $(NAME) --no-print-directory

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
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) --no-print-directory

.PHONY: all clean fclean re
