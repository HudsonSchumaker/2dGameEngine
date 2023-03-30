
#include "include/Common.h"
#include "gfx/Scene.h"
#include "ecs/Entity.h"
#include "core/MousePointer.h"
#include "ecs/system/RenderSystem.h"
#include "ecs/system/CollisionSystem.h"
#include "ecs/system/RenderTextSystem.h"
#include "ecs/system/ControllerSystem.h"
#include "ecs/system/MouseCollisionSystem.h"

class Menu : public Scene {
private:
    Entity* background = nullptr;
    Entity* title = nullptr;
	Entity* button = nullptr;

	MousePointer pointer;

    CollisionSystem collisionSystem;
	MouseCollisionSystem mouseCollisionSystem;
	ControllerSystem controllerSystem;
	RenderSystem renderSystem;
    RenderTextSystem renderTextSystem;

    void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	Menu();
	~Menu();
	short run() override;
};