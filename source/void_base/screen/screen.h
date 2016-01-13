#ifndef VOID_BASE_SCREEN_SCREEN_H_
#define VOID_BASE_SCREEN_SCREEN_H_

namespace void_base {
	class Game;

	class Screen {
	public:
		Screen(Game* game);
		virtual ~Screen();

	public:
		virtual bool draw();

	protected:
		virtual void clearDraw();

	private:

	};
}

#endif
