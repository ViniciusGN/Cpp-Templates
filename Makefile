#CXX = clang++  # OR
CXX = g++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra

SRCS = set_test.cpp
OBJS = $(SRCS:.cpp=.o)

EXEC = main
TEST_EXEC = test

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Comando específico para os testes, se aplicável
test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TEST_EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXEC) $(TEST_EXEC)

.PHONY: all clean
