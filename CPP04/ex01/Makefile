NAME = animals

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp \
		WrongCat.cpp Brain.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Test target builds separate executable using the test file
tester: $(filter-out main.cpp,$(SRCS)) tests/tester_ex01.cpp
	$(CXX) $(CXXFLAGS) -I. -o tester $(filter-out main.cpp,$(SRCS)) tests/tester_ex01.cpp

# Run with: make tester && ./tester
# Then check memory:
# valgrind --leak-check=full ./tester   (Linux)
# leaks -atExit -- ./tester             (macOS)

.PHONY: all clean fclean re tester
