CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
NAME	= Array

all: $(NAME)
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
