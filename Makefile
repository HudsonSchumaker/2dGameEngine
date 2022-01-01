# Variables

CC           = g++
C_FLAGS      = -Wall -Wfatal-errors
LANG_STD     = -std=c++17
INCLUDE_PATH = -I"./libs/"
SRC_FILES    = ./src/*.cpp      \
               ./src/ECS/*.cpp  \
               ./src/Game/*.cpp \
               ./src/Log/*.cpp  \
               ./src/Systems/*.cpp

LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -llua
OBJ_NAME     = engine 

build:
	$(CC) $(C_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME) 

check:
	ls -ls

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)

all:
	rm $(OBJ_NAME)
	$(CC) $(C_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)