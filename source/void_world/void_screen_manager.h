#ifndef VOID_GAME_VOID_SCREEN_MANAGER_H_
#define VOID_GAME_VOID_SCREEN_MANAGER_H_

#include <void_base/screen/screen_mananager.h>

namespace void_world {
	class VoidScreenManager : public void_base::ScreenManager {
	public:
		VoidScreenManager(void_base::Game* game);
		virtual ~VoidScreenManager();
	};
}

#endif