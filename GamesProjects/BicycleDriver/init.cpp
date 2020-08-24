/**
 *  Init cpp - documenting code
 *
 */

#include "init.h"
#include "variable.h"
#include "constants.h"
#include <SDL.h>
#include <SDL_image.h>

bool init_all()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;

    //screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE); used with SDL1
    screen = SDL_CreateWindow("My Game Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_SWSURFACE);

    if (screen == NULL)
    {
        return false;
    }

    if (TTF_Init() == -1)                  //Font Initialization...
    {
        return false;
    }

    renderer = SDL_CreateRenderer(screen, -1, 0);

    return true;
}

SDL_Surface* load_image(const char* filename, int col1 = 0xFF, int col2 = 0xFF, int col3 = 0xFF)
{
    SDL_Surface* loaded_image = NULL;
    SDL_Surface* optimized_image = NULL;
    
    loaded_image = IMG_Load(filename);
    if (!loaded_image)
    {
        /* image failed to load */
        printf("IMG_Load: %s\n", IMG_GetError());
        SDL_Quit();
        return 0;
    }
    if (loaded_image != NULL)
    {
        // SDL_Surface *input = ...;
        SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);
        optimized_image = SDL_ConvertSurface(loaded_image, format, 0);
        SDL_FreeFormat(format);
        SDL_FreeSurface(loaded_image);

        if (optimized_image != NULL)
        {
            SDL_SetColorKey(optimized_image, SDL_TRUE, SDL_MapRGB(optimized_image->format, col1, col2, col3));
        }
    }

    return optimized_image;     //Return the address of the loaded image...
}

bool load_files()
{
    for (int i = 0; i < 2; i++)
    {
        back[i] = load_image("image/bg2.png");         //Loads the background image..
        if (back[i] == NULL)
            return false;
    }
    bg[0] = background(0, 0, back[0]->w, back[0]->h);
    bg[1] = background(WIDTH, 0, back[1]->w, back[1]->h);

    upback = load_image("image/bg1.png");     //Loads the uper side of the  background image..
    if (upback == NULL)
        return false;

    bike = load_image("image/bike.PNG");      //Loads the image of bike..
    if (bike == NULL)
        return false;
    bike_y = LAYER_Y - bike->h;

    obs_wall[0] = load_image("image/wall.JPG");
    obs_wall[1] = load_image("image/wall1.JPG");
    if (obs_wall == NULL || obs_wall[1] == NULL)
        return false;

    w1[0] = wall(WIDTH + 50, LAYER_Y - obs_wall[0]->h, obs_wall[0]->w, obs_wall[0]->h);
    w1[1] = wall(WIDTH + 1350, LAYER_Y - obs_wall[0]->h, obs_wall[0]->w, obs_wall[0]->h);
    w1[2] = wall(WIDTH + 3350, LAYER_Y - obs_wall[0]->h, obs_wall[0]->w, obs_wall[0]->h);
    w1[3] = wall(WIDTH + 5050, LAYER_Y - obs_wall[0]->h, obs_wall[0]->w, obs_wall[0]->h);
    w1[4] = wall(WIDTH + 7100, LAYER_Y - obs_wall[0]->h, obs_wall[0]->w, obs_wall[0]->h);

    w2[0] = wall(WIDTH + 2050, LAYER_Y - obs_wall[1]->h, obs_wall[1]->w, obs_wall[1]->h);
    w2[1] = wall(WIDTH + 4350, LAYER_Y - obs_wall[1]->h, obs_wall[1]->w, obs_wall[1]->h);
    w2[2] = wall(WIDTH + 6050, LAYER_Y - obs_wall[1]->h, obs_wall[1]->w, obs_wall[1]->h);
    w2[3] = wall(WIDTH + 7800, LAYER_Y - obs_wall[1]->h, obs_wall[1]->w, obs_wall[1]->h);

    font = TTF_OpenFont("times.ttf", 20);      //Font file is loaded....

    time_limit = TTF_RenderText_Solid(font, "Time limit is 1:30 minute", textColor);
    die = TTF_RenderText_Solid(font, "GAME OVER", textColor);

    menu_pic = load_image("image/menu.jpg");
    play_menu = load_image("image/menu_play.jpg");
    instruction_menu = load_image("image/menu_instruction.jpg");
    quit_menu = load_image("image/menu_exit.jpg");
    if (menu_pic == NULL || play_menu == NULL || instruction_menu == NULL || quit_menu == NULL)
        return false;

    return true;
}

bool init_restart() 
{
    for (int i = 0; i < SMAX_WALL; i++)
        w1[i].set_state(false);              //add the wall's state
    for (int i = 0; i < BMAX_WALL; i++)
        w2[i].set_state(false);              //add the wall's state

    keybstate = SDL_GetKeyboardState(NULL);
    if (SDL_Init(SDL_INIT_TIMER) == -1)
        return false;
    speed = 0;
    bike_x = START_BIKE_X;
    game_on = 1;
    time_gap = 0;
    start_time = SDL_GetTicks();

    if (!load_files())
        return false;

    return true;
}

bool test_imgonscr()
{
    //SDL_Renderer* renderer = SDL_CreateRenderer(screen, -1, 0);
    SDL_Rect rect = {100, 100, 40, 30};
    int a, b;
    int c = 0;
    SDL_Rect rects[12];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a = rect.x + i * 50;
            b = rect.y + j * 50;
            if ((i == 1 || i == 2) && j > 0 && j < 3) continue;
            rects[c] = { a, b, rect.w, rect.h };
            c++;
        }
    }

    SDL_SetRenderDrawColor(renderer, 160, 255, 160, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRects(renderer, rects, 12);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    return true;
}