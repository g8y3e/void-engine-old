#include "void_screen_manager.h"

#include "level/lesson_1/lesson_1_screen.h"
#include "level/lesson_2/lesson_2_screen.h"

namespace void_world {
	VoidScreenManager::VoidScreenManager(void_base::Game* game) 
		: ScreenManager(game) {
	}

	VoidScreenManager::~VoidScreenManager() {
	}
	
	bool VoidScreenManager::init() {
		//screen_ = new Lesson1Screen(game_);
		screen_ = new Lesson2Screen(game_);

		return true;
	}	
}