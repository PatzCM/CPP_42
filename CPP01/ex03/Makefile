NAME = weapon

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@$(RM) $(NAME)

re: fclean all
	@echo "Rebuilding all..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


.PHONY: all clean fclean re

