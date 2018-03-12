#include "scriptutility.h"
//#include "ofMain.h"
//#include "CoreOF.xcconfig"
scriptUtility::scriptUtility(string mediaroot, string indivpath, string imgName)
{
    this->mediaroot = mediaroot;
    this->indivpath = indivpath;
    this->imgName = imgName;
    
}

void scriptUtility::run()
{
    
//    string absolutePath = "/Users/h/Desktop/of_v0.9.8_osx_release/apps/myApps/knit";
    string absolutePath = "/home/ubuntu/of_v0.9.8_linux64_release/apps/myApps/akt_s_test";
    
//    std::cout << "OF_PATH: " << $(abc) << ":" << std::endl;
//    std::cout << "OF_PATH: " << $(ohho) << ":" << std::endl;
    
    string imageFn = "not set yet";

    //pics settings
    string outputFolder = absolutePath+"/outputPics/";
    //string imagesFn [6] =  {  "abstract2", "elgreco2" , "dance2", "starik2", "tree32", "tree42"};
//    string imagesFn [1] = { this->imgName };
    string imgName = "suji_01";
    string inputPath = absolutePath + "/inputPics/";
    string jsonPath = absolutePath+"/json/";
    string seqPath = absolutePath+"/seq/";
    if(this->imgName != "default" && this->mediaroot != "default" && this->indivpath != "default"){
        absolutePath = this->mediaroot;
        inputPath = absolutePath+ this->indivpath + "/";
        outputFolder = absolutePath+ this->indivpath+"/";
        seqPath = absolutePath+ this->indivpath+"/seq/";
        jsonPath = absolutePath+ this->indivpath+"/";
        imgName = this->imgName;
    }
    
    std::cout << "inputPath : " << inputPath << std::endl;
    std::cout << "imgName : " << imgName << std::endl;
    std::cout << "inputImgPath : " << inputPath+imgName << std::endl;
    string imagesFn [1] = { imgName };
    int imagesFnSize = 1;
    
    
//    string imagesFn [4] = { "lucky_02","oh_01","oh_02","suji_01" };
//    int imagesFnSize = 4;

    // position settings
//    string pinPositionsSaverFn = outputFolder + "pinPositions.dat";
    string pinPositionsInputFn = absolutePath + "/pinPos/" + "pinPositions_450.dat";

    for ( int i = 0; i < imagesFnSize; i++ ){

        ofImage pic;
        string imageFn = imagesFn[i];
        pic.load(inputPath + imageFn + ".jpg");
        //enum ofImageType{
            //OF_IMAGE_GRAYSCALE		= 0x00,
            //OF_IMAGE_COLOR			= 0x01,
            //OF_IMAGE_COLOR_ALPHA	= 0x02,
            //OF_IMAGE_UNDEFINED		= 0x03
        //};
        pic.setImageType(OF_IMAGE_GRAYSCALE);

        //genericShed * workshop = new colorShed(pic, imageFn);
        genericShed * workshop = new grayShed(pic, imageFn, jsonPath);
	
        abstractWheel wel = wheelFromFile(pinPositionsInputFn, workshop->w, workshop->h);
        wel.setup();

        workshop->setupWheel(wel);

        while ( workshop->stepsNumberP < workshop->maxStepsNumberP ){
            workshop->computeAndDrawOneStep();
            if ((workshop->stepsNumberP % 1000) == 1){

                workshop->saveResultImage(seqPath);

            }
            
            
        }
//        if((workshop->maxStepsNumberP - workshop->stepsNumberP) <= 10){
            workshop->saveLastResultImage(outputFolder, imageFn);
//        }

        wel.destroy();
        delete workshop;
    }


}
