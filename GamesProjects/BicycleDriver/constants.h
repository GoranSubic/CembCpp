/**
 *	Constants for height and width of the screen ..
 */

#ifndef BIKES_CONSTANTS_H
#define BIKES_CONSTANTS_H

/// <summary>
/// 0 - save data to txt file;
/// 1 - save data to database;
/// </summary>
const int SAVE_DATA_TO = 1; 

const int WIDTH = 800;
const int HEIGHT = 600;
const int BPP = 32;

//Constant for Layes..
const int START_LAYER_Y = 530;        //Starting y position of the base layer or the ground surface of the plane...

//Constants for BIKE...
const int START_BIKE_X = 150;                  //Starting coardinate of BIKE...
const int FINISH_BIKE_X = 250;               //Last positon of BIKE on the screen in x direction..

//constants for layer
const int LAYER_Y = 493;
//constants for wall
const int SMAX_WALL = 5;
const int BMAX_WALL = 4;
#endif