#ifdef __APPLE__
#import "MacApp.h"
#import <iostream>

@implementation MacApp

@synthesize glView;

-(id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)aStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)flag{
    
    if(self = [super initWithContentRect:contentRect styleMask:aStyle backing:bufferingType defer:flag]){
        
        
        [self setTitle:[[NSProcessInfo processInfo] processName]];
        [self makeKeyAndOrderFront:self];
        [self setAcceptsMouseMovedEvents:YES];
        
        //Setup an opengl window with opengl 3_2+
        NSOpenGLPixelFormatAttribute pixelFormatAttributes[] ={
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
            NSOpenGLPFAColorSize    , 24                           ,
            NSOpenGLPFAAlphaSize    , 8                            ,
            NSOpenGLPFADoubleBuffer ,
            NSOpenGLPFAAccelerated  ,
            NSOpenGLPFANoRecovery   ,
            0
        };
        
        
        NSOpenGLPixelFormat* format = [[NSOpenGLPixelFormat alloc]initWithAttributes:pixelFormatAttributes];
        
        glView = [[NSOpenGLView alloc]initWithFrame:contentRect pixelFormat:format];
        
        //Set context and attach it to the window
        [[glView openGLContext]makeCurrentContext];
      
        //Do stuff required to make a fullscreen window
        [self setContentView:glView];
        [glView prepareOpenGL];
        [self makeKeyAndOrderFront:self];
        [self setAcceptsMouseMovedEvents:YES];
        [NSApp activateIgnoringOtherApps:YES];
        [self setLevel:NSMainMenuWindowLevel+1];
        [self setOpaque:YES];
        [self setHidesOnDeactivate:YES];
        
        //Initialize the app..
        self->app = new Application(contentRect.size.width, contentRect.size.height);
        
        
    }
    
    return self;
    
}

-(void)keyDown:(NSEvent*) event{

 //   std::cout << [event keyCode] << "\n";
    if([event keyCode] == 53){
        [self close];
    }
    else{
        //Pass the key down event to the app
        self->app->keyDown([event keyCode]);
    }
}

-(BOOL)canBecomeKeyWindow {
    //this is required to receive input..
    return YES;
}

- (void)applicationWillFinishLaunching:(NSNotification *)notification{
    //setup the menubar
    NSMenu* mainMenu = [[NSMenu alloc] initWithTitle:@"MainMenu"];
    NSMenuItem* appleMenuItem;
    NSMenu* appleSubMenu;
    NSString* applicationName = [[NSProcessInfo processInfo]processName];
    NSMenuItem* appMenuItem;
    
    appleMenuItem = [mainMenu addItemWithTitle:@"Apple" action:NULL keyEquivalent:@""];
    appleSubMenu = [[NSMenu alloc]initWithTitle:@"Apple"];
    
    appMenuItem = [appleSubMenu addItemWithTitle:[NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"About", nil), applicationName] action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""];
    [appMenuItem setTarget:NSApp];
    [appleSubMenu addItem:[NSMenuItem separatorItem]];
    
    appMenuItem = [appleSubMenu addItemWithTitle:[NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"Quit", nil), applicationName] action:@selector(terminate:) keyEquivalent:@"q"];
    [appMenuItem setTarget:NSApp];
    
    [mainMenu setSubmenu:appleSubMenu forItem:appleMenuItem];
    [NSApp setMainMenu:mainMenu];
}

-(void) drawLoop:(NSTimer*) timer{
    self->app->drawLoop();
    [glView update];
     [[glView openGLContext] flushBuffer];
}



- (void)applicationDidFinishLaunching:(NSNotification *)notification {
    //set the main loop
    [NSTimer scheduledTimerWithTimeInterval:0.000001 target:self selector:@selector(drawLoop:) userInfo:nil repeats:YES];
    
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication{
    return YES;//Close it... or it will cause an segmentation error. (appdelegate will be destroyed...)
}

- (void)applicationWillTerminate:(NSNotification *)aNotification{
    self->app->onClose();//give an close call.. The deconstructor might be good to but an clang-4 bug causes the deconstructor not being called :-(
    
    [self release]; //Object suicide.. it's no longer needed
}

-(void) dealloc{
    if(self->app != nullptr){
        delete self->app;//Delete the app
        self->app = nullptr;
    }
    
    if(glView != nil){
        [glView clearGLContext];
        [glView release];
        glView = nil;
    }

    [super dealloc];
}

@end

int main(){

    NSRect mainDisplayRect = [[NSScreen mainScreen] frame];
    application = [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    MacApp* app =  [[MacApp alloc]initWithContentRect: mainDisplayRect styleMask:NSBorderlessWindowMask backing:
                    NSBackingStoreBuffered defer:YES];
    [application setDelegate:app];
    [application run];
    
    
}


#endif