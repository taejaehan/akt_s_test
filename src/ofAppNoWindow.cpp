//
//  ofAppNoWindow.cpp
//  knit
//
//  Created by 한태재 on 2018. 2. 26..
//

#include "ofAppNoWindow.h"

void ofAppNoWindow::setup(){
    //onTypeOfShedValidatedPressed();
//    ofAppNoWindow window;
//    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
    ofAppNoWindow::runScript();
}

void ofAppNoWindow::runScript()
{
    scriptUtility s = scriptUtility();
    s.run();
}



//#include "ofMain.h"
//#include "ofAppNoWindow.h"
//
//class ofApp : public ofBaseApp {
//    
//public:
//    void setup()
//    {
//        ofSetFrameRate(1000);
//    }
//    void update()
//    {
//        std::cout << ofGetFrameRate() << std::endl;
//    }
//};
//
//int main()
//{
//    ofAppNoWindow window;
//    ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
//    ofRunApp(new ofApp());
//}

