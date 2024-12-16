# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Output binary name
TARGET = game

# Source files
SRCS = src/main.cpp src/Game.cpp src/Player.cpp src/Map.cpp src/Room.cpp src/Item.cpp src/Utils.cpp src/Inventory.cpp src/Enemy.cpp

# Object files (optional, useful for larger projects)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET) $(OBJS)
