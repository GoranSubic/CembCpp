/**
 *	Menu header file - documenting code..
 *
 */

#ifndef BIKES_MENU_H
#define BIKES_MENU_H

 /// <summary>
 /// Start window with links coordinates...
 /// </summary>
 /// <returns>Zero on exit or on end of game...</returns>
int start_menu();

/// <summary>
/// Input players name (and write to database)
/// </summary>
void get_players_name();

/// <summary>
/// Show information about users scores - on instruction page
/// </summary>
void users_scores();

/// <summary>
/// Show instructions info (after info about users scores) on instructions page
/// </summary>
void instructions_info();

#endif