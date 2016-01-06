#include "log.h"

#include <third_party/sdl2/SDL.h>

namespace void_base {
	namespace log {
		void print(const char* file, int line, const char* msg) {
			std::string full_msg = file;
			full_msg.append("::").append(std::to_string(line)).append(": ").append(msg);

			SDL_Log(full_msg.c_str());
		}

		void print(const char* file, int line, const std::string& msg) {
			print(file, line, msg.c_str());
		}

		void print(const char* msg) {
			SDL_Log(msg);
		}
	}
}