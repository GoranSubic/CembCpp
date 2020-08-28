/**
 *  Menu cpp - documenting code
 *
 */

#include <SDL.h>
#include <vector>
#include <fstream>
#include "menu.h"
#include "init.h"
#include "surface.h"
#include "variable.h"
#include "process.h"
#include "dbconnection.h"

int start_menu()
{
    bool running = true;
    int x, y;

    bike_process bk;

    SDL_StartTextInput();

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

            //Input players name
            get_players_name();

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
                    store_data->write_score();
                    store_data->fill_users_map();
                }
                else if ((x > 572) && (x < 778) && (y > 414) && (y < 431))
                {
                    //main instruction page - image
                    apply_surface(0, 0, instruction_menu->w, instruction_menu->h, instruction_menu, renderer);
                    
                    get_players_name();

                    //show information about users scores - on instruction page
                    users_scores();

                    //show instructions after users scores on instructions page
                    instructions_info();

                    SDL_RenderPresent(renderer);
                    SDL_RenderClear(renderer);
                }
                else if ((x > 641) && (x < 708) && (y > 490) && (y < 506))
                {
                    return 0;
                }
            }
        }

    SDL_StopTextInput();

    return 0;
}

void get_players_name()
{
    if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
    {
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && input_name.length() > 0)
            input_name = input_name.substr(0, input_name.length() - 1);
        else if (event.type == SDL_TEXTINPUT && input_name.length() <= 10)
            input_name += event.text.text;
    }
    input_name = input_name.length() == 0 ? " " : input_name;
    input_name_times = TTF_RenderText_Solid(font, input_name.c_str(), textColor);
    //input_name_times = TTF_RenderText_Blended_Wrapped(font, input_name.c_str(), textColor, 180);
    apply_surface_bckgr(600, 250, 160, input_name_times->h, input_name_times, renderer, "input_name");
}

void users_scores()
{
    if (store_data != NULL)
    {
        int mapcols = store_data->users_map.size();
        if (mapcols > 0) 
        {
            names_list.clear();
            cout << "MENU - Users from map: " << endl;
            std::multimap<string, string>::reverse_iterator itermap;
            int n = 1;
            names_list.append("\n");
            names_list.append("Best scores: \n");
            //for (const auto& a : store_data->users_map)
            for (itermap = store_data->users_map.rbegin();
                itermap != store_data->users_map.rend();
                ++itermap)
            {
                std::stringstream ss;
                ss << (n);
                names_list += ss.str();
                names_list.append(".  ");
                names_list.append(itermap->second);
                names_list.append(":  ");
                names_list.append(itermap->first);
                names_list.append("\n");
                n++;
            }
            if (mapcols < 10)
                for (int i = mapcols+1; i <= 10; i++)
                {
                    std::stringstream ss;
                    ss << i;
                    names_list += ss.str();
                    names_list.append(". \n");
                }
            names_list.append("\n");
            cout << names_list;
        }

        names_list_times = TTF_RenderText_Blended_Wrapped(font_introduct, names_list.c_str(), textColor, 220);
        apply_surface_bckgr(50, 170, 500, 180, names_list_times, renderer, "names_list");
    }
}

void instructions_info()
{
    string line;
    ifstream instructs_file("Instructions.txt");
    if (instructs_file.is_open())
    {
        instruct_list.clear();
        instruct_list.append("\n");
        while (getline(instructs_file, line))
        {
            cout << line << '\n';
            instruct_list.append(line);
            instruct_list.append("\n");
        }
        instruct_list.append("\n");
        instructs_file.close();
    }
    else cout << "Unable to open file";
    
    /*
    char* instruct_text;
    instruct_file = SDL_RWFromFile("Instructions.txt", "r");
    if (instruct_file != NULL) {
        SDL_RWread(instruct_file, instruct_text, sizeof(instruct_text), 10);
        std::string str(instruct_text);
        instruct_times = TTF_RenderText_Blended_Wrapped(font, instruct_text, textColor, 80);
        apply_surface_bckgr(100, 450, 350, 100, instruct_times, renderer, "instruct_list");
        SDL_RWclose(instruct_file);
    }
    */
    
    instruct_times = TTF_RenderText_Blended_Wrapped(font_introduct, instruct_list.c_str(), textColor, 240);
    apply_surface_bckgr(50, 350, 500, 200, instruct_times, renderer, "instruct_list");
}