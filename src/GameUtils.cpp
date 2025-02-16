#include <Game.hpp>
#include <cstring>

void Game::resetInputs()
{
	if(_keys['H'] == false)
    {
        maps["level1"]._player->stop("hide");
    }
}