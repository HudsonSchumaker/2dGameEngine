/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Playground.h"
#include "gfx/Box.h"
#include "gfx/Line.h"
#include "gfx/Circle.h"
#include "gfx/Color.h"
#include "gfx/Sprite.h"
#include "gfx/Animation.h"
#include "event/EventBus.h"
#include "ecs/EntityManager.h"
#include "ecs/component/Radar.h"
#include "ecs/component/Button.h"
#include "event/MouseClickEvent.h"
#include "ecs/component/TextLabel.h"
#include "ecs/component/Transform.h"
#include "ecs/component/RigidBody.h"
#include "ecs/component/SpriteText.h"
#include "ecs/component/Waypoint.h"
#include "ecs/component/Callback.h"
#include "ecs/component/Health.h"
#include "core/BulletFactory.h"

Playground::Playground() {}

Playground::~Playground() {
    unload();
}

void Playground::load() {
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
	button->addComponent(new TextLabel("HemiHead.ttf", true, button->getComponent<Transform>()->position, "T", 12, Color::getBlue()));
	button->addComponent(new Radar(96, {16, 16}));
	button->addComponent(new Callback([&](unsigned long id, unsigned long otherId) { 
		shoot(id, otherId);
	}));
   
    auto label = button->getComponent<TextLabel>();
	auto bt = button->getComponent<Button>();
	auto tr = button->getComponent<Transform>();
	label->position.x = tr->position.x + 16 - (label->w/2);
    label->position.y= tr->position.y + 16 - (label->h/2);

	bt->hover = 0;
	bt->setCallback([&](unsigned long id, int value) {
        buttonHard(id, value);
	});

	button2 = EntityManager::getInstance()->createEntity(100, 360);
	button2->tag = Tag::ui;
	//button->addComponent(new Sprite("hard", true, Tags::getLayer(Tag::ui)));
	button2->addComponent(new Box(32, 32, Tags::getLayer(Tag::ui), true));
	button2->addComponent(new BoxCollider(button->getComponent<Box>()->getSize()));
	button2->addComponent(new Button()); 
	button2->addComponent(new TextLabel("pico8.ttf", true, button2->getComponent<Transform>()->position, "T", 12, Color::getBlue()));
   
    auto label2 = button2->getComponent<TextLabel>();
	auto bt2 = button2->getComponent<Button>();
	auto tr2 = button2->getComponent<Transform>();
	label2->position.x = tr2->position.x + 16 - (label2->w/2);
    label2->position.y = tr2->position.y + 16 - (label2->h/2);

	bt2->hover = 0;
	bt2->setCallback([&](unsigned long id, int value) {
        buttonHard(id, value);
	});

	std::vector<std::pair<short, short>> waypoints = {
    	{ 150, 150 },
    	{ 400, 400 },
		{ 500, 500 },
		{ 18, 18 }
	};

	for(int i = 1; i < 300; i++) {
		auto enemy = EntityManager::getInstance()->createEntity(0, i* 42);
		enemy->tag = Tag::enemy;
		enemy->addComponent(new RigidBody(32.0f + i, 32.0f + i));
		//enemy->addComponent(new Box(32, 32, Tags::getLayer(Tag::ui), true));
		//enemy->addComponent(new Sprite("hard", true, Tags::getLayer(Tag::ui)));
		enemy->addComponent(new Circle(16, Tags::getLayer(Tag::ui), false, Color::getBlue()));
		enemy->addComponent(new Waypoint(waypoints));
		enemy->addComponent(new BoxCollider(enemy->getComponent<Circle>()->getSize(), {-10, -10}));
		enemy->addComponent(new Button()); 
		enemy->addComponent(new SpriteText("pico8.ttf", true, { -3, -9 }, "E", 12, Color::getBlue()));
		enemy->addComponent(new Health(100));
		auto bt2 = enemy->getComponent<Button>();
		bt2->hover = 0;
		bt2->setCallback([&](int id, int value) {
        	buttonHard(id, value);
		});
	}

	auto line = EntityManager::getInstance()->createEntity(300, 300);
	line->tag = Tag::ui;
	//line->addComponent(new Line(340, 340));
	
	lastEmissionTime = SDL_GetTicks();
    isRunning = true;

	auto bayley = EntityManager::getInstance()->createEntity(200, 200);
	bayley->addComponent(new Animation("run2", 8, 10, false));
	//bayley->getComponent<Animation>()->skipFrameIndex = 5;
	auto transform = bayley->getComponent<Transform>();
	transform->scale.x = 2;
	transform->scale.y = 2;

	auto coin = EntityManager::getInstance()->createEntity(500, 500);
	coin->addComponent(new Animation("coin20x20",8, 10, false));
}

short Playground::run() {
    load();
    while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void Playground::input() {
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

void Playground::update() {
	calculateDeltaTime();

/* 	auto circles = EntityManager::getInstance()->getEntitiesWithComponent<Circle>();
	for(auto& circle : circles) {
		if( circle->id%2 == 0) {
			auto r = circle->getComponent<Circle>()->getRadius();

			if (r < 28) {
				circle->getComponent<Circle>()->setRadius(r + 2.0f);
			}
			if (r > 27) {
				circle->getComponent<Circle>()->setRadius(r - 16.0f);
			}
		}
	} */

	EntityManager::getInstance()->update();
	collisionSystem.update();
	radarSystem.update();
	mouseSystem.update(pointer);
	movementSystem.update(deltaTime);
	waypointNavigationSystem.update(deltaTime);
} 

void Playground::render() {
	beginRender();
	{
		renderSystem.update(&camera);
		animationSystem.update(&camera);
		renderTextSystem.update(&camera);
		primitiveRenderSystem.update(&camera);
		renderHealthBarSystem.update(&camera);
		renderColliderSystem.update(&camera);
	}	
	endRender();
}

void Playground::buttonHard(int id, int value) {
	std::cout << "entity: "<< id << std::endl;
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

void Playground::unload() {
    EntityManager::getInstance()->clear();
}

void Playground::shoot(unsigned long id, unsigned long otherId) {
	if (SDL_GetTicks() - lastEmissionTime > 120) {
		auto me = EntityManager::getInstance()->getEntity(id);
		auto other = EntityManager::getInstance()->getEntity(otherId);

		auto meTransform = me->getComponent<Transform>();
		auto otherTransform = other->getComponent<Transform>();

		auto nX = meTransform->position.x + 16;
		auto nY = meTransform->position.y + 16;
		BulletFactory::getInstance()->createBullet(
			{ nX, nY }, 
			otherTransform->position, 
			BulletType::BASIC, 
			true
		);
     
    	lastEmissionTime = SDL_GetTicks();
    }    
}
