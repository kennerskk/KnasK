#include "Game.hpp"
#include "Entity.hpp"
SDL_Texture *playerTex;
SDL_Rect srcR,dstR;
Entity ken(playerTex,100,100);
Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

    int flags = 0;//declare flags
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;//change flags to fullscreen
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)//init
    {
        std::cout << "intialize complete" << std::endl;

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);//if init success
        if (window)
            {
                std::cout << "window created" << std::endl;
            }
        renderer = SDL_CreateRenderer(window,-1,0);//if init success
        if (renderer)
            {
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                std::cout << "renderer created" << std::endl;
            }
        isRunning = true;//if init success
    }
    SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
    playerTex = SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvent()
{
    SDL_Event event;//declare variable for handle all event
    SDL_PollEvent(&event);//for i in event
    ken.movementt(event);
    switch(event.type)//event type analysis
    {

        case SDL_QUIT:
            isRunning = false;//toggle running
            break;
        case SDL_KEYDOWN:
            ken.skill();
            std::cout << "hi" << std::endl;
            break;
        default:
            break;
    }
}

void Game::update()
{
    dstR.h = ken.getcurrentFrame().h*4;
    dstR.w = ken.getcurrentFrame().w*4;
    dstR.x = ken.getx();
    dstR.y = ken.gety();

}

void Game::render()
{   ken.entityupdate(4);
    SDL_RenderClear(renderer);//refresh renderer
    SDL_RenderCopy(renderer,playerTex,NULL,&dstR);
    SDL_RenderPresent(renderer);//start render on renderer

}
void Game::clean()
{
    SDL_DestroyWindow(window);//delete window
    SDL_DestroyRenderer(renderer);//delete renderer
    SDL_Quit();//quit
}
