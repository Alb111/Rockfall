# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g -fsanitize=thread

# Source files
SRCS = main.c gameArray.c binUtils.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Target executable name
TARGET = game

# Build rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

# Compile .c files into .o files
%.o: %.c game.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule (optional, removes compiled files)
clean:
	rm -f $(TARGET) $(OBJS)

