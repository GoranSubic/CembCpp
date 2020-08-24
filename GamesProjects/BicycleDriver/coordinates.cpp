/**
 *  Coordinates cpp - documenting code
 *
 */

#include "coordinates.h"
#include "constants.h"

cord::cord()
{
    cord_rect.x = 0;
    cord_rect.y = 0;
    cord_rect.w = 0;
    cord_rect.h = 0;
}

cord::cord(int x, int y, int w, int h)
{
    cord_rect.x = x;
    cord_rect.y = y;
    cord_rect.w = w;
    cord_rect.h = h;
}

int cord::get_cord_x()              //Returns the current x coardinate of the object...
{
    return cord_rect.x;
}

int cord::get_cord_y()              //Returns the current y coardinate of the object...
{
    return cord_rect.y;
}

int cord::get_cord_w()
{
    return cord_rect.w;
}

int cord::get_cord_h()
{
    return cord_rect.h;
}

SDL_Rect cord::get_rect()
{
    return cord_rect;
}

background::background()
{}

background::background(int x, int y, int w, int h):cord(x, y, w, h)
{}

void background::add_background_x(int n)
{
    cord_rect.x += (n - 1);
    if (cord_rect.x < -WIDTH)
        cord_rect.x += (2 * WIDTH);
}

wall::wall()
{
    state = false;
}

wall::wall(int x, int y, int w, int h) :cord(x, y, w, h)
{
    state = false;
}
bool wall::get_state()
{
    return state;
}
void wall::set_state(bool s)
{
    state = s;
}
void wall::add_wall_x(int n)
{
    cord_rect.x += n;
    if (cord_rect.x > WIDTH or ((cord_rect.x + cord_rect.w) < 0))
        state = false;
    else
        state = true;
}