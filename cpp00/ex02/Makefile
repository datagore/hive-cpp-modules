NAME := account
HEADERS := Account.hpp
SRC := tests.cpp Account.cpp
OBJ := $(SRC:%.cpp=%.o)
CXXFLAGS := -Wall -Wextra -Werror -Wno-deprecated-declarations

all: $(NAME)

$(NAME): $(OBJ)
	c++ $^ -o $@

%.o: %.cpp $(HEADERS)
	c++ -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re
