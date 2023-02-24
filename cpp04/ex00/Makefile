CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = diamondtrap
SRCS = main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
