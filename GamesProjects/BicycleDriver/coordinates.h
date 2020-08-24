/**
 *  Coordinates header file - documenting code
 *
 */

#ifndef BIKES_COORDS_H
#define BIKES_COORDS_H

#include <SDL.h>

class cord{
protected:
    SDL_Rect cord_rect;
public:
    cord();
    cord(int x, int y, int w, int h);

    /// <summary>
    /// Returns the current x coardinate of the object...
    /// </summary>
    /// <returns>X coordinate of object</returns>
    int get_cord_x();              //Returns the current x coardinate of the object...

    /// <summary>
    /// Returns the current y coardinate of the object...
    /// </summary>
    /// <returns>Y coordinate of object</returns>
    int get_cord_y();              //Returns the current y coardinate of the object...

    /// <summary>
    /// Returns the current y coardinate of the object...
    /// </summary>
    /// <returns>Z coordinate of object</returns>
    int get_cord_w();

    /// <summary>
    /// Returns the current H coardinate of the object...
    /// </summary>
    /// <returns>H coordinate of object</returns>
    int get_cord_h();

    /// <summary>
    /// Coordinates of rectangle
    /// </summary>
    /// <returns>Object of rectangles type</returns>
    SDL_Rect get_rect();

};          //Holds the coordinates of the images

class background:public cord
{
private:

public:
    background();
    background(int x, int y, int w, int h);
    void add_background_x(int n);
};

class wall :public cord
{
private:
    bool state;
public:
    wall();
    wall(int x, int y, int w, int h);
    bool get_state();
    void set_state(bool s);
    void add_wall_x(int n);
};


#endif // BIKES_Coords