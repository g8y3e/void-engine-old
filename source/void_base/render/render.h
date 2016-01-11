#ifndef VOID_BASE_RENDER_RENDER_H_
#define VOID_BASE_RENDER_RENDER_H_

#include <string>

#include <third_party/sdl2/SDL.h>

namespace void_base {
	class Screen;

	class Render {
	public:
		virtual ~Render();

	public:
		bool init(const std::string& name, int width, int height,
			bool is_fullscreen = false);
	public:
		bool render(Screen* screen);

	public:
		int getScreenWidth() const;
		int getScreenHeight() const;

	private:
		int screen_width_;
		int screen_height_;

		SDL_Window* window_;
		SDL_GLContext context_;
	};
}

#endif