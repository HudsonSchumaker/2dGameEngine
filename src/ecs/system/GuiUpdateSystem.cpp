/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "GuiUpdateSystem.h"
#include "../EntityManager.h"
#include "../component/Button.h"
#include "../../event/EventBus.h"

GuiUpdateSystem::GuiUpdateSystem() {
	subscribeToEvents();
}

void GuiUpdateSystem::subscribeToEvents() {
	EventBus::getInstance()->subscribeToEvent<MouseHoverEvent>(this, &GuiUpdateSystem::onHover);
}

void GuiUpdateSystem::onHover(MouseHoverEvent& event) {
	if (event.b->tag == Tag::ui) {
		
		Button* button = event.b->getComponent<Button>();
		if (button) {
			if (event.isInside) {
				button->hoverOn();
			} else {
				button->hoverOff();
			}
			return;
		}

		//TODO: update other ui components	
	}
}
