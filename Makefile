build:
	g++ -Wall -std=c++17 -I"./libs/" src/*.cpp -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -llua -o game
check:
	ls -ls

run:
	./game

clean:
	rm game
