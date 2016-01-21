#include "lesson_2_screen.h"

#include <void_base/math/vector.h>

namespace void_world {
	namespace {
		GLuint VBO;
	}

	Lesson2Screen::Lesson2Screen(void_base::Game* game) 
		: void_base::Screen(game) {		
		glGenBuffers(1, &VBO);

		/*

		Monitor coords
		(-1.0, 1.0)           (1.0, 1.0)
		    ------------ ------------
		   |			|			 |
		   |			|			 |
		   |			|			 |
		   |------------|------------|
		   |			|			 |
		   |			|			 |
		   |			|			 |
		    ------------ ------------	
	    (-1.0, -1.0)          (1.0, -1.0)

		*/

		using void_base::math::Vector3f;
		Vector3f vertices[3];
		vertices[0] = Vector3f(0.0f,  1.0f, 0.0f);
		vertices[1] = Vector3f(-1.0f, -1.0f, 0.0f);
		vertices[2] = Vector3f(1.0f, -1.0f, 0.0f);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		
	}

	Lesson2Screen::~Lesson2Screen() {
	}

	bool Lesson2Screen::draw() {
		clearDraw();

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
		glDrawArrays(GL_TRIANGLES, 0, 3);	

		glDisableVertexAttribArray(0);

		return true;
	}
}