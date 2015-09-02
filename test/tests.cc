#include <iostream>
#include "../interface/DefineLinks.h"
#include <math.h>


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
    linksdef->ReadFileoRSC("InputsoRSC/Run254790_rlxTau_withDelay.txt");
    linksdef->WriteFileMP7Format("OutputMP7/Run254790_rlxTau_withDelay.txt");

//    DefineLinks *testreadMP7=new DefineLinks();
//    testreadMP7->ReadFileMP7("OutputMP7/output_753539223.txt");
//    testreadMP7->WriteFileMP7Format("test.txt");

    return 0;
}
