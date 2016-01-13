#include "void_screen_manager.h"

#include "level/lesson_1/lesson_1_screen.h"

namespace void_world {
	VoidScreenManager::VoidScreenManager(void_base::Game* game) 
		: ScreenManager(game) {
	}

	VoidScreenManager::~VoidScreenManager() {
	}
	
	bool VoidScreenManager::init() {
		screen_ = new Lesson1Screen(game_);
	}	
}