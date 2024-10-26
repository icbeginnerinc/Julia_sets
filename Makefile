# Compiler
CXX = g++

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = objects

# Source files
SRCS_COMPLEX = $(SRC_DIR)/main_complex.cpp $(SRC_DIR)/complex.cpp
SRCS_CONVERGENCE = $(SRC_DIR)/main_convergence.cpp $(SRC_DIR)/complex.cpp

# Object files for complex program
OBJS_COMPLEX = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_COMPLEX))
# Object files for convergence program
OBJS_CONVERGENCE = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_CONVERGENCE))

# Output executables
TARGET_COMPLEX = $(OBJ_DIR)/complex_program
TARGET_CONVERGENCE = $(OBJ_DIR)/convergence_program

# Compiler flags
CXXFLAGS = -I$(INC_DIR) -Wall -Wextra -g -std=c++11

# Default target
all: $(TARGET_COMPLEX) $(TARGET_CONVERGENCE)

# Link the object files to create the complex executable
$(TARGET_COMPLEX): $(OBJS_COMPLEX)
	$(CXX) -o $@ $^

# Link the object files for the convergence executable
$(TARGET_CONVERGENCE): $(OBJS_CONVERGENCE)
	$(CXX) -o $@ $^

# Compile source files into object files for complex
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile source files into object files for convergence
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executables
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET_COMPLEX) $(TARGET_CONVERGENCE)

# Phony targets
.PHONY: all clean
