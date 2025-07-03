NAME := DiamondTrap
SRC := \
	src/ClapTrap.cpp \
	src/DiamondTrap.cpp \
	src/FragTrap.cpp \
	src/ScavTrap.cpp \
	src/main.cpp \

CXXFLAGS := -Wall -Wextra -Werror -Iinc -std=c++20 -MMD -MP
OBJ := $(SRC:src/%.cpp=.build/%.o)
DEP := $(SRC:src/%.cpp=.build/%.d)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $^ -o $@

.build/%.o: src/%.cpp | .build
	c++ -c $< -o $@ $(CXXFLAGS)

.build:
	mkdir -p $@

clean:
	rm -rf .build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) $(DEP) .build
-include $(DEP)
