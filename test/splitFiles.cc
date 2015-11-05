#include <iostream>
#include "../interface/DefineLinks.h"
#include <math.h>
//#include "TString.h"


int main(int argc, char **argv){
  if(argc == 3)
  {
    DefineLinks *linksdef=new DefineLinks();
    linksdef->ReadFileoRSC(argv[1]);
    linksdef->WriteFileMP7Format(argv[2]);

    return 0;
  } else {
    return 1;
  }
}
