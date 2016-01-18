#ifndef VOID_BASE_EVENT_EVENT_MANAGER_H_
#define VOID_BASE_EVENT_EVENT_MANAGER_H_

#include <third_party/sdl2/SDL.h>

namespace void_base {
	class Game;
	class Screen;

	class EventManager {
	public:
		EventManager(Game* game);
		virtual ~EventManager();

	public:
		virtual void handleEvent(Screen* game);

	protected:
		Game* game_;
		SDL_Event event_;
	};
}

#endif
