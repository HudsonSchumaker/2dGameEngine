/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "SplashScreen.h"
#include "gfx/AssetManager.h"

SplashScreen::SplashScreen() : Scene() {}

SplashScreen::~SplashScreen() {
	unload();
}

void SplashScreen::load() {
	logoTexture = AssetManager::getInstance()->getTexture("logo");
	SDL_Point size = Gfx::getInstance()->getTextureSize(logoTexture);
	rect = { 
		SCREEN_H_WIDTH - (size.x / 2) - 20,  // x
		SCREEN_H_HEIGHT - (size.y / 2) - 20, // y
		size.x,                              // w 
		size.y                               // h
	};
	isRunning = true;
}

short SplashScreen::run() {
	load();
	render();
	auto controller = SDL_GameControllerOpen(0);
	if (controller) {
		std::cout << "Joystick name: " << SDL_GameControllerName(controller) << std::endl;
	}
	input();
	
	SDL_GameControllerRumble(controller, 0xFFFF * 0.300, 0xFFFF * 0.800, 88);
	while (isRunning) {
		input();
		update();
		render();
	}
	SDL_GameControllerClose(controller);
	return exit;
}

void SplashScreen::input() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			exit = QUIT;
			break;
		}
	}
}

void SplashScreen::update() {
	static char times = 0;
	SDL_Delay(499);
	times++;
	if (times > 4) {
		isRunning = false;
	}
}

void SplashScreen::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
	SDL_RenderPresent(renderer);
}

void SplashScreen::unload() {
	SDL_DestroyTexture(logoTexture);
}