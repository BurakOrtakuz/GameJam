#include <Animationable.hpp>


Animationable::Animationable(void)
{
    _currentAnimation = "";
}

Animationable::~Animationable(void)
{
}

void Animationable::addAnimation(std::vector<std::string> textures, std::string animationName, unsigned int frames, bool loop)
{
    _animations[animationName] = Animation(textures, true, frames, loop);
    _animations[animationName].setPlaying(true);
}

std::string Animationable::getUpdate(float deltaTime)
{
    return _animations[_currentAnimation].update(deltaTime);
}

void Animationable::setCurAnimation(const std::string &animationName)
{
    _currentAnimation = animationName;
}

size_t  Animationable::getTextureSize(const std::string &animationName)
{
    return (_animations[animationName]._textures.size());
}