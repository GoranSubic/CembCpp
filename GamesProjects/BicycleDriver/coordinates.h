#include <SDL.h>

#ifndef BIKES_Coords
#define BIKES_Coords

class cord{
protected:
    SDL_Rect cord_rect;
public:
    cord(int x, int y, int w, int h);
    int get_cord_x();              //Returns the current x coardinate of the object...
    int get_cord_y();              //Returns the current y coardinate of the object...
    int get_cord_w();
    int get_cord_h();
    SDL_Rect get_rect();    //Returns rectangle and take width of the picture as a argument..
                            //Sets the width and the height of the current picture..

};          //Holds the coardinates of the images

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