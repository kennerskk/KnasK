#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"
class Entity{
public:
    Entity(SDL_Texture *p_tex,float p_x,float p_y);
    void skill();
    SDL_Rect getcurrentFrame();
    SDL_Texture *getTexture();
    float getx();
    float gety();
    void movementt(SDL_Event event);
    void entityupdate(int p_speed);

private:
    movement movementx;
    movement movementy;
    SDL_Texture *tex;
    SDL_Rect currentFrame;
    float x,y;
};

