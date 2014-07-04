#include <iostream>
#include "../interface/DefineLinks.h"
#include <math.h>


int main(){
    DefineLinks *linksdefEventpp_1=new DefineLinks();
    linksdefEventpp_1->ReadFileoRSC("InputsoRSC/output_753539223.txt");
    linksdefEventpp_1->WriteFileMP7Format("OutputMP7/output_753539223.txt");

    DefineLinks *linksdefEventpp_2=new DefineLinks();
    linksdefEventpp_2->ReadFileoRSC("InputsoRSC/output_753585983.txt");
    linksdefEventpp_2->WriteFileMP7Format("OutputMP7/output_753585983.txt");

    DefineLinks *linksdefEventpp_3=new DefineLinks();
    linksdefEventpp_3->ReadFileoRSC("InputsoRSC/output_753694855.txt");
    linksdefEventpp_3->WriteFileMP7Format("OutputMP7/output_753694855.txt");

    return 0;
}
