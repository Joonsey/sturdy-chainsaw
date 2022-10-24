CC=c++
LIBS=-L/usr/local/lib/ -lSDL2_image
BIN=bin
SRC=src
TEST=test
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)
SRCS_NOT_MAIN=$(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))

sdl2-config= $$(sdl2-config --cflags --libs)


main: make-bin
	$(CC) -o $(BIN)/main $(SRCS) $(sdl2-config) $(LIBS)

tests: make-test-bin
	$(CC) -o $(TEST)/bin/test $(SRCS_NOT_MAIN) $(TESTS) $(sdl2-config) $(LIBS)

clean:
	rm -r -f $(BIN)/* \
	$(TEST)/$(BIN)/*

make-test-bin:
	mkdir -p $(TEST)/$(BIN)

make-bin:
	mkdir -p $(BIN)
