#include "lesson_1_screen.h"

#include <void_base/log/log.h>
#include <void_base/opengl.h>
#include <void_base/math/vector.h>

namespace void_world {		
	Lesson1Screen::Lesson1Screen(void_base::Game* game) 
		: void_base::Screen(game) {

		void_base::math::Vector3f vertices[1];
		vertices[0] = void_base::math::Vector3f(0.0f, 0.0f, 0.0f);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	}

	Lesson1Screen::~Lesson1Screen() {		
	}	

	bool Lesson1Screen::draw() {
		clearDraw();

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glDrawArrays(GL_POINTS, 0, 1);

		glDisableVertexAttribArray(0);

		return true;
	}
}