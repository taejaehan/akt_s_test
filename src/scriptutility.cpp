#include "scriptutility.h"


scriptUtility::scriptUtility()
{

}

void scriptUtility::run()
{
    
//    string absolutePath = "/Users/h/Desktop/of_v0.9.8_osx_release/apps/myApps/knit";
    string absolutePath = "/home/ubuntu/of_v0.9.8_linux64_release/apps/myApps/akt_s_test";
    string imageFn = "not set yet";

    //pics settings
    string outputFolder = absolutePath+"/outputPics/";
    //string imagesFn [6] =  {  "abstract2", "elgreco2" , "dance2", "starik2", "tree32", "tree42"};
    string imagesFn [1] = { "lucky_02" };
    int imagesFnSize = 1;


    // position settings
    string pinPositionsSaverFn = outputFolder + "pinPositions.dat";
    string pinPositionsInputFn = outputFolder + "inputPinPositions.dat";


    for ( int i = 0; i < imagesFnSize; i++ ){

        ofImage pic;
        string imageFn = imagesFn[i];
        pic.load(absolutePath+"/inputPics/" + imageFn + ".jpg");
        //enum ofImageType{
            //OF_IMAGE_GRAYSCALE		= 0x00,
            //OF_IMAGE_COLOR			= 0x01,
            //OF_IMAGE_COLOR_ALPHA	= 0x02,
            //OF_IMAGE_UNDEFINED		= 0x03
        //};
        pic.setImageType(OF_IMAGE_GRAYSCALE);

        //genericShed * workshop = new colorShed(pic, imageFn);
        genericShed * workshop = new grayShed(pic, imageFn);

        abstractWheel wel = wheelFromFile(pinPositionsInputFn, workshop->w, workshop->h);
        wel.setup();

        workshop->setupWheel(wel);

        while ( workshop->stepsNumberP < workshop->maxStepsNumberP ){
            workshop->computeAndDrawOneStep();
            if ((workshop->stepsNumberP % 1000) == 1){

                workshop->saveResultImage(outputFolder);

            }
        }

        wel.destroy();
        delete workshop;
    }


}
