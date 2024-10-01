# Variables
CC = gcc               # Compiler to use
CFLAGS = -Wall -g      # Compilation flags (warnings and debug info)
TARGET = Rockfall      # Name of the final executable
SRC = Rockfall.c Print.c       # Source file(s)

# Default target to build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean target to remove the compiled files
clean:
	rm -f $(TARGET)

# Rebuild the project
rebuild: clean $(TARGET)
