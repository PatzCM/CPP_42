NAME = PhoneBook

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98
DEPS =

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS) $(DEPS)
	$(CXX) $(OBJS) $(DEPS) -o $(NAME)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
