//
//  ofAppNoWindow.h
//  knit
//
//  Created by 한태재 on 2018. 2. 26..
//

#ifndef ofAppNoWindow_h
#define ofAppNoWindow_h


#endif /* ofAppNoWindow_h */


#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "scriptutility.h"
#include "ofxArgs.h"

class ofAppNoWindowRun : public ofBaseApp {
private:
    ofxArgs* args;
    string mediaroot, indivpath, imgname, option1, option2;
public:
    ofAppNoWindowRun(ofxArgs* args);
    void setup();
    //    void update();
    void runScript();
};

