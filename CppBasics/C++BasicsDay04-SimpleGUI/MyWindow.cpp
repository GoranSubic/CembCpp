#include "MyWindow.h"


MyWindow::MyWindow(Point xy, int w, int h, const string& title) :
Window(xy,w,h,title),
	inBox(Point(100, 20), 70, 20, "inBox - test label"),
	outBox(Point(100, 40), 70, 20, "outBox - test label"),
	menu(Point(0, 0), 150, 20, Menu::horizontal, "Menu"),
	showButton(Point(x_max()-120, 20), 120, 20, "Copy - test name", cb_showButton),
	showButtonPushed(false)
{
	menu.attach(showButton);
	attach(menu);
	attach(inBox);
	attach(outBox);
}


MyWindow::~MyWindow(void)
{
}


bool MyWindow::wait_for_button()
{
	show();
	Fl::run();
	return true;
}


void MyWindow::cb_showButton(Address, Address pw)
{
	reference_to<MyWindow>(pw).showButtonHandler();
}


void MyWindow::showButtonHandler()
{
	outBox.put(inBox.get_string());
}
