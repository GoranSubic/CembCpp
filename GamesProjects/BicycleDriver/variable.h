/**
 *  Variable header file - documenting code
 *
 */

#ifndef BIKES_VARS_H
#define BIKES_VARS_H

#include <soci/soci.h>
#include <SDL_ttf.h>
#include "dbconnection.h"
#include "constants.h"
#include "coordinates.h"
#include <string>

soci::session* sql;
StorageData* store_data = NULL;

SDL_Window* screen = NULL;
SDL_Renderer* renderer = NULL;
SDL_Rect* scr_rect = NULL;

SDL_Surface* back[2] = { NULL,NULL };       //Holds two backgrounds..
SDL_Surface* upback = NULL;
SDL_Surface* bike = NULL;
SDL_Surface* obs_wall[2] = { NULL,NULL };
SDL_Surface* menu_pic = NULL;
SDL_Surface* play_menu = NULL;
SDL_Surface* instruction_menu = NULL;
SDL_Surface* quit_menu = NULL;

TTF_Font* font = NULL;
TTF_Font* font_introduct = NULL;

std::string input_name = "No Name";
std::string names_list = "Empty List";
std::string instruct_list = "Empty List";
SDL_Surface* input_name_times = NULL;
SDL_Surface* names_list_times = NULL;
SDL_Surface* instruct_times = NULL;
SDL_Surface* users_nick_name = NULL;
SDL_Surface* achieved_score = NULL;
SDL_Surface* score_times = NULL;
int score = 1;

SDL_Surface* times = NULL;
SDL_Surface* time_limit = NULL;
SDL_Surface* die = NULL;

SDL_Color textColor = { 225,0,0 };
SDL_Event event;                             //For checking the event happen...
//Uint8* keystate = SDL_GetKeyState(NULL);       //for check key event keys..
const Uint8* keybstate = SDL_GetKeyboardState(NULL);

//Variable for background...
background bg[2];

//variable for time..
int start_time;
int end_time;
int time_gap;

int speed;
int angle = 0;
int angle_count = 0;

int jump_state = 0;
int max_limit = 200;

//variable for bike..
int bike_stand = LAYER_Y;
int bike_x = START_BIKE_X;
int bike_y;
//Variable for wall...
wall w1[SMAX_WALL];
wall w2[BMAX_WALL];

//Game states..
int game_on = 1;

#endif // BIKES_VARS_H
