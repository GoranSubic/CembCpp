#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main(int argc, char **argv)
{
	Point pt(100,100);

	Simple_window win(pt, 600, 400, "Canvas");

	win.wait_for_button();

	return 0;
}
