CC = g++
SRC = $(wildcard src/*.cpp src/include/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = bin
OBJDIR = obj

LINKTHINGS = -Llib/SFML -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -pthread -lX11 
INCLUDETHINGS = -Isrc/include/SFML -Isrc/include/

all: makeit makeobj main 

temp:
	echo $(OBJ)

makeit: 
	mkdir -p $(BIN)

makeobj:
	mkdir -p $(OBJDIR)

run:
	$(BIN)/out

main: $(OBJ)
	$(CC) $^ -o $(BIN)/out $(LINKTHINGS) 

%.o: %.cpp
	$(CC) -o $@ -c $< $(INCLUDETHINGS)

clean:
	rm -rf $(OBJ)
