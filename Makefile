CXX = g++ # Or clang++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/board.cpp $(SRC_DIR)/cannon.cpp $(SRC_DIR)/counter.cpp $(SRC_DIR)/nail.cpp $(SRC_DIR)/obstacle.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

EXEC = $(BUILD_DIR)/main

ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
    RM = rmdir /S /Q $(BUILD_DIR)
else
    MKDIR = mkdir -p $(BUILD_DIR)
    RM = rm -rf $(BUILD_DIR)
endif

all: $(EXEC)

$(EXEC): $(OBJS)
	$(MKDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(MKDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM)

.PHONY: all clean
