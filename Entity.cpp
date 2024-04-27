#include "Entity.hpp"
#include <iostream>
void Entity::skill(){
    std::cout << sKills <<std::endl;

}
void Entity::movement(SDL_Event &event,Entity &player){
   switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        player.pos.x -= 1*player.speed;
                        break;
                    case SDLK_RIGHT:
                        player.pos.x += 1*player.speed;
                        break;
                    case SDLK_UP:
                        player.pos.y -= 1*player.speed;
                        break;
                    case SDLK_DOWN:
                        player.pos.y += 1*player.speed;
                        break;
                    default:
                        break;
                }
}
void Entity::gravity(Entity &self){
    self.pos.y+=3;

}
