# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -fsanitize=thread -g

# Source files and objects
SRC = main.c game.c art.c display.c game_manager.c key_listener.c
OBJ = $(SRC:.c=.o)

# Final executable
program: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule: how to build .o from .c
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Cleanup
clean:
	rm -f $(OBJ) program
