#ifndef SCRIPTUTILITY_H
#define SCRIPTUTILITY_H

#include "ofMain.h"
#include "grayshed.h"
#include "colorshed.h"


class scriptUtility
{
public:
    
    string imgName;
    string indivpath;
    string mediaroot;
    scriptUtility(string mediaroot, string indivpath, string imgName);
    void run();

};

#endif // SCRIPTUTILITY_H
