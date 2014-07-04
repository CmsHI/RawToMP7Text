#include <iostream>
#include "../interface/DefineLinks.h"
#include <math.h>


int main(){
    DefineLinks *linksdefEventpp_1=new DefineLinks();
    linksdefEventpp_1->ReadFileoRSC("InputsoRSC/outputoRSC_Eventpp_1.txt");
    linksdefEventpp_1->WriteFileMP7Format("OutputMP7/outputoRSC_Eventpp_1.txt");

    DefineLinks *linksdefEventpp_2=new DefineLinks();
    linksdefEventpp_2->ReadFileoRSC("InputsoRSC/outputoRSC_Eventpp_2.txt");
    linksdefEventpp_2->WriteFileMP7Format("OutputMP7/outputoRSC_Eventpp_2.txt");

    DefineLinks *linksdefEventpp_3=new DefineLinks();
    linksdefEventpp_3->ReadFileoRSC("InputsoRSC/outputoRSC_Eventpp_3.txt");
    linksdefEventpp_3->WriteFileMP7Format("OutputMP7/outputoRSC_Eventpp_3.txt");

    return 0;
}
