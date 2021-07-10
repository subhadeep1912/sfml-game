CC = g++
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = bin

LINKTHINGS = -Llib/SFML -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
INCLUDETHINGS = -Isrc/include/SFML

all: makeit main clean

makeit: 
	mkdir -p $(BIN)

run:
	$(BIN)/out

main: $(OBJ)
	$(CC) $^ -o $(BIN)/out $(LINKTHINGS) 

%.o: %.cpp
	$(CC) -o $@ -c $< $(INCLUDETHINGS)

clean:
	rm -rf $(OBJ)
