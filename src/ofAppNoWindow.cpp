//
//  ofAppNoWindow.cpp
//  knit
//
//  Created by 한태재 on 2018. 2. 26..
//

#include "ofAppNoWindow.h"

void ofAppNoWindow::setup(){
    //onTypeOfShedValidatedPressed();
    ofAppNoWindow::runScript();
}

void ofAppNoWindow::runScript()
{
    scriptUtility s = scriptUtility();
    s.run();
}
