NAME := RPN
SRC := main.cpp RPN.cpp

CXXFLAGS := -Wall -Wextra -Werror -std=c++20 -MMD -MP
OBJ := $(SRC:%.cpp=.build/%.o)
DEP := $(SRC:%.cpp=.build/%.d)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $^ -o $@

.build/%.o: %.cpp | .build
	c++ -c $< -o $@ $(CXXFLAGS)

.build:
	mkdir -p $@

clean:
	rm -rf .build

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	clear
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "7 7 * 7 -"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	./RPN "(1 + 1)"

.PHONY: all clean fclean re test
.SECONDARY: $(OBJ) $(DEP) .build
-include $(DEP)
