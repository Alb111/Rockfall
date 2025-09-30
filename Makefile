# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -fsanitize=thread -g

# Directories
SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build

# Find all .c files
SRC = $(wildcard $(SRC_DIR)/*.c)
LIB = $(wildcard $(LIB_DIR)/*.c)

# Object files in build directory
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC) $(LIB)))

# Final executable
program: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lpthread

# Pattern rule: compile any .c from src or lib to build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Cleanup
clean:
	rm -rf $(BUILD_DIR) program

