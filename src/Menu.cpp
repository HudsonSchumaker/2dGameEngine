
#include "Menu.h"
#include "gfx/Box.h"
#include "gfx/Circle.h"
#include "gfx/Color.h"
#include "gfx/Sprite.h"
#include "event/EventBus.h"
#include "ecs/EntityManager.h"
#include "ecs/component/Button.h"
#include "event/MouseClickEvent.h"
#include "ecs/component/TextLabel.h"
#include "ecs/component/Transform.h"
#include "ecs/component/RigidBody.h"
#include "ecs/component/SpriteText.h"

Menu::Menu() {}

Menu::~Menu() {
    unload();
}

void Menu::load() {
   /* background = EntityManager::getInstance()->createEntity(0, 0);
	background->tag = Tag::background;
    background->addComponent(new Sprite("back129", true, Tags::getLayer(Tag::background)));
    background->getComponent<Sprite>()->setOnCenterX();

    title = EntityManager::getInstance()->createEntity(350, 0);
    title->addComponent(new TextLabel("HemiHead.ttf", true, title->getComponent<Transform>()->position, "Only One dodoi engine", 60, Color::getRed()));
    title->getComponent<TextLabel>()->setOnCenterX();
*/
	button = EntityManager::getInstance()->createEntity(352, 360);
	button->tag = Tag::ui;
	//button->addComponent(new Sprite("hard", true, Tags::getLayer(Tag::ui)));
	button->addComponent(new Box(32, 32, Tags::getLayer(Tag::ui), true));
	button->addComponent(new BoxCollider(button->getComponent<Box>()->getSize()));
	button->addComponent(new Button()); 
	button->addComponent(new TextLabel("HemiHead.ttf", true, button->getComponent<Transform>()->position, "T", 12, Color::getRed()));
   
    auto label = button->getComponent<TextLabel>();
	auto bt = button->getComponent<Button>();
	auto tr = button->getComponent<Transform>();
	label->position.x = tr->position.x + 16 - (label->w/2);
    label->position.y= tr->position.y + 16 - (label->h/2);

	 bt->hover = 0;
	bt->setCallback([&](int value) {
        buttonHard(value);
	});

	button2 = EntityManager::getInstance()->createEntity(100, 360);
	button2->tag = Tag::ui;
	//button->addComponent(new Sprite("hard", true, Tags::getLayer(Tag::ui)));
	button2->addComponent(new Box(32, 32, Tags::getLayer(Tag::ui), true));
	button2->addComponent(new BoxCollider(button->getComponent<Box>()->getSize()));
	button2->addComponent(new Button()); 
	button2->addComponent(new TextLabel("HemiHead.ttf", true, button2->getComponent<Transform>()->position, "T", 12, Color::getRed()));
   
    auto label2 = button2->getComponent<TextLabel>();
	auto bt2 = button2->getComponent<Button>();
	auto tr2 = button2->getComponent<Transform>();
	label2->position.x = tr2->position.x + 16 - (label2->w/2);
    label2->position.y= tr2->position.y + 16 - (label2->h/2);

	bt2->hover = 0;
	bt2->setCallback([&](int value) {
        buttonHard(value);
	});

	for(int i = 1; i < 11; i++) {
		auto enemy = EntityManager::getInstance()->createEntity(0, i * 42);
		enemy->tag = Tag::ui;
		enemy->addComponent(new RigidBody(0.1f + i, 0.0f));
		//enemy->addComponent(new Box(32, 32, Tags::getLayer(Tag::ui), true));
		//enemy->addComponent(new Sprite("hard", true, Tags::getLayer(Tag::ui)));
		enemy->addComponent(new Circle(9, Tags::getLayer(Tag::ui), false, Color::getRed()));
		enemy->addComponent(new BoxCollider(enemy->getComponent<Circle>()->getSize()));
		//enemy->addComponent(new Button()); 
		enemy->addComponent(new SpriteText("HemiHead.ttf", true, {-3, -9}, "E", 12, Color::getRed()));
	}

	Gfx::getInstance()->drawLine(400,400, 600, 600, Color::getBlue());

    isRunning = true;
}

short Menu::run() {
    load();
    while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void Menu::input() {
	SDL_Event sdlEvent;
	SDL_GetMouseState(&pointer.x, &pointer.y);
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			exit = QUIT;
			break;
		
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&pointer.x, &pointer.y);
            if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
				pointer.button = MouseButton::LEFT;
				EventBus::getInstance()->emitEvent<MouseClickEvent>(pointer);
                  
            } else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
				pointer.button = MouseButton::RIGHT;
                EventBus::getInstance()->emitEvent<MouseClickEvent>(pointer);
            } else if (sdlEvent.button.button == SDL_BUTTON_MIDDLE) {
				pointer.button = MouseButton::MIDDLE;
 				EventBus::getInstance()->emitEvent<MouseClickEvent>(pointer);
 			}
            break;
		}
	}
}

void Menu::update() {
	calculateDeltaTime();

	EntityManager::getInstance()->update();
	collisionSystem.update();
	mouseSystem.update(pointer);
	movementSystem.update(deltaTime);
} 

void Menu::render() {
	beginRender();
		
	renderSystem.update(&camera);
	renderTextSystem.update(&camera);
	primitiveRenderSystem.update(&camera);

	endRender();
}

void Menu::buttonHard(int value) {
	if (value == 1) {
		std::cout << "hard button click left" << std::endl;
	}

	if (value == 2) {
		std::cout << "hard button click right" << std::endl;
	}

	if (value == 3) {
		std::cout << "hard button click middle" << std::endl;
	}
}

void Menu::unload() {
    EntityManager::getInstance()->clear();
}
