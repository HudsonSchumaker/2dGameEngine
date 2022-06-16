compile:
	g++ -Wall -std=c++17 -O3 -dynamiclib src/physics/*.cpp src/systems/*cpp \
	-I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx -o libdodoiengine.dylib 
		
	mv -f libdodoiengine.dylib build/
	