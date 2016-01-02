#ifdef __linux__	
#include "Application.hpp"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <iostream>
#include "Renderer.hpp"
#include <unistd.h>
void Application::quitApplication(){

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

int main(int argc, char** argv){
	
	Display                 *dpy;
	Window                  root;
	GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	XVisualInfo             *vi;
	Colormap                cmap;
	XSetWindowAttributes    swa;
	Window                  win;
	GLXContext              glc;
	XWindowAttributes       gwa;
	XEvent                  xev;


	dpy = XOpenDisplay(nullptr);
    if(dpy == nullptr) {
    	std::cout << "could not connect to x server\n";	
		return -1;
    }
    root = DefaultRootWindow(dpy);
      
    vi = glXChooseVisual(dpy, 0, att);

    if(vi == nullptr) {
		std::cout << "no appropiate visual found\n";
		return -1;
    } 

	cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;
    win = XCreateWindow(dpy, root, 0, 0,800, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
    XMapWindow(dpy, win);
    XStoreName(dpy, win, "BackMaze");
    glc = glXCreateContext(dpy, vi, nullptr, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);
	GLenum err = glewInit();
	Application* app = new Application(800,600);	
	
	for(;;){
		XNextEvent(dpy, &xev);
	
		if(xev.type == KeyPress) {
			std::cout << xev.xkey.keycode << "\n";
            char buf[128] = {0};
            KeySym keysym;
            int len = XLookupString(&xev.xkey, buf, sizeof buf, &keysym, NULL);
			if(xev.xkey.keycode == 9){            
				break;   
			}else{
				app->keyDown(xev.xkey.keycode);
			}
		}	

		XGetWindowAttributes(dpy, win, &gwa);
		
		app->gameLoop();		
		glFlush();
		glXSwapBuffers(dpy, win);


	}


	delete app;
	glXMakeCurrent(dpy, None, NULL);
    glXDestroyContext(dpy, glc);
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy); 
}

#endif
