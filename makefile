CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude

# Source and object files
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
DATA_DIR = data

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
BIN = $(BUILD_DIR)/expense_tracker

# Default target
all: setup $(BIN)

# Create necessary directories and files
setup:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(DATA_DIR)
	@touch $(DATA_DIR)/expenses.csv

# Build the main executable
$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build completed successfully!"

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
	@echo "Clean completed!"

# Run the application
run: $(BIN)
	./$(BIN)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: clean $(BIN)

# Check system architecture
arch-info:
	@echo "System Architecture: $(shell uname -m)"
	@echo "Compiler: $(shell $(CXX) --version | head -n1)"

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run the application"
	@echo "  debug    - Build with debug symbols"
	@echo "  arch-info - Show system architecture info"
	@echo "  help     - Show this help message"

# Declare phony targets
.PHONY: all setup clean run debug arch-info help