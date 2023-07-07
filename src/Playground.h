/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "include/Common.h"
#include "gfx/Scene.h"
#include "ecs/Entity.h"
#include "core/MousePointer.h"
#include "ecs/system/RadarSystem.h" 
#include "ecs/system/MouseSystem.h"
#include "ecs/system/RenderSystem.h"
#include "ecs/system/MovementSystem.h"
#include "ecs/system/CollisionSystem.h"
#include "ecs/system/GuiUpdateSystem.h"
#include "ecs/system/RenderTextSystem.h"
#include "ecs/system/ControllerSystem.h"
#include "ecs/system/RenderColliderSystem.h"
#include "ecs/system/RenderHealthBarSystem.h"
#include "ecs/system/PrimitiveRenderSystem.h" 
#include "ecs/system/WaypointNavigationSystem.h"
#include "ecs/system/DamageSystem.h"

class Playground final : public Scene {
private:
    //Entity* background = nullptr;
    //Entity* title = nullptr;
	Entity* button = nullptr;
	Entity* button2 = nullptr;
	MousePointer pointer;
	unsigned int lastEmissionTime = 0;

    CollisionSystem collisionSystem;
	GuiUpdateSystem guiUpdateSystem;
	MouseSystem mouseSystem;
	ControllerSystem controllerSystem;
	RenderSystem renderSystem;
    RenderTextSystem renderTextSystem;
	PrimitiveRenderSystem primitiveRenderSystem;
	MovementSystem movementSystem;
	WaypointNavigationSystem waypointNavigationSystem;
	RadarSystem radarSystem;
	RenderColliderSystem renderColliderSystem;
	RenderHealthBarSystem renderHealthBarSystem;
	DamageSystem damageSystem;

    void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;
	void buttonHard(int id, int value);
	void shoot(unsigned long id, unsigned long otherId);
	
public:
	Playground();
	~Playground();
	short run() override;
};
