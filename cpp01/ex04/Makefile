NAME := replace
SRC := main.cpp

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
	@cp main.cpp copy.cpp
	@./$(NAME) copy.cpp "std::" "REDACTED::"
	@cat copy.cpp
	@rm copy.cpp

.PHONY: all clean fclean re test
.SECONDARY: $(OBJ) $(DEP) .build
-include $(DEP)
