/*
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class Gfx final {
private:
    inline static Gfx* instance;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Gfx() = default;
    ~Gfx();

public:
    static Gfx* getInstance();
    
    void setGfxContext();
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    SDL_Texture* createText(std::string fontName, std::string text, short size, SDL_Color color);
    SDL_Texture* loadTexture(std::string name);
    SDL_Point getTextureSize(SDL_Texture* texture);
    SDL_Rect getTextureBounds(SDL_Texture* texture);
    SDL_FRect getTextureFBounds(SDL_Texture* texture);
    void drawTexture(int x, int y, int w, int h, SDL_Texture* texture);
    void drawTexture(int x, int y, int w, int h, float r, SDL_Texture* texture);
    void drawTexture(int x, int y, int w, int h, float r, SDL_RendererFlip flip, SDL_Texture* texture);
    void drawTexture(float x, float y, int w, int h, SDL_Texture* texture);
    void drawTexture(float x, float y, int w, int h, float r, SDL_Texture* texture);
    void drawTexture(float x, float y, int w, int h, float r, SDL_RendererFlip flip, SDL_Texture* texture);
};
