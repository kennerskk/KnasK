#ifndef Game_hpp
#define Game_hpp
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Game{
public:
    Game();//constructor
    ~Game();//destructor
    void init(const char *title, int xpos ,int ypos ,int width ,int height,bool fullscreen);
    void update();
    void render();
    void clean();
    void handleEvent();

    bool running() {return isRunning;}
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif
