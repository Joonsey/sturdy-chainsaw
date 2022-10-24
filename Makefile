CC=c++
LIBS=-L/usr/local/lib/ -lSDL2_image
BIN=bin
SRC=src
TEST=test
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)
SRCS_NOT_MAIN=$(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))


main: make-bin
	$(CC) -o $(BIN)/main $(LIBS) $(SRCS) `sdl2-config --cflags --libs`

tests: make-test-bin
	$(CC) -o $(TEST)/bin/test $(LIBS) $(TESTS) $(SRCS_NOT_MAIN) `sdl2-config --cflags --libs`

clean:
	rm -r -f $(BIN)/* \
	$(TEST)/$(BIN)/*

make-test-bin:
	mkdir -p $(TEST)/$(BIN)

make-bin:
	mkdir -p $(BIN)
