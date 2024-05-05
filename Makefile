# Makefile

# Compiler
CXX = g++

# Compiler flags (sets the cpp version to 14)
CXXFLAGS = -Wall -std=c++14 -lgtest -lgtest_main -pthread

# Target executable
MAIN_TARGET = changeMaker	# The name of the main executable
TEST_TARGET = test			# The name of the test executable

# Source files
MAIN_SRCS = main.cpp changeMaker.cpp	# The main source files
TEST_SRCS = test.cpp changeMaker.cpp	# The test source files

# Object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)	# The main object files
TEST_OBJS = $(TEST_SRCS:.cpp=.o)	# The test object files

# make (all) command
all: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

# make test command
test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# make run command
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# make clean command
clean:
	$(RM) $(MAIN_OBJS) $(MAIN_TARGET) $(TEST_OBJS) $(TEST_TARGET)