#include "Entity.hpp"
#include <iostream>
Entity::Entity(SDL_Texture *p_tex,float p_x,float p_y)
:x(p_x),y(p_y),tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

void Entity::skill(){
    std::cout << "skill used"<<std::endl;
}
SDL_Rect Entity::getcurrentFrame(){
    return currentFrame;
}
SDL_Texture* Entity::getTexture(){
    return tex;
}
float Entity::getx(){
    return x;
}
float Entity::gety(){
    return y;
}

void Entity::movementt(SDL_Event event )
{

switch(event.type)//event type analysis
    {
        case SDL_KEYDOWN:
            switch( event.key.keysym.sym ){
                    case SDLK_a:
                        movementx.x = true;
                        break;
                    case SDLK_d:
                        movementx.y = true;
                        break;
                    case SDLK_w:
                        movementy.x = true;
                        break;
                    case SDLK_s:
                        movementy.y = true;
                        break;
                    default:
                        break;}
            break;
        case SDL_KEYUP:
            switch( event.key.keysym.sym ){
                    case SDLK_a:
                        movementx.x = false;
                        break;
                    case SDLK_d:
                        movementx.y = false;
                        break;
                    case SDLK_w:
                        movementy.x = false;
                        break;
                    case SDLK_s:
                        movementy.y = false;
                        break;
                    default:
                        break;
             }
            break;
        default:
            break;

}}

void Entity::entityupdate(int p_speed){
    x += p_speed*(movementx.y-movementx.x);
    y += p_speed*(movementy.y-movementy.x);
}

