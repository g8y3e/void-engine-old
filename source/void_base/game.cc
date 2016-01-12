#include "game.h"

#include <void_base/define/system_define.h>
#include <void_base/helper/system_helper.h>

namespace void_base {
	Game::Game() 
		: is_running_(true) {
	}

	Game::~Game() {
	}

	bool Game::init(const std::string& name, size_t width, size_t height, size_t frame_rate) {
		static_frame_rate_ = frame_rate;

		game_width_ = width;
		game_height_ = height;

		return render_->init(name, width, height);
	}

	int Game::run() {
		fps_counter_.reset(new debug::FPSCounter());

		ulong delta_time = 1000 / (static_frame_rate_ - 1);
		ulong current_time;
		ulong elapsed;
		ulong prev_time = helper::getCurrentTime();
		ulong lag = 0;

		double static_dt = delta_time / 1000.0;
		double dt = 0.0f;

		while(isRunning()) {
			fps_counter_->count();

			current_time = helper::getCurrentTime();
			elapsed = current_time - prev_time;
			prev_time = current_time;
			lag += elapsed;

			dt = elapsed / 1000.0;

			while (lag >= delta_time) {				
				fps_counter_->countStatic();

				lag -= delta_time;
			}

			fps_counter_->printData();
		}
		
		return 0;
	}

	bool Game::isRunning() const {
		return is_running_;
	}
}