CXX = c++
SRC = src
BIN = bin
BUILD = build
INCLUDE = include
CXXFLAGS = -I $(INCLUDE)

$(BIN)/a.out: $(BUILD)/main.o $(BUILD)/polygon.o $(BUILD)/display.o | bin
	$(CXX) $(CXXFLAGS) -o $@ $?

$(BUILD)/main.o: $(SRC)/main.cpp | build
	$(CXX) $(CXXFLAGS) -c -o $@ $?

$(BUILD)/polygon.o: $(SRC)/polygon.cpp $(INCLUDE)/thethring/polygon.h | build
	$(CXX) $(CXXFLAGS) -c -o $@ $(SRC)/polygon.cpp

$(BUILD)/display.o: $(SRC)/display.cpp $(INCLUDE)/thethring/display.h | build
	$(CXX) $(CXXFLAGS) -c -o $@ $(SRC)/display.cpp

bin:
	mkdir $@

build:
	mkdir $@

.PHONY: clean
clean:
	rm $(BIN)/*.out $(BUILD)/*.o

