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
CPP= clang++
CPPFLAGS= -std=c++11 -Wall -Wextra -Werror -g -Wno-deprecated

SRC_DIR= src/
SRC= init/main.cpp\
	 event/processInput.cpp\
	 humanDraw/humanDraw.cpp
SRCS= $(addprefix $(SRC_DIR),$(SRC))

CLASS= Shader.cpp\
	   Vector3f.cpp\
	   Vector4f.cpp\
	   Matrix4.cpp\
	   Limb.cpp\
	   MatrixStack.cpp
CLASS_DIR= class/
CLASSES= $(addprefix $(CLASS_DIR),$(CLASS))

OBJ_DIR= obj/
OBJ= $(SRC:.cpp=.o)
OBJ += $(CLASSES:.cpp=.o)
OBJ_SUBDIRS= init event class humanDraw
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))

VPATH = $(SRC_DIR):$(CLASS_DIR)

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
	@ $(CPP) -o $@ ./glad/src/glad.c $(CPPFLAGS) $(OBJS) $(LIB)
# $(LIBFT)
	@echo "$(GREEN)$@ executable created$(WHITE)"

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o:%.cpp $(INCLUDES) Makefile
	@ $(CPP) -o $@ -c $< $(CPPFLAGS)
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
