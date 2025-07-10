CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = build/expense_tracker

all: $(BIN)

$(BIN): $(SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SRC)

clean:
	rm -rf build/*.o build/expense_tracker

run: all
	./build/expense_tracker
