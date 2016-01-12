#include <iostream>

#include <third_party/sdl2/SDL.h>

#include <void_world/void_game.h>
#include <void_base/log/log.h>

int main(int argc, char** argv) {
	void_base::LOG("Begin game engine development\n");

	void_world::VoidGame game;
	game.init("Void World v0.0.0.1", 300, 480);
	
	return game.run();
}