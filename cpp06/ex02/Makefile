CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = conversion
SRCS = Base.cpp \
	generate.cpp \
	identify.cpp \
	main.cpp

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
