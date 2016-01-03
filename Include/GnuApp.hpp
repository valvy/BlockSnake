#ifndef GNU_APP_HPP
#define GNU_APP_HPP
#ifdef __linux__
#include <X11/X.h>
#include <X11/Xlib.h>
#include "Application.hpp"
class GnuApp{
private:
	
	Display                 *dpy;
	Window                  root;
	GLXContext	glc;
	Window                  win;
	
	Application* mainApp;	

	void loop();
	
public:
	GnuApp();
	~GnuApp();
};

#endif
#endif
