#include "screen.h"

#include <void_base/opengl.h>

namespace void_base{
	Screen::Screen(Game* game) {
		
	}

	Screen::~Screen() {
	}

	bool Screen::draw() {
		clearDraw();

		return true;
	}

	void Screen::clearDraw() {
		glClearColor(0.0f, 0.3f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}