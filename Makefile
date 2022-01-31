#clang++ -D V=0 main.cpp -I vector.hpp -o a

NAME = a
NAME2 = $(NAME)_stl

MAIN = main.cpp

HEADER_DIR =	./

SDIR =	./
ODIR =	./

#SRCS =	$(SDIR)main.cpp
HEADERS = $(HEADER_DIR)vector.hpp

OBJS =	$(patsubst $(SDIR)%.cpp, $(ODIR)%.o, $(SRCS))

CC = clang++
C_FLAGS = -Wall -Werror -Wextra -g -std=c++98
C_SANIT = -fsanitize=address

$(NAME):	$(OBJS) $(MAIN) $(HEADERS)
	$(CC) -I $(HEADERS) $(MAIN) $(OBJS) $(C_FLAGS) $(C_SANIT) $(L_FLAGS) -D V=1 -o $(NAME)
	$(CC) -I $(HEADERS) $(MAIN) $(OBJS) $(C_FLAGS) $(C_SANIT) $(L_FLAGS) -D V=0 -o $(NAME2)
	echo CONCLUIDO

$(ODIR)%.o: $(SDIR)%.cpp
#		#mkdir -p $(ODIR)
		$(CC) $(C_FLAGS) $(HEADERS) $(L_FLAGS) -c $< -o $@


all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	./$(NAME)

val:	$(OBJS)
	$(CC) $(OBJS) $(C_FLAGS) $(HEADERS) $(L_FLAGS) -o $(NAME)
	echo CONCLUIDO
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
