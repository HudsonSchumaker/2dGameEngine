compile:
	g++ -Wall -std=c++17 -O3 -dynamiclib src/physics/*.cpp -o libdodoiengine.dylib 
	mv -f libdodoiengine.dylib build/
	