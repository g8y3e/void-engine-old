#include "void_game.h"

#include "void_screen_manager.h"

namespace void_world {
	VoidGame::VoidGame() {
		render_.reset(new void_base::Render());
		screen_manager_.reset(new void_world::VoidScreenManager(this));
		event_manager_.reset(new void_base::EventManager(this));
	}
	
	VoidGame::~VoidGame() {
	}

}