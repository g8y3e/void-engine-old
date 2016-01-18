#include "game.h"

#include <void_base/log/log.h>

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

		ulong delta_time = 1000 / static_frame_rate_;
		ulong current_time;
		ulong elapsed;
		ulong prev_time = helper::getCurrentTime();
		ulong lag = 0;

		screen_manager_->init();

		while(isRunning()) {
			event_manager_->handleEvent(screen_manager_->getCurrentScreen());
			fps_counter_->count();

			current_time = helper::getCurrentTime();
			elapsed = current_time - prev_time;
			prev_time = current_time;
			lag += elapsed;			
			
			while (lag >= delta_time) {
				fps_counter_->countStatic();

				lag -= delta_time;
			}		

			fps_counter_->printData();
			render_->render(screen_manager_->getCurrentScreen());
		}
		
		return 0;
	}

	bool Game::isRunning() const {
		return is_running_;
	}

	void Game::setRunning(bool is_running) {
		is_running_ = is_running;
	}
}