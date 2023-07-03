CC = gcc -g3 -Wall -Wextra -Werror -MMD # -fsanitize=address

SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = dep

SRC_EXT = .c
OBJ_EXT = .o
DEP_EXT = .d


SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/signals.c

OBJS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:$(SRC_EXT)=$(OBJ_EXT)))


DEPS = $(patsubst $(SRC_DIR)/%,$(DEP_DIR)/%,$(SRCS:$(SRC_EXT)=$(DEP_EXT)))

SRCH_INCLDS = -Iincludes

RM = rm -rf
MKDIR = mkdir -p

RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m

NAME = minishell

all: $(NAME)

-include $(DEPS)

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
	@$(MKDIR) $(@D)
	@echo "$(GREEN)Compiling$(RESET) $<..."
	@$(CC) $(SRCH_INCLDS) -c $< -o $@


$(DEP_DIR)/%$(DEP_EXT): $(SRC_DIR)/%$(SRC_EXT)
	@$(MKDIR) $(@D)
	@echo "$(GREEN)Generating dependencies$(RESET) for $<..."
	@$(CC) $(SRCH_INCLDS) -MM -MT '$(OBJ_DIR)/$*$(OBJ_EXT)' $< -MF $@

$(NAME): $(OBJS)
	@echo "$(BOLD)Linking$(RESET) $(NAME)..."
	@$(CC) $(OBJS) -lreadline -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(NAME) has been compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning$(RESET) object files..."
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Cleaning$(RESET) dependencies..."
	@$(RM) $(DEP_DIR)

fclean: clean
	@echo "$(RED)Cleaning$(RESET) $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
