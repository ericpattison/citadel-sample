#include "castle/game/Game.h"
#include "watchtower/Color.h"

class CitadelSampleGame : public Game {
public:
	CitadelSampleGame(SPtr<Device> device):Game() {
        Color clearColor(127, 66, 255, 255);
        device->SetClearColor(clearColor);
    }

	virtual void Update(){}
	virtual void Render(){}
private:
};

UPtr<Game> createGame(SPtr<Device> device) {
	return MakeUPtr<CitadelSampleGame>(device);
}
GameRegistrar registrar(createGame);