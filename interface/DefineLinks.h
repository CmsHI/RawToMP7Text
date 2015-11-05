#ifndef _DEFINELINKS_h
#define _DEFINELINKS_h

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdint.h>
#include <iomanip>
#include <sstream>

#define NLinks 36
#define NwordsInLinkActive 654
#define NwordsInLink 1024
#define MAXARRAYSIZE 8400


class DefineLinks {
  private:

    int noRSCint[MAXARRAYSIZE][NLinks];
    int nMP7int[MAXARRAYSIZE][NLinks];

    int counter = 0;

  public:
    DefineLinks();
    ~DefineLinks() { }
    void ReadFileoRSC(std::string);
    void ReadFileMP7(std::string);
    void WriteFileMP7Format(std::string);
    int maplinkfromoRSCtoMP7(int);
    int maplinkfromMP7tooRSC(int);

};

#endif
