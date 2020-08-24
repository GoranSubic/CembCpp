/**
 *  Collision cpp - documenting code
 *
 */

#include "collision.h"
#include "surface.h"
#include "variable.h"

bool is_collision()
{
    SDL_Rect rect;
    rect.x = bike_x;
    rect.y = bike_y;
    rect.w = bike->w;
    rect.h = bike->h;

    for (int i = 0; i < SMAX_WALL; i++)    //Check collision of WALL..
        if (w1[i].get_state())     //When enabled WALL is found only then check the collision and exit the loop...
        {
            if (check_collision_wall(rect, w1[i].get_rect()))   //Check collision of the Bike and WALL 0...
            {
                return true;
                break;
            }
        }

    for (int i = 0; i < BMAX_WALL; i++)    //Check collision of WALL..
        if (w2[i].get_state())     //When enabled WALL is found only then check the collision and exit the loop...
        {
            if (check_collision_wall(rect, w2[i].get_rect()))   //Check collision of the Bike and WALL 0...
            {
                return true;
                break;
            }
        }

    return false;
}

bool check_collision_wall(SDL_Rect source, SDL_Rect dest)
{
    if (((source.x + source.w) < dest.x) or source.x > (dest.x + dest.w))
    {
        if ((bike_stand - bike->h) == dest.y - source.h)
            bike_stand = LAYER_Y;
        return false;
    }
    if (((source.y + source.h) <= dest.y))
    {
        bike_stand = dest.y;
        return false;
    }
    if (((source.y + source.h) <= (dest.y + 20)) and ((source.y + source.h) >= dest.y - 10))
    {
        bike_stand = dest.y;
        bike_y = dest.y - source.h;
        return false;
    }
    apply_surface(100, 300, die->w, die->h, die, renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    return true;
}