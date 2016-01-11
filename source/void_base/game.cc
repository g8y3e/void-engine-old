#include "game.h"

namespace void_base {
	Game::Game() 
		: is_running_(true) {
	}

	Game::~Game() {
	}

	bool Game::init(const std::string& name, size_t width, size_t height, size_t frame_rate) {
		game_width_ = width;
		game_height_ = height;

		return render_->init(name, width, height);
	}

	int Game::run() {
		while(!isRunning()) {
			
		}
		
		return 0;
	}

	bool Game::isRunning() const {
		return is_running_;
	}
}