#include "render.h"

#include <void_base/log/log.h>

#include <void_base/opengl.h>
#include <void_base/screen/screen.h>

namespace void_base {
	Render::~Render() {
		SDL_DestroyWindow(window_);
		SDL_Quit();
	}

	bool Render::init(const std::string& name, int width, int height, bool is_fullscreen) {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::string error_msg = "Unable to initialize SDL: ";	
			LOG(error_msg.append(SDL_GetError()));
		}

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 0);
		SDL_GL_SetAttribute(SDL_GL_STEREO, 0);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 0);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 0);
		SDL_GL_SetAttribute(SDL_GL_RETAINED_BACKING, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

#ifdef MOBILE_OS
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES); 

		window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			0, 0, SDL_WINDOW_OPENGL);
#else  
		window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								   width, height, SDL_WINDOW_OPENGL);
		
#endif 

		if (window_ == nullptr) {
			std::string error_msg = "Error: can't create SDL window: ";			
			LOG(error_msg.append(SDL_GetError()));

			return false;
		}

		SDL_DisplayMode display_mode;		
		size_t depth = 16;

		SDL_zero(display_mode);
		switch (depth) {
		case 8:
			display_mode.format = SDL_PIXELFORMAT_INDEX8;
			break;
		case 15:
			display_mode.format = SDL_PIXELFORMAT_RGB555;
			break;
		case 16:
			display_mode.format = SDL_PIXELFORMAT_RGB565;
			break;
		case 24:
			display_mode.format = SDL_PIXELFORMAT_RGB24;
			break;
		default:
			display_mode.format = SDL_PIXELFORMAT_RGB888;
			break;
		}

		if (SDL_SetWindowDisplayMode(window_, &display_mode) < 0) {
			std::string error_msg = "Can't set up fullscreen display mode: ";
			LOG(error_msg.append(SDL_GetError()));

			return false;
		}

		context_ = SDL_GL_CreateContext(window_);	
		if (!context_) {
			std::string error_msg = "SDL_GL_CreateContext(): ";
			LOG(error_msg.append(SDL_GetError()));

			return false;
		}

		SDL_GL_MakeCurrent(window_, context_);
		SDL_GetWindowSize(window_, &screen_width_, &screen_height_);

#ifndef MOBILE_OS
		GLenum res = glewInit();
		if (res != GLEW_OK) {
			//std::string error_msg = std::to_string((char*)(glewGetErrorString(res)));
			return false;
		}
#endif


		return true;
	}

	bool Render::render(Screen* screen) {
		bool result = screen->draw();

		SDL_GL_SwapWindow(window_);
		return result;
	}

	int Render::getScreenWidth() const {
		return screen_width_;
	}

	int Render::getScreenHeight() const {
		return screen_height_;
	}
}