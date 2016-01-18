#include "event_manager.h"

#include <void_base/game.h>
#include <void_base/log/log.h>

namespace void_base {
	EventManager::EventManager(Game* game)
		: game_(game) {
	}

	EventManager::~EventManager() {
	}

	void EventManager::handleEvent(Screen* game) {
		while (SDL_PollEvent(&event_)) {
			switch (event_.type) {
			case SDL_QUIT:
				LOG("Quit!");
				game_->setRunning(false);
				break;
			}
		}
	}
}