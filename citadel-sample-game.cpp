#include "castle/game/Game.h"

class CitadelSampleGame : public Game {
public:
	CitadelSampleGame(SystemWindow& window):Game(window) { }

	virtual void Update(){}
	virtual void Render(){}
};


String Game::Name() { return "Citadel Sample Game"; }
std::unique_ptr<Game> Game::Create(SystemWindow& window) {
	return std::make_unique<CitadelSampleGame>(window);
}
