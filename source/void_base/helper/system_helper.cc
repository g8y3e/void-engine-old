#include "system_helper.h"

#include <third_party/sdl2/SDL.h>

namespace void_base {
namespace helper {
	ulong getCurrentTime() {
		return SDL_GetTicks();
	}
}
}