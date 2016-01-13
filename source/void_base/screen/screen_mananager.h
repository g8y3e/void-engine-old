#ifndef VOID_BASE_SCREEN_SCREEN_MANAGER_H_
#define VOID_BASE_SCREEN_SCREEN_MANAGER_H_

namespace void_base {
	class Game;
	class Screen;
	
	class ScreenManager {
	public:
		ScreenManager(Game* game);
		~ScreenManager();

	public:
		void setCurrentScreen(Screen* screen);
		Screen* getCurrentScreen() const;

	public:
		virtual bool init() = 0;

	protected:
		Game* game_;
		Screen* screen_;
	};
}

#endif
