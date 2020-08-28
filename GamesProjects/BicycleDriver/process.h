/**
 *  Process header file - documenting code
 *
 */

#ifndef BIKES_PROCESS_H
#define BIKES_PROCESS_H

class bike_process {
public:
	void load_layer(int x = 0, int y = 0);
	void change_coardinate(int);
	void change_users_score(int);
	bool process();
};

#endif