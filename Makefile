# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -fsanitize=thread -I$(LIB_DIR)
LDFLAGS = -lpthread

# Directories
SRC_DIR = src
LIB_DIR = lib/chan
BUILD_DIR = build

# Find all .c files
SRC = $(wildcard $(SRC_DIR)/*.c)
LIB = $(wildcard $(LIB_DIR)/*.c)

# Convert to object file paths with subdirectories
SRC_OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/src_%.o,$(SRC))
LIB_OBJ = $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/lib_%.o,$(LIB))
OBJ = $(SRC_OBJ) $(LIB_OBJ)

# Final executable
program: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Pattern rule: compile any .c from src to build/src_*.o
$(BUILD_DIR)/src_%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Pattern rule: compile any .c from lib to build/lib_*.o
$(BUILD_DIR)/lib_%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Cleanup
clean:
	rm -rf $(BUILD_DIR) program

.PHONY: clean