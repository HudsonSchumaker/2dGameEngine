/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/MousePointer.h"

class MouseSystem final : public System {
private:
    bool isInside(const SDL_Rect& box1, const SDL_Rect& box2) const;
    
public:
    MouseSystem() = default;
	~MouseSystem() = default;

	void update(MousePointer pointer);
};
