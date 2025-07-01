NAME := violence
HEADERS := Weapon.hpp HumanA.hpp HumanB.hpp
SRC := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ := $(SRC:%.cpp=%.o)
CXXFLAGS := -std=c++20 -Wall -Wextra -Werror

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
