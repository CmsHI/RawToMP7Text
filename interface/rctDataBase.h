#ifndef _rctDATABASE_h
#define _rctDATABASE_h

#include <iostream>
#include <stdexcept>
#include <vector>
#include <stdint.h>

namespace l1t{
  class rctDataBase {
  public:
    enum rctObjectType {
      RCEt,
      RCTau,
      RCOf,
      HFEt,
      HFFg,
      IEEt,
      IEPos,
      NEEt,
      NEPos,
      RCHad,
      nObjects};

  private:

    int RCEt_start[7][2];   //card, region
    int RCTau_start[7][2];  //card, region
    int RCOf_start[7][2];   //card, region
    int HFEt_start[8];      //region
    int HFFg_start[8];      //region
    int IEEt_start[4];      //candidate
    int IEPos_start[4];     //candidate
    int NEEt_start[4];      //candidate
    int NEPos_start[4];     //candidate
    int RCHad_start[7][2];  //card, region

    int length[nObjects];

    int link[nObjects];

  public:
    rctDataBase();
    ~rctDataBase(){};

    int GetLength(rctObjectType t)
    {
      return length[t];
    }

    int GetLink(rctObjectType t)
    {
      return link[t];
    }

    int GetIndices(rctObjectType t, int c, int r = -1)
    {
      switch (t){
      case RCEt:
	return RCEt_start[c][r];
      case RCTau:
	return RCTau_start[c][r];
      case RCOf:
	return RCOf_start[c][r];
      case HFEt:
	return HFEt_start[c];
      case HFFg:
	return HFFg_start[c];
      case IEEt:
	return IEEt_start[c];
      case IEPos:
	return IEPos_start[c];
      case NEEt:
	return NEEt_start[c];
      case NEPos:
	return NEPos_start[c];
      case RCHad:
	return RCHad_start[c][r];
      default:
	return -1;
      }
    }
  };
}
#endif
