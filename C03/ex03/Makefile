NAME = howWeird
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc #-g
RM = rm -rf

OBJDIR = obj

SRC = 	src/main.cpp \
		src/ClapTrap.cpp \
		src/ScavTrap.cpp \
		src/DiamondTrap.cpp \
		src/FragTrap.cpp \
		src/utils.cpp

OBJS = $(patsubst src/%, $(OBJDIR)/%, $(SRC:.cpp=.o))

DESIGN_MARKER = .design_running

all: $(NAME)

$(DESIGN_MARKER):
	@clear
	@bash src/generateGradient.cpp &
	@touch $(DESIGN_MARKER)

$(NAME): $(DESIGN_MARKER) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean 
	@$(RM) $(NAME) $(DESIGN_MARKER)

re: fclean all

.PHONY: all clean fclean re
