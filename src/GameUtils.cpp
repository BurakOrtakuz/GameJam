#include <Game.hpp>
#include <cstring>
#include <TagManager.hpp>

void Game::resetInputs()
{
    if(_keys['H'] == false)
    {
        maps["level1"]._player->stop("hide");
    }
}