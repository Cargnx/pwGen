# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -g -O1 -std=c11 -I$(INC_DIR)
LDFLAGS =  # Add linker flags here (e.g., -lm for math library)

# Directories
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include

# Target executable name
TARGET = $(BUILD_DIR)/main

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPENDS = $(OBJECTS:.o=.d)

# Default target
all: $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files to create executable
$(TARGET): $(BUILD_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile .c files to .o files with automatic dependency generation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Include dependency files (for header tracking)
-include $(DEPENDS)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Rebuild everything from scratch
rebuild: clean all

.PHONY: all run clean rebuild help