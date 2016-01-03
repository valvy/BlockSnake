#ifdef __linux__	

#include <iostream>
#include "Renderer.hpp"
#include <unistd.h>
#include "GnuApp.hpp"

GnuApp* app;
bool shouldStop;
void Application::quitApplication(){
	shouldStop = true;
	
}

#define GetCurrentDir getcwd
std::string Application::getAppPath() const{
    char cCurrentPath[FILENAME_MAX];
    
    if(!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        return "Error";
    }
    
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
    
    return cCurrentPath;
}


void GnuApp::loop(){

	//Make sure when the user press the exit button.. it cleans everything up
	Atom              wm_protocols;
	Atom              wm_delete_window;
	wm_protocols = XInternAtom(dpy, "WM_PROTOCOLS", False);
  	wm_delete_window = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
  	XSetWMProtocols(dpy, win, &wm_delete_window, 1);
	XEvent	xev;
	for(;;){
		if(shouldStop){		
			return; //stop when the app asks for it
		}
		while(XPending(dpy)){//Do not hang the app while waiting for input
			XNextEvent(dpy, &xev);
	
			if(xev.type == KeyPress) {
				this->mainApp->keyDown(xev.xkey.keycode);
			
			}else if (xev.xclient.message_type == wm_protocols &&
            	xev.xclient.data.l[0] == wm_delete_window)  {
				return;
        	}
		
		}
		XWindowAttributes       gwa;
		XGetWindowAttributes(dpy, win, &gwa);
		this->mainApp->gameLoop();		
		glFlush();
		glXSwapBuffers(dpy, win);
	}

}



GnuApp::GnuApp(){
	shouldStop = false;
	GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };

	this->dpy = XOpenDisplay(nullptr);
    if(this->dpy == nullptr) {
    	std::cout << "could not connect to x server\n";	
		return;
    }
    this->root = DefaultRootWindow(this->dpy);
      
	XVisualInfo	*vi;
   	vi = glXChooseVisual(this->dpy, 0, att);

    if(vi == nullptr) {
		std::cout << "no appropiate visual found\n";
		return;
    } 
	Colormap	cmap;
	
	cmap = XCreateColormap(this->dpy, this->root, vi->visual, AllocNone);
	XSetWindowAttributes swa;
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;

	XWindowAttributes xwa;
	XGetWindowAttributes(dpy, DefaultRootWindow(dpy), &xwa);


    win = XCreateWindow(dpy, root, 0, 0, xwa.width, xwa.height, 0, vi->depth, InputOutput, vi->visual,CWBackingStore | CWSaveUnder| CWBorderPixel | CWBackingStore | CWColormap | CWEventMask, &swa);


	Atom prop = None;
	prop = XInternAtom(dpy, "_MOTIF_WM_HINTS", True);
 	XMapRaised(dpy,root);

    XMapWindow(dpy, win);
    XStoreName(dpy, win, "BlockSnake");

	//Setup opengl	
    glc = glXCreateContext(dpy, vi, nullptr, GL_TRUE);
    glXMakeCurrent(dpy, win, glc); 


	GLenum err = glewInit();
	if (GLEW_OK != err){
		std::cout << "an error has occured : " << glewGetErrorString(err) << "\n";
		std::cout << "closing blocksnake\n";
		return;
	}


	if (!GLEW_VERSION_4_1){
		std::cout << "Blocksnake requires at least opengl 4.1. \n";
		std::cout << "It is recommended to use the propieriatary versions of the video card drivers\nClosing the app\n";
		return;

	}
	


	this->mainApp = new Application(xwa.width,xwa.height);	


	this->loop();


	
}


GnuApp::~GnuApp(){

	//Close the window nice and neat
	glXMakeCurrent(dpy, None, nullptr);
    glXDestroyContext(dpy, glc);
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy); 
	if(mainApp != nullptr){
		delete this->mainApp;
	}
}

int main(int argc, char** argv){
	app = new GnuApp();
	delete app;
}

#endif
