/**
 *  Surface header file - documenting code
 *
 */

#ifndef BIKES_SURFACE_H
#define BIKES_SURFACE_H

#include <iostream>
#include <sstream>
#include <SDL.h>

 /// <summary>
 /// Rotate biker on UP key pressed
 /// </summary>
 /// <param name="x">X coordinate</param>
 /// <param name="y">Y coordinate</param>
 /// <param name="w">Width</param>
 /// <param name="h">Heigth</param>
 /// <param name="source">SDL_Surface</param>
 /// <param name="angle">Angle - step to rotate on each iteration...</param>
void rotate_surface(int x, int y, int w, int h, SDL_Surface* source, int angle);

void apply_surface_bckgr(int x, int y, int w, int h, SDL_Surface* source, SDL_Renderer* dest, const char* type_srf);

/// <summary>
/// For every Surface create Texture and then render it...
/// </summary>
/// <param name="x">X coordinate</param>
/// <param name="y">Y coordinate</param>
/// <param name="w">Width</param>
/// <param name="h">Heigth</param>
/// <param name="source">SDL_Surface</param>
/// <param name="dest">Renderer</param>
/// <param name="clip">Clip</param>
void apply_surface(int x, int y, int w, int h, SDL_Surface* source, SDL_Renderer* dest, SDL_Rect* clip = NULL);

#endif