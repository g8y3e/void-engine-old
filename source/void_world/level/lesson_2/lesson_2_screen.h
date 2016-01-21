#ifndef VOID_WORLD_LEVEL_LESSON_2_LESSON_2_SCREEN_H_
#define VOID_WORLD_LEVEL_LESSON_2_LESSON_2_SCREEN_H_

#include <void_base/opengl.h>

#include <void_base/screen/screen.h>

namespace void_world {
	class Lesson2Screen : public void_base::Screen {
	public:
		Lesson2Screen(void_base::Game * game);
		virtual ~Lesson2Screen();

	public:
		bool draw() override;

	private:		
		GLuint VBO;		
	};
}

#endif