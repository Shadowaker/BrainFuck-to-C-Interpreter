AUTHOR = Dan
NAME = bf
FLAGS = -Wextra -Werror -Wall

all:
	@gcc $(FLAGS) main.c uti/*.c -o $(NAME)
	@echo "\033[92m $(NAME) compiled! \033[0m by $(AUTHOR)"

clean:
	rm -f $(NAME)
