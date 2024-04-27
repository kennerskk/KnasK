#include <SDL.h>
#include "Math.hpp"
class Entity{
public:
    int health;
    void skill();
    int sKills = 1;
    int speed;
    void gravity(Entity &self);
    void movement(SDL_Event &event,Entity &player);
    vec2 pos;

};
