CC=c++
LIBS=-lSDL2
BIN=bin
SRC=src
TEST=test
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)
SRCS_NOT_MAIN=$(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))

main:
	$(CC) -o $(BIN)/main $(LIBS) $(SRCS)

tests:
	$(CC) -o $(TEST)/bin/test $(LIBS) $(TESTS) $(SRCS_NOT_MAIN)

clean:
	rm $(BIN)/*
