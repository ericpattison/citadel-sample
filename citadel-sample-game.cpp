#include "castle/game/Game.h"
//#include <android_native_app_glue.h>

class CitadelSampleGame : public Game {
public:
	CitadelSampleGame():Game() { }

	virtual void Update(){}
	virtual void Render(){}
private:
};

UPtr<Game> createGame() { 
	return MakeUPtr<CitadelSampleGame>();
}
GameRegistrar registrar(createGame);