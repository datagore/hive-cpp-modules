NAME := account
HEADERS := Account.hpp
SRC := tests.cpp Account.cpp
OBJ := $(SRC:%.cpp=%.o)
CXXFLAGS := -std=c++20 -Wall -Wextra -Werror -Wno-deprecated-declarations

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

check: all
	./$(NAME) | cut -d" " -f2- > a.log
	cat 19920104_091532.log  | cut -d" " -f2- > b.log
	diff a.log b.log
	rm a.log b.log

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re check
