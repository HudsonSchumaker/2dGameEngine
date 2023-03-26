/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include <set>
#include <map>
#include <list>
#include <array>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <utility>
#include <fstream>
#include <iostream>
#include <typeindex>
#include <algorithm>
#include <filesystem>
#include <functional>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <math.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_gamecontroller.h>

#define QUIT -1
#define AUDIO_FOLDER "data/audios/"
#define FONT_FOLDER "data/fonts/"
#define IMAGE_FOLDER "data/images/"
#define MAP_FOLDER "data/maps/"

#define SCREEN_WIDTH 1280
#define SCREEN_H_WIDTH SCREEN_WIDTH/2
#define SCREEN_HEIGHT 720
#define SCREEN_H_HEIGHT SCREEN_HEIGHT/2 

class Common final {
public:
    inline static const char NAME[] = "- -";

    constexpr static float FPS = 60.0f;
    constexpr static float FRAME_TIME_LENGTH = 1000.0f / FPS;
    constexpr static float PI = 3.141592f;
};