//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//#include <string>
//#include "coordinates.h"
//#include "variable.h"
//#include "constants.h"

#include <iostream>
#include <sstream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "string"
#include "coordinates.h"

#ifndef BIKES_Init
#define BIKES_Init

bool init_all();

//Load a image file on screen and returns the address..
//SDL_Surface* load_image(std::string, int col1, int col2, int col3);
SDL_Surface* load_image(const char*, int col1, int col2, int col3);

bool load_files();

bool test_imgonscr();

#endif