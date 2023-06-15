
#include "include/Common.h"
#include "gfx/Scene.h"
#include "ecs/Entity.h"
#include "core/MousePointer.h"
#include "ecs/system/RenderSystem.h"
#include "ecs/system/CollisionSystem.h"
#include "ecs/system/GuiUpdateSystem.h"
#include "ecs/system/RenderTextSystem.h"
#include "ecs/system/ControllerSystem.h"
#include "ecs/system/MouseSystem.h"
#include "ecs/system/PrimitiveRenderSystem.h"

class Menu final : public Scene {
private:
    Entity* background = nullptr;
    Entity* title = nullptr;
	Entity* button = nullptr;

	MousePointer pointer;

    CollisionSystem collisionSystem;
	GuiUpdateSystem guiUpdateSystem;
	MouseSystem mouseSystem;
	ControllerSystem controllerSystem;
	RenderSystem renderSystem;
    RenderTextSystem renderTextSystem;
	PrimitiveRenderSystem primitiveRenderSystem;

    void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;
	void buttonHard(int value);
	
public:
	Menu();
	~Menu();
	short run() override;
};
