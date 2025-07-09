#define compiler
CXX = c++

# Define the compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra 

# Define the source files
SRCS = megaphone.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the executable file
TARGET = megaphone

# Define the rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Define the rule to build the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Define the rule to clean up the object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Define the rule to clean up the object files and executable
fclean: clean
	rm -f $(TARGET)

# Define the rule to recompile everything
re: fclean $(TARGET)

phony: clean fclean re
