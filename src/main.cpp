#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindowRun.h"
#include "ofAppNoWindow.h"
#include "ofAppGlutWindow.h"
#include "ofxArgs.h"

//========================================================================
int main(int argc, char *argv[] ){
    
    ofxArgs* args = new ofxArgs(argc, argv);
    std::cout << "args!"<< args << std::endl;
    args->printArgs();
    args->printOpts();
 
    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context
    
    
//    ofAppGlutWindow window;
//    ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
    ofAppNoWindow window;
    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);

    ofRunApp(new ofAppNoWindowRun(args));
//    ofRunApp(new ofApp());
    delete args;

}
