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
	@./$(NAME) main.cpp "std::" "REDACTED::"
	@cat main.cpp.replace
	@rm main.cpp.replace

.PHONY: all clean fclean re test
.SECONDARY: $(OBJ) $(DEP) .build
-include $(DEP)
