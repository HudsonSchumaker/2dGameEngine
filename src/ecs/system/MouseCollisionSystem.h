/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/MousePointer.h"

class MouseCollisionSystem final : public System {
private:
    bool isInside(const SDL_Rect& box1, const SDL_Rect& box2) const;
    
public:
    MouseCollisionSystem() = default;
	~MouseCollisionSystem() = default;

	void update(MousePointer pointer);
};
