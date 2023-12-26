NAME					=	simple_templates
CC						=	c++
FLAGS					=	-Wall -Wextra -Werror -std=c++98
RM						=	rm -rf

### Directories ###
SRC_PATH = srcs/
OBJ_PATH = objs/
HEADER_PATH = includes/
### All sources ###
SOURCES		=	main.cpp
### All objects ###

SRCS = $(addprefix $(SRC_PATH),$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.o))
DEPS = $(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.d))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

all:	header tmp $(NAME)

tmp:
	@mkdir -p $(OBJ_PATH)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -o $(NAME)
	@echo "$(GREEN)Project compiled succesfully$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) -MMD $(FLAGS) -c -o $@ $< -I $(HEADER_PATH)
	@echo "$(CYAN)Creation of object file -> $(CYAN)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean :
	@echo "clean: $(GREEN)Cleaning object files$(NOC)"
	$(RM) $(OBJ_PATH)

fclean : clean
	@echo "fclean: $(GREEN)Cleaning executable$(NOC)"
	$(RM) $(NAME)

re : fclean all

header:
	clear
	@echo "$(CYAN) $$HEADER_PROJECT"

-include $(DEPS)

.PHONY: all clean fclean re

define HEADER_PROJECT

CPP MODULE 07/EX00

endef
export HEADER_PROJECT
