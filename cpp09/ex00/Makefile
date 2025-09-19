NAME					= btc
CC						= c++
CFLAGS					= -Wall -Werror -Wextra -std=c++98

incDir					= includes
objDir					= obj
GREEN					= \033[0;32m
RED						= \033[0;31m
RESET					= \033[0m
ARROW					= ✔

SRCS					= srcs/main.cpp srcs/BitcoinExchange.cpp
OBJS					= $(SRCS:%.cpp=$(objDir)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Making $(NAME)...$(RESET)"
	@$(CC) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Done $(ARROW)$(RESET)"

$(objDir)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(incDir) -c $< -o $@

clean:
	@echo "$(RED)Deleting $(objDir)...$(RESET)"
	@rm -rf $(objDir)
	@echo "$(RED)Done $(ARROW)$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Done $(ARROW)$(RESET)"

re: fclean all

.PHONY: all clean fclean re