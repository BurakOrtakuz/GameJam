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

void Game::collisionDetection(glm::vec2 &playerPos, glm::vec2 &playerMomentum, glm::vec2 &temp, Player *player)
{ //TEO - Collision detection
const float p_right = playerPos.x + player->getCollision().getSize().x;
    const float p_left = playerPos.x;
    const float p_up = playerPos.y;
    const float p_down = playerPos.y + player->getCollision().getSize().y;
    std::vector<GameObject *> objects = TagManager::getTags(e_tag::WALL);

    for (auto object : objects)
    {
        if (object->isDestroyed())
            continue;

        glm::vec2 object_position = object->getCollision().getPosition();
        glm::vec2 object_size = object->getCollision().getSize();

        const float o_right = object_position.x + object_size.x;
        const float o_left = object_position.x;
        const float o_up = object_position.y;
        const float o_down = object_position.y + object_size.y;

        bool bottomCollision =
            (fabs(p_down - o_up) < 1.0f) &&
            (p_up < o_up) &&
            (p_right > o_left) &&
            (p_left < o_right);

        bool topCollision =
            (fabs(p_up - o_down) < 1.0f) &&
            (p_down > o_down) &&
            (p_right > o_left) &&
            (p_left < o_right);

        bool leftCollision =
            (fabs(p_left - o_right) < 1.0f) &&
            (p_right > o_right) &&
            (p_down > o_up) &&
            (p_up < o_down);

        bool rightCollision =
            (fabs(p_right - o_left) < 1.0f) &&
            (p_left < o_left) &&
            (p_down > o_up) &&
            (p_up < o_down);

        if (bottomCollision)
        {
            playerPos = glm::vec2(playerPos.x, temp.y - 0.1F);
            playerMomentum = glm::vec2(playerMomentum.x, temp.y);
        }

        if (topCollision)
        {
            playerPos = glm::vec2(playerPos.x, temp.y + 0.1F);
            playerMomentum = glm::vec2(playerMomentum.x, temp.y);
        }

        if (leftCollision)
        {
            playerPos = glm::vec2(temp.x + 0.1F, playerPos.y);
            playerMomentum = glm::vec2(temp.x, playerMomentum.y);
        }

        if (rightCollision)
        {
            playerPos = glm::vec2(temp.x - 0.1F, playerPos.y);
            playerMomentum = glm::vec2(temp.x, playerMomentum.y);
        }
    }
}