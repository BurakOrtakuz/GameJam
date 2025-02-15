#ifndef ANIMATIONABLE_HPP
# define ANIMATIONABLE_HPP 202502

#include <vector>
#include <string>
#include <map>
#include <Animation.hpp>

class Animationable
{
private:
    std::map<std::string, Animation> _animations;
    std::string _currentAnimation;
public:
    Animationable(void);
    virtual ~Animationable(void);
    void addAnimation(std::vector<std::string> textures, std::string animationName, unsigned int frames,bool loop = true);
    std::string getUpdate(float deltaTime);
    void setCurAnimation(const std::string &animationName);
    size_t  getTextureSize(const std::string &animationName);
    virtual void updateAnimation(float deltaTime) = 0;
};


#endif /* ANIMATIONABLE__HPP */
