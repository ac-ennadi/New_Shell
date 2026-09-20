# Program file name
NAME	= minishell

# Compiler and compilation flags
CC		= clang
CFLAGS	= -Werror -Wextra -Wall
CXX		= clang++
CXXFLAGS	= -Werror -Wextra -Wall

# Build files and directories
OBJ_PATH = ./objects/
CPP_SRC := $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
CPP_OBJS := $(patsubst %.cpp,$(OBJ_PATH)%.o,$(CPP_SRC))
C_SRC := $(wildcard src/*.c src/*/*.c src/*/*/*.c)
C_OBJS := $(patsubst %.c,$(OBJ_PATH)%.o,$(C_SRC))
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
	$(CXX) $(CXXFLAGS) -Wno-writable-strings -c $< -o $@ $(INC)

# C objects rule
$(OBJ_PATH)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(CPP_OBJS) $(C_OBJS)
	$(CXX) $(CXXFLAGS) $(CPP_OBJS) $(C_OBJS) -o $@ $(INC) $(LIBFT) -l readline

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
