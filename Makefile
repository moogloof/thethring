CXX = c++
SRC = src
BIN = bin
BUILD = build
INCLUDE = include
CXXFLAGS = -I $(INCLUDE)

$(BIN)/a.out: $(BUILD)/main.o $(BUILD)/polygon.o
	$(CXX) $(CXXFLAGS) -o $@ $?

$(BUILD)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $?

$(BUILD)/polygon.o: $(SRC)/polygon.cpp $(INCLUDE)/thethring/polygon.h
	$(CXX) $(CXXFLAGS) -c -o $@ $(SRC)/polygon.cpp

.PHONY: clean
clean:
	rm $(BIN)/*.out $(BUILD)/*.o

