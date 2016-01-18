#ifndef VOID_WORLD_LEVEL_LESSON_1_LESSON_1_SCREEN_H_
#define VOID_WORLD_LEVEL_LESSON_1_LESSON_1_SCREEN_H_

#include <void_base/screen/screen.h>

namespace void_world {
	class Lesson1Screen : public void_base::Screen {
	public:
		Lesson1Screen(void_base::Game * game);
		virtual ~Lesson1Screen();

	public:
		bool draw() override;
	};
}

#endif
