CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		  RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ		= $(SRC:.cpp=.o)
NAME	= AForm

all: $(NAME)
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
