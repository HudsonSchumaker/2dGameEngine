/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Color.h"

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

	//int n = SDL_GetNumVideoDisplays();
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);

	window = SDL_CreateWindow(
		Common::NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_SHOWN | SDL_WINDOW_METAL | SDL_WINDOW_ALLOW_HIGHDPI
	);

	//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	std::string icon = "icon.png";
	auto path = IMAGE_FOLDER + icon; 
	SDL_Surface* iconSurface = IMG_Load(path.c_str());
	SDL_SetWindowIcon(window, iconSurface);
	SDL_FreeSurface(iconSurface);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

SDL_Window* Gfx::getWindow() {
	return window;
}

SDL_Renderer* Gfx::getRenderer() {
	return renderer;
}

SDL_Texture* Gfx::createText(std::string fontName, std::string text, short size, SDL_Color color) {
	auto path = FONT_FOLDER + fontName;
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	return texture;
}

SDL_Texture* Gfx::loadTexture(std::string name) {
	auto path = IMAGE_FOLDER + name;
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
	SDL_FRect rect = { 0.0f, 0.0f, static_cast<float>(size.x), static_cast<float>(size.y) };

	return rect;
}

 void Gfx::showMouseCursor(bool value) {
	if(value) { SDL_ShowCursor(SDL_ENABLE); }
	else {SDL_ShowCursor(SDL_DISABLE); }
 }

void Gfx::drawTexture(int x, int y, int w, int h, SDL_Texture* texture) {
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Gfx::drawTexture(float x, float y, int w, int h, SDL_Texture* texture) {
	SDL_FRect rect = { x, y, static_cast<float>(w), static_cast<float>(h) };
	SDL_RenderCopyF(renderer, texture, NULL, &rect);
}

void Gfx::drawTexture(int x, int y, int w, int h, float rotation, SDL_Texture* texture) {
	SDL_Rect dstRect = { x, y, w, h };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, rotationDeg, NULL, SDL_FLIP_NONE);
}

void Gfx::drawTexture(float x, float y, int w, int h, float rotation, SDL_Texture* texture) {
	SDL_FRect dstRect = { x, y, static_cast<float>(w), static_cast<float>(h) };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyExF(renderer, texture, NULL, &dstRect, rotationDeg, NULL, SDL_FLIP_NONE);
}

void Gfx::drawTexture(int x, int y, int w, int h, float rotation, SDL_RendererFlip flip, SDL_Texture* texture) {
	SDL_Rect dstRect = { x, y, w, h };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, rotationDeg, NULL, flip);
}

void Gfx::drawTexture(float x, float y, int w, int h, float rotation, SDL_RendererFlip flip, SDL_Texture* texture) {
	SDL_FRect dstRect = { x, y, static_cast<float>(w), static_cast<float>(h) };
	float rotationDeg = rotation * 57.2958;
	SDL_RenderCopyExF(renderer, texture, NULL, &dstRect, rotationDeg, NULL, flip);
}

void Gfx::drawLine(int x0, int y0, int x1, int y1, SDL_Color color) {
    Uint32 pixelColor = Color::createRGBA(color.r, color.g, color.b, color.a);
    lineColor(renderer, x0, y0, x1, y1, pixelColor);
}

void Gfx::drawCircle(int x, int y, int radius, float angle, SDL_Color color) {
    Uint32 pixelColor = Color::createRGBA(color.r, color.g, color.b, color.a);
    circleColor(renderer, x, y, radius, pixelColor);
    lineColor(renderer, x, y, x + cos(angle) * radius, y + sin(angle) * radius, pixelColor);
}

void Gfx::drawCircle(int centerX, int centerY, int radius, SDL_Color color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	
	//draw
	int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawDashedCircle(int centerX, int centerY, int radius, int dashLength, SDL_Color color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	// draw
	const float PI = 3.141592f;
	const int totalSegments = radius * 2 * PI / dashLength;

    for (int i = 0; i < totalSegments; ++i) {
        double angle = 2 * PI * i / totalSegments;

        int x1 = centerX + radius * std::cos(angle);
        int y1 = centerY + radius * std::sin(angle);

        angle = 2 * PI * (i + 1) / totalSegments;

        int x2 = centerX + radius * std::cos(angle);
        int y2 = centerY + radius * std::sin(angle);

        if (i % 2 == 0) {
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Gfx::drawFillCircle(int x, int y, int radius, SDL_Color color) {
    Uint32 pixelColor = Color::createRGBA(color.r, color.g, color.b, color.a);
    filledCircleColor(renderer, x, y, radius, pixelColor);
}

void Gfx::drawRect(int x, int y, int width, int height, SDL_Color color) {
	Uint32 pixelColor = Color::createRGBA(color.r, color.g, color.b, color.a);
    lineColor(renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y - height / 2.0, pixelColor);
    lineColor(renderer, x + width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, pixelColor);
    lineColor(renderer, x + width / 2.0, y + height / 2.0, x - width / 2.0, y + height / 2.0, pixelColor);
    lineColor(renderer, x - width / 2.0, y + height / 2.0, x - width / 2.0, y - height / 2.0, pixelColor);
}

void Gfx::drawRect(int x, int y, int width, int height, float angle, SDL_Color color) {
	// Set the rotation center
	int centerX = x + width / 2;
	int centerY = y + height / 2;

	// Calculate the rotated coordinates of the rectangle corners
	int rotatedX1 = centerX + (x - centerX) * cos(angle * M_PI / 180.0) - (y - centerY) * sin(angle * M_PI / 180.0);
	int rotatedY1 = centerY + (x - centerX) * sin(angle * M_PI / 180.0) + (y - centerY) * cos(angle * M_PI / 180.0);

	int rotatedX2 = centerX + (x + width - centerX) * cos(angle * M_PI / 180.0) - (y - centerY) * sin(angle * M_PI / 180.0);
	int rotatedY2 = centerY + (x + width - centerX) * sin(angle * M_PI / 180.0) + (y - centerY) * cos(angle * M_PI / 180.0);

	int rotatedX3 = centerX + (x + width - centerX) * cos(angle * M_PI / 180.0) - (y + height - centerY) * sin(angle * M_PI / 180.0);
	int rotatedY3 = centerY + (x + width - centerX) * sin(angle * M_PI / 180.0) + (y + height - centerY) * cos(angle * M_PI / 180.0);

	int rotatedX4 = centerX + (x - centerX) * cos(angle * M_PI / 180.0) - (y + height - centerY) * sin(angle * M_PI / 180.0);
	int rotatedY4 = centerY + (x - centerX) * sin(angle * M_PI / 180.0) + (y + height - centerY) * cos(angle * M_PI / 180.0);

	// Render the rotated rectangle
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Set the rendering color
	SDL_RenderDrawLine(renderer, rotatedX1, rotatedY1, rotatedX2, rotatedY2);
	SDL_RenderDrawLine(renderer, rotatedX2, rotatedY2, rotatedX3, rotatedY3);
	SDL_RenderDrawLine(renderer, rotatedX3, rotatedY3, rotatedX4, rotatedY4);
	SDL_RenderDrawLine(renderer, rotatedX4, rotatedY4, rotatedX1, rotatedY1);

	Uint32 pixelColor = Color::createRGBA(color.r, color.g, color.b, color.a);
	filledCircleColor(renderer, centerX, centerY, 1, pixelColor);
}

void Gfx::drawFillRect(int x, int y, int width, int height, SDL_Color color) {
    Uint32 pixelColor = Color::createRGBA(color.r, color.g, color.b, color.a);
    boxColor(renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, pixelColor);
}

void Gfx::drawBox(SDL_Rect rect, SDL_Color color) {
	Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
