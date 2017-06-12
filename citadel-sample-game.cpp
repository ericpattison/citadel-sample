#include "castle/game/Game.h"


struct GameRegistrar {
    GameRegistrar() {
        RegisterGame();
    }
};

class CitadelSampleGame : public Game {
public:
	CitadelSampleGame():Game() { }

	virtual void Update(){}
	virtual void Render(){}
private:
    static GameRegistrar registrar;
};