# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:03:44 by jmoucach          #+#    #+#              #
#    Updated: 2020/02/13 14:10:58 by acostaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= HumanGL
C++ = g++
CFLAGS= -Wall -Wextra -Werror -g

SRC_DIR= src/
SRC= init/main.cpp\
	 event/processInput.cpp
SRCS= $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR= obj/
OBJ= $(SRC:.cpp=.o)
OBJ_SUBDIRS= init event
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))

# LIBFT=libft/libft.a
LIB= -lglfw\
	 -ldl\
	 -lm
INCLUDES=	hdr/HumanGL.hpp

###############################################################################
#								Rules										  #
###############################################################################

all: $(SUBDIRS) 
#	@ make all -C libft
	@ make -j $(NAME)

$(NAME): $(OBJS)
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ $(C++) -o $@ glad/src/glad.c $(CFLAGS) $(OBJS) $(LIB) 
# $(LIBFT)
	@echo "$(GREEN)$@ executable created$(WHITE)"

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INCLUDES) Makefile
	@ $(C++) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "$(YELLOW)Deleting objects$(WHITE)"
	@ for i in $(OBJ); do \
		echo "$(RED)- Deleting $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(LIBFT)
	@ echo "$(YELLOW)Deleting obj directory$(WHITE)"
	@ rm -rf obj
	@ echo "$(GREEN)Obj directory deleted$(WHITE)"
	@ echo "$(GREEN)Executable deleted$(WHITE)"
	@ rm -rf $(NAME)

re: fclean all

FORCE:

.PHONY: all re fclean clean
