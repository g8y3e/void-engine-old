#include "screen_mananager.h"

namespace void_base {
	ScreenManager::ScreenManager(Game* game) 
		: game_(game) {
	}

	ScreenManager::~ScreenManager() {
	}

	void ScreenManager::setCurrentScreen(Screen* screen) {
		screen_ = screen;
	}

	Screen* ScreenManager::getCurrentScreen() const {
		return screen_;
	}
}