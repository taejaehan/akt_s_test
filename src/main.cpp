#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindowRun.h"
#include "ofAppNoWindow.h"

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context
//    ofAppNoWindow window;
//    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
//    ofRunApp(new ofApp());

//    ofRunApp(new ofAppNoWindow());
    //scriptUtility s = scriptUtility();
    //s.run();
    
    ofAppNoWindow window;
    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
    ofRunApp(new ofAppNoWindowRun());

}
