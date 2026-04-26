# Flags #

NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

# Files #

OBJ_DIR = objs

SRC_DIR = src

FILES = Contact.cpp PhoneBook.cpp main.cpp

SRC := $(addprefix $(SRC_DIR)/,$(FILES))

OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.cpp=.o))

# Configuration #

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Compiled objects."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled $(NAME)."

test: $(NAME)
	@./test/add_8_contacts.sh
	
# Phonies #

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed program"

re: fclean all

.PHONY: all clean fclean re
