# Program file name
NAME	= newshell

# Compiler and compilation flags
CC		= clang
CXX		= clang++
CXXFLAGS	= -Werror -Wextra -Wall

# Build files and directories
OBJ_PATH = ./objects/
CPP_SRC := $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
CPP_OBJS := $(patsubst %.cpp,$(OBJ_PATH)%.o,$(CPP_SRC))
INC		= -I ./include -I $(LIBFT_PATH)

# Libft files and directories
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a

# Main rule
all: $(OBJ_PATH) $(LIBFT) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# C++ objects rule
$(OBJ_PATH)%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(CPP_OBJS)
	$(CXX) $(CXXFLAGS) $(CPP_OBJS) -o $@ $(INC) $(LIBFT) -l readline

# Libft rule
$(LIBFT):
	make -C $(LIBFT_PATH)

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

# Remove program executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean
.SECONDARY:
