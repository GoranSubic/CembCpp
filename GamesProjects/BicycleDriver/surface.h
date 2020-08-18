#pragma once
#include <iostream>
#include <sstream>
#include <SDL.h>

#ifndef BIKES_Surface
#define BIKES_Surface

void apply_surface(int x, int y, int w, int h, SDL_Surface* source, SDL_Renderer* dest, SDL_Rect* clip = NULL);

#endif