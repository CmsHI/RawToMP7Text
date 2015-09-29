#include <iostream>
#include "../interface/DefineLinks.h"
#include <math.h>
#include "TString.h"


int main(){
    // DefineLinks *linksdefEventpp_1=new DefineLinks();
    // linksdefEventpp_1->ReadFileoRSC("InputsoRSC/output_5794135.txt");
    // linksdefEventpp_1->WriteFileMP7Format("OutputMP7/output_5794135.txt");

    // DefineLinks *linksdefEventpp_2=new DefineLinks();
    // linksdefEventpp_2->ReadFileoRSC("InputsoRSC/output_5800215.txt");
    // linksdefEventpp_2->WriteFileMP7Format("OutputMP7/output_5800215.txt");

    // DefineLinks *linksdefEventpp_3=new DefineLinks();
    // linksdefEventpp_3->ReadFileoRSC("InputsoRSC/output_5802847.txt");
    // linksdefEventpp_3->WriteFileMP7Format("OutputMP7/output_5802847.txt");

    //DefineLinks *linksdef=new DefineLinks();
    //linksdef->ReadFileoRSC("InputsoRSC/output_64eventsPion_WithDelay.txt");
    //linksdef->WriteFileMP7Format("OutputMP7/output_64eventsPion_WithDelay.txt");

    DefineLinks *linksdef=new DefineLinks();
    for(int i = 1; i <= 10; i++)
    {
      std::string input = Form("InputsoRSC/HI_Central_Data_%.2d.txt",i);
      std::string output = Form("OutputMP7/HI_Central_Data_%.2d.txt",i);
      linksdef->ReadFileoRSC(input);
      linksdef->WriteFileMP7Format(output);
    }

    // DefineLinks *linksdef2=new DefineLinks();
    // linksdef2->ReadFileoRSC("InputsoRSC/pp100Events_HISettings.txt");
    // linksdef2->WriteFileMP7Format("OutputMP7/pp100Events_HISettings.txt");


//    DefineLinks *testreadMP7=new DefineLinks();
//    testreadMP7->ReadFileMP7("OutputMP7/output_753539223.txt");
//    testreadMP7->WriteFileMP7Format("test.txt");

    return 0;
}
