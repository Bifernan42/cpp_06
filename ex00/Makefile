CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD -MP
SRCS = srcs/main.cpp srcs/ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)
NAME = converter

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(DEPS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
