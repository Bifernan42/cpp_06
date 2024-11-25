NAME = random
SRCS = srcs/Base.cpp srcs/main.cpp srcs/functions.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

class :
	@chmod +x ../.cgen.sh
	@cd includes/ && ../../.cgen.sh

.PHONY: all clean fclean re

