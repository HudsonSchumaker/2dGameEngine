/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../core/MousePointer.h"
#include "../../event/MouseClickEvent.h"

class MouseSystem final : public System {
private:
    void subscribeToEvents();
    bool isInside(const SDL_Rect& box1, const SDL_Rect& box2) const;
    
public:
    MouseSystem();
	~MouseSystem() = default;

	void update(MousePointer pointer);
	void onMouseClick(MouseClickEvent& event);
};
