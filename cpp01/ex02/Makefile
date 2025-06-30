NAME := brain
HEADERS :=
SRC := main.cpp
OBJ := $(SRC:%.cpp=%.o)
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror

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
