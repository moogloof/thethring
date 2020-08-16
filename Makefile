CXX = c++
SRC = src
BIN = bin
BUILD = build

$(BIN)/a.out: $(BUILD)/main.o
	$(CXX) -o $@ $?

$(BUILD)/main.o: $(SRC)/main.cpp
	$(CXX) -c -o $@ $?

.PHONY: clean
clean:
	rm $(BIN)/*.out $(BUILD)/*.o

