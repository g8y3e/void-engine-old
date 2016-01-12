#ifndef VOID_BASE_GAME_H_
#define VOID_BASE_GAME_H_

#include <string>
#include <memory>

#include <void_base/render/render.h>
#include <void_base/screen/screen_mananager.h>

#include <void_base/debug/fps/fps_counter.h>

namespace void_base {
	class Game {
	public:
		Game();
		virtual ~Game();

	public:
		virtual bool init(const std::string& name, size_t width, size_t height, size_t frame_rate = 60);

	public:
		virtual int run();

	private:
		bool isRunning() const;

	protected:
		std::unique_ptr<Render> render_;
		std::unique_ptr<ScreenManager> screen_manager_;
		std::unique_ptr<debug::FPSCounter> fps_counter_;

	private:
		bool is_running_;

		size_t static_frame_rate_;

		size_t game_width_;
		size_t game_height_;

		size_t screen_width_;
		size_t screen_height_;		

	};
} 

#endif