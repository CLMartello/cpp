# Flags #

NAME = zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

# Files #

OBJS_DIR := objs

CPPFILES = Zombie.cpp zombieHorde.cpp main.cpp

OBJS = $(CPPFILES:%.cpp=$(OBJS_DIR)/%.o)

# Configuration #

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $@
	@echo "Compiled objects."

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Compiled $(NAME)"

# Phonies #

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed program"

re: fclean all
