CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -g
SRCS = srcs/main.cpp srcs/Input.cpp srcs/common.cpp srcs/ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = converter

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
