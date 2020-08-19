#include "menu.h"
#include <SDL.h>
#include "init.h"
#include "surface.h"
#include "variable.h"
#include "process.h"

int start_menu()
{
    bool running = true;
    int x, y;

    bike_process bk;

    while (running)
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEMOTION)
            {
                //cerr << "inside" << endl;
                x = event.motion.x;
                y = event.motion.y;
                if ((x > 594) && (x < 756) && (y > 340) && (y < 357))
                {
                    apply_surface(0, 0, play_menu->w, play_menu->h, play_menu, renderer);
                }
                else if ((x > 572) && (x < 778) && (y > 414) && (y < 431))
                {
                    apply_surface(0, 0, instruction_menu->w, instruction_menu->h, instruction_menu, renderer);
                }
                else if ((x > 641) && (x < 708) && (y > 490) && (y < 506))
                {
                    apply_surface(0, 0, quit_menu->w, quit_menu->h, quit_menu, renderer);
                }
                else
                    apply_surface(0, 0, menu_pic->w, menu_pic->h, menu_pic, renderer);
                //SDL_Flip(screen);
                SDL_RenderPresent(renderer);
            }
            else
                apply_surface(0, 0, menu_pic->w, menu_pic->h, menu_pic, renderer);
            //SDL_Flip(screen);
            SDL_RenderPresent(renderer);

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                x = event.motion.x;
                y = event.motion.y;
                if ((x > 594) && (x < 756) && (y > 340) && (y < 357))   //start game
                {

                    if (game_on == 0 || time_gap > 0)       // play again if game was started once already
                        if (!init_restart()) return 0;

                    while (bk.process())
                    {
                        //SDL_Flip(screen);
                        SDL_RenderPresent(renderer);
                        SDL_RenderClear(renderer);
                    }
                }
                else if ((x > 572) && (x < 778) && (y > 414) && (y < 431))
                {
                    apply_surface(0, 0, instruction_menu->w, instruction_menu->h, instruction_menu, renderer);
                }
                else if ((x > 641) && (x < 708) && (y > 490) && (y < 506))
                {
                    return 0;
                }
            }
        }

    return 0;
}
