#ifdef __linux__    

#include <iostream>
#include "Renderer.hpp"
#include <unistd.h>
#include "GnuApp.hpp"


typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);


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
    XEvent  xev;
    for(;;){
        if(shouldStop){     
            return; //stop when the app asks for it
        }
        while(XPending(dpy)){//Do not hang the app while waiting for input
            XNextEvent(dpy, &xev);
    
            if(xev.type == KeyPress) {
                this->mainApp->keyDown(xev.xkey.keycode);
            
            }else if (xev.xclient.message_type == wm_protocols &&
                xev.xclient.data.l[0] ==(unsigned int) wm_delete_window)  {
                return;
            }
        
        }
        //Render the program
        this->mainApp->gameLoop();      
        glFlush();
        glXSwapBuffers(dpy, win);
    }

}



GnuApp::GnuApp(){
    shouldStop = false;

    static int visual_attribs[] ={
        GLX_X_RENDERABLE    , True,
        GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
        GLX_RENDER_TYPE     , GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
        GLX_RED_SIZE        , 8,
        GLX_GREEN_SIZE      , 8,
        GLX_BLUE_SIZE       , 8,
        GLX_ALPHA_SIZE      , 8,
        GLX_DEPTH_SIZE      , 24,
        GLX_STENCIL_SIZE    , 8,
        GLX_DOUBLEBUFFER    , True,
        None
    };

    this->dpy = XOpenDisplay(nullptr);
    if(this->dpy == nullptr) {
        std::cout << "could not connect to x server\n"; 
        return;
    }
    this->root = DefaultRootWindow(this->dpy);
  
    int fbcount;
    GLXFBConfig *fbc = glXChooseFBConfig( dpy, DefaultScreen( dpy ), 
    visual_attribs, &fbcount );
    const GLXFBConfig bestFbc = fbc[0];

    XVisualInfo *vi = glXGetVisualFromFBConfig( dpy, bestFbc );
    root = DefaultRootWindow(dpy);


    if(vi == nullptr) {
        std::cout << "no appropiate visual found\n";
        return;
    } 
    Colormap    cmap;
    
    cmap = XCreateColormap(this->dpy, this->root, vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;

    XWindowAttributes xwa;
    XGetWindowAttributes(dpy, DefaultRootWindow(dpy), &xwa);


    this->win = XCreateWindow(dpy, root, 0, 0, xwa.width, xwa.height, 0, vi->depth, InputOutput, vi->visual,CWColormap | CWEventMask, &swa);


    XMapRaised(this->dpy,this->root);
    XMapWindow(this->dpy, this->win);
    XStoreName(this->dpy, this->win, "BlockSnake");
    int attribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 4,
        GLX_CONTEXT_MINOR_VERSION_ARB, 0,
        0
    };

    glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
    glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc) glXGetProcAddress((const GLubyte*)"glXCreateContextAttribsARB");

   //Setup opengl  
    this->glc = glXCreateContextAttribsARB(dpy, *fbc, nullptr, true, attribs);
  //  glc = glXCreateContext(dpy, vi, nullptr, GL_TRUE);
    glXMakeCurrent(dpy, win, glc); 

    //initialize
    glewExperimental = GL_TRUE; 
    GLenum err = glewInit();
    if (GLEW_OK != err){
        std::cout << "an error has occured : " << glewGetErrorString(err) << "\n";
        std::cout << "closing blocksnake\n";
        return;
    }

    //std::cout << glewGetString(GLEW_VERSION)) << "\n";

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
    //When the the app doesnt't work properly the mainapp is a null
    if(mainApp != nullptr){
        delete this->mainApp;
    }
}

int main(int argc, char** argv){
    app = new GnuApp();
    delete app;
}

#endif
