#include "Game.hpp"
#include "detect.hpp"
Game *game = nullptr;//make a pointer

int main(int argc,char * argv[])
{


    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 framestart;
    int frameTime;

    game = new Game();//create obj for class Game pass by constructor
    game->init("KnasK",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);//initfunc
    while(game->running())//loop
    {

        framestart = SDL_GetTicks();//get new tick for start new loop

        game->handleEvent();
        game->update();
        game->render();

        frameTime = SDL_GetTicks()-framestart;//gettick after complete task and minus from start

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay-frameTime);//make a delay to wait a millisecond and go to while above again
        }
    }
    game->clean();//stop
    return 0;
}
