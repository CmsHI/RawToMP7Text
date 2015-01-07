#ifndef _PHYSICSTOBITCONVERTER_h
#define _PHYSICSTOBITCONVERTER_h

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdint.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <bitset>
#include <stdint.h>
#include "rctDataBase.h"

namespace l1t{
  class PhysicsToBitConverter {


    int words32bitLink[2][6];  //[link][word]

    std::vector<int> bitsLink[2];
    rctDataBase databaseobject;


  public:

    PhysicsToBitConverter();
    ~PhysicsToBitConverter() { }
    void Set32bitWordLink0(int index,uint32_t value){words32bitLink[0][index]=value;};
    void Set32bitWordLink1(int index,uint32_t value){words32bitLink[1][index]=value;};
    void Convert();

    int GetObject(rctDataBase::rctObjectType t, int c, int r = -1);

    int ReadBitInInt(int bit,int value);
    int BuildPhysicsValue(int firstbit,int bitlength,int linkid);

  };
}
#endif
