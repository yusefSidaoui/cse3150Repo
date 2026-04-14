# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -g -Wall

# Target executable
TARGET = solution

# Source file
SRC = solution.cpp

# Default target
all: $(TARGET)

# Compile the program
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run tests
test: $(TARGET)
	pytest test_game.py

# Clean compiled files
clean:
	rm -f $(TARGET)
