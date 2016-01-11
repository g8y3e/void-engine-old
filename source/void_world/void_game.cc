#include "void_game.h"

namespace void_world {
	VoidGame::VoidGame() {
		render_.reset(new void_base::Render());
	}


	VoidGame::~VoidGame() {
	}

}