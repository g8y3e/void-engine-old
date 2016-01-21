#include "fps_counter.h"

#include <stdio.h>
#include <third_party/SDL2/SDL.h>

#include <void_base/helper/system_helper.h>

namespace void_base {
namespace debug {
	FPSCounter::FPSCounter() {
		init();
	}

	void FPSCounter::init() {
		previous_time_ = helper::getCurrentTime();

		count_ = 0;
		static_count_ = 0;

		previous_count_ = 0;
		previous_static_count_ = 0;
	}

	void FPSCounter::count() {
		++count_;
	}

	void FPSCounter::countStatic() {
		++static_count_;
	}

	int FPSCounter::getCount() {
		return count_;
	}

	int FPSCounter::getCountStatic() {
		return static_count_;
	}

	int FPSCounter::getPreviousCount() {
		return previous_count_;
	}

	int FPSCounter::getPreviousCountStatic() {
		return previous_static_count_;
	}

	bool FPSCounter::printData() {
		if ((previous_time_ + VE_SECOND_MS) <= helper::getCurrentTime()) {

			static char current_fps[120];
			sprintf(current_fps, "FPS: %d;\nStatic FPS: %d;", count_, static_count_);

			SDL_Log(current_fps);

			previous_count_ = count_;
			previous_static_count_ = static_count_;

			count_ = 0;
			static_count_ = 0;
			previous_time_ = helper::getCurrentTime();

			return true;
		}

		return false;
	}
}
}