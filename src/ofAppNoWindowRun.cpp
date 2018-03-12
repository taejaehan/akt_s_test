//
//  ofAppNoWindow.cpp
//  knit
//
//  Created by 한태재 on 2018. 2. 26..
//

#include "ofMain.h"
#include "ofAppNoWindowRun.h"
#include "ofAppNoWindow.h"

ofAppNoWindowRun::ofAppNoWindowRun(ofxArgs* args){
    this->args = args;
}
void ofAppNoWindowRun::setup(){
    if(this->args->contains("-imgname")){
        this->imgname = this->args->getString("-imgname");
    }
    if(this->args->contains("-mediaroot")){
        this->mediaroot = this->args->getString("-mediaroot");
    }
    if(this->args->contains("-indivpath")){
        this->indivpath = this->args->getString("-indivpath");
    }
    runScript();
}


void ofAppNoWindowRun::runScript()
{
    scriptUtility s = scriptUtility(this->mediaroot, this->indivpath, this->imgname);
    s.run();
    ofAppNoWindow::exitApp();
}

