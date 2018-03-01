//
//  ofAppNoWindow.h
//  knit
//
//  Created by 한태재 on 2018. 2. 26..
//

//#ifndef ofAppNoWindow_h
//#define ofAppNoWindow_h
//
//
//#endif /* ofAppNoWindow_h */


#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "scriptutility.h"

class ofAppNoWindowRun : public ofBaseApp {
    
public:
    void setup()
    {
        ofSetFrameRate(1000);
        ofAppNoWindowRun::runScript();
    }
    void update()
    {
    //    std::cout << ofGetFrameRate() << std::endl;
    }
//    void setup();
//    void update();
    void runScript(){
	scriptUtility s = scriptUtility();
        s.run();
    };
};

