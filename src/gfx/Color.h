/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class Color final {
public:
    int r = 255, g = 255, b = 255, a = 255;
    
    Color() = default;
    Color(int r, int g, int b, int a);
    ~Color() = default;

    static Uint32 createRGBA(SDL_Color color);
    static Uint32 createRGBA(int r, int g, int b, int a);

    static Uint32 createARGB(SDL_Color color);
    static Uint32 createARGB(int a, int r, int g, int b);

    unsigned long getHex();
    static SDL_Color getRed();
    static SDL_Color getGreen();
    static SDL_Color getBlue();
    static SDL_Color getWhite();
    static SDL_Color getBlack();
    static SDL_Color getGray();
    static SDL_Color getOrange();
    static SDL_Color getYellow();
    static SDL_Color getPink();
    static SDL_Color getBrown();
};
