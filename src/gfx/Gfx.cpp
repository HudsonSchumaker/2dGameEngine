/*
	Windows 10 / 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "Gfx.h"

Gfx::~Gfx() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

Gfx* Gfx::getInstance() {
	if (instance == nullptr) {
		instance = new Gfx();
	}

	return instance;
}

void Gfx::setGfxContext() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	int n = SDL_GetNumVideoDisplays();
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);

	window = SDL_CreateWindow(
		Common::NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	SDL_Surface* iconSurface = IMG_Load("data/images/chesttile.png");
	SDL_SetWindowIcon(window, iconSurface);
	SDL_FreeSurface(iconSurface);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	SDL_ShowCursor(SDL_DISABLE);
}

SDL_Window* Gfx::getWindow() {
	return window;
}

SDL_Renderer* Gfx::getRenderer() {
	return renderer;
}

SDL_Texture* Gfx::createText(std::string path, std::string text, short size, SDL_Color color) {
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	return texture;
}

SDL_Texture* Gfx::loadTexture(std::string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	return texture;
}

SDL_Point Gfx::getTextureSize(SDL_Texture* texture) {
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	return size;
}

SDL_Rect Gfx::getTextureBounds(SDL_Texture* texture) {
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	SDL_Rect rect = { 0, 0, size.x, size.y };

	return rect;
}

SDL_FRect Gfx::getTextureFBounds(SDL_Texture* texture) {
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	SDL_FRect rect = { 0.0f, 0.0f, size.x, size.y };

	return rect;
}

void Gfx::drawTexture(int x, int y, int w, int h, SDL_Texture* texture) {
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Gfx::drawTexture(float x, float y, int w, int h, SDL_Texture* texture) {
	SDL_FRect rect = { x, y, w, h };
	SDL_RenderCopyF(renderer, texture, NULL, &rect);
}

void Gfx::drawTexture(int x, int y, int w, int h, float rotation, SDL_Texture* texture) {
	SDL_Rect dstRect = { x, y, w, h };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, rotationDeg, NULL, SDL_FLIP_NONE);
}

void Gfx::drawTexture(float x, float y, int w, int h, float rotation, SDL_Texture* texture) {
	SDL_FRect dstRect = { x, y, w, h };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyExF(renderer, texture, NULL, &dstRect, rotationDeg, NULL, SDL_FLIP_NONE);
}

void Gfx::drawTexture(int x, int y, int w, int h, float rotation, SDL_RendererFlip flip, SDL_Texture* texture) {
	SDL_Rect dstRect = { x, y, w, h };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, rotationDeg, NULL, flip);
}

void Gfx::drawTexture(float x, float y, int w, int h, float rotation, SDL_RendererFlip flip, SDL_Texture* texture) {
	SDL_FRect dstRect = { x, y, w, h };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyExF(renderer, texture, NULL, &dstRect, rotationDeg, NULL, flip);
}