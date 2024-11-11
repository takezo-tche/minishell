NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

LIBS = -lreadline

SRCDIR = .
BUILTIN_DIR = execution
ENV_DIR = env

OBJDIR = obj

SRCS = $(SRCDIR)/main.c \
	   $(ENV_DIR)/set_env.c \
	   $(ENV_DIR)/env_utils.c \
	   $(BUILTIN_DIR)/ft_env.c 

OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

GRAY = \033[37m
GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo " "
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo " "
	@echo "$(GREEN)Compilation terminée -> $(NAME)$(RESET)"
	@echo " "
	@echo "$(GREEN)1 -> ./$(NAME)$(RESET)"
	@echo " "

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@) # Crée le répertoire cible dans OBJDIR si nécessaire
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY)Compilation de $< -> $@$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GRAY)Répertoire $(OBJDIR) supprimé$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GRAY)Exécutable $(NAME) supprimé$(RESET)"

re: fclean all

.PHONY: all clean fclean re
