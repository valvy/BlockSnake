#ifndef MAC_APP_H
#define MAC_APP_H
#ifdef __APPLE__
#import <Cocoa/Cocoa.h>
#import "Application.hpp"


NSApplication* application;

@interface MacApp : NSWindow <NSApplicationDelegate>{
    Application* app;
}
@property (nonatomic, retain) NSOpenGLView* glView;
//-(void) mainLoop:(NSTimer*)timer;
-(void) drawLoop:(NSTimer*) timer;
-(void) stopMacApp;
@end

#endif
#endif