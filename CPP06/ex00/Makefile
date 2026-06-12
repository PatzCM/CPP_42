CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
INCLUDES	= -I incs/

SRC		= srcs/main.cpp srcs/ScalarConverter.cpp
OBJ		= $(SRC:.cpp=.o)
NAME		= convert

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
