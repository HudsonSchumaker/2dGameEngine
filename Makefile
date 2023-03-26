compile:
	g++ -Wall -std=c++17 -O3 -dynamiclib src/core/*.cpp src/ecs/*cpp src/ecs/system/*cpp src/gfx/*cpp src/physics/*cpp src/sfx/*cpp \
	-I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx -o libdodoiengine.dylib 
		
	mv -f libdodoiengine.dylib build/
	