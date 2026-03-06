# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 21:32:42 by palexand          #+#    #+#              #
#    Updated: 2026/03/06 21:35:04 by palexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC= main.cpp Bureaucrat.cpp
OBJ= $(SRC:.cpp=.o)
NAME= Bureaucrat

all: $(NAME)
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
