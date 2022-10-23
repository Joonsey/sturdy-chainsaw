CC=c++
LIBS=-lSDL2
BIN=bin
SRC=src
TEST=test
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)

main:
	$(CC) -o $(BIN)/main $(LIBS) $(SRCS) 

test:
	$(CC) -o $(TEST)/bin/test $(LIBS) $(TEST)

clean:
	rm $(BIN)/*
