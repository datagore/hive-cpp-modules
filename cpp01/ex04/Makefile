NAME := replace
HEADERS :=
SRC := main.cpp
OBJ := $(SRC:%.cpp=%.o)
CXXFLAGS := -Wall -Wextra -Werror

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

test: all
	cp main.cpp copy.cpp
	./$(NAME) copy.cpp "std::" "REDACTED::"
	cat copy.cpp
	rm copy.cpp

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re test
.SILENT: test
