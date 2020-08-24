/**
 *  Collision header file - documenting code
 *
 */

#ifndef BIKES_COLLISION_H
#define BIKES_COLLISION_H

#include <SDL.h>

/// <summary>
/// Detect collision when moving RIGHT side, of the Bike and WALL...
/// </summary>
/// <param name="source">Bike</param>
/// <param name="dest">Wall</param>
/// <returns>false if no collision and game moves forward</returns>
bool check_collision_wall(SDL_Rect, SDL_Rect);

/// <summary>
/// Check if collision happend - if bycicle has not jumbed over wall
/// </summary>
/// <returns>true when collision happen, otherwise returns false..</returns>
bool is_collision();

#endif