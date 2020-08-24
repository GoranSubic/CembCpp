/**
 *	Initial header file - documenting code..
 *
 */

#ifndef BIKES_INIT_H
#define BIKES_INIT_H

#include <iostream>
#include <sstream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "string"
#include "coordinates.h"

 /// <summary>
 /// Initialize window, renderer and fonts
 /// </summary>
 /// <returns>true if everything is ok</returns>
bool init_all();

/// <summary>
/// Load a image file on screen and returns the address..
/// </summary>
/// <param name="filename">Location of file</param>
/// <param name="col1">Color</param>
/// <param name="col2">Color</param>
/// <param name="col3">Color</param>
/// <returns>Pointer to surface with image</returns>
SDL_Surface* load_image(const char*, int col1, int col2, int col3);

/// <summary>
/// Load files to set variables of surfaces...
/// </summary>
/// <returns>true if everything is ok</returns>
bool load_files();

/// <summary>
/// Reset variables to start game again from zero...
/// </summary>
/// <returns>true if everything is ok</returns>
bool init_restart();

/// <summary>
/// Function used to test SDL2 library
/// </summary>
/// <returns>true in the end...</returns>
bool test_imgonscr();

#endif