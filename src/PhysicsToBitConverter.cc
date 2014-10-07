#include "../interface/PhysicsToBitConverter.h"

PhysicsToBitConverter::PhysicsToBitConverter() {

}

void PhysicsToBitConverter::Convert() {

  for (int iword=0;iword<6;iword++){
    for (int ibit=0;ibit<32;ibit++){
      bitsLink[0].push_back(ReadBitInInt(ibit,words32bitLink[0][iword]));
      bitsLink[1].push_back(ReadBitInInt(ibit,words32bitLink[1][iword]));
    }
  }
}

int PhysicsToBitConverter::GetRCEt(int card,int region){

  int mystart=databaseobject.GetIndicesRCEt(card,region);
  int mylength=databaseobject.GetRCEtLength();
  int mylink=databaseobject.GetRCEtLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetHFEt(int region){

  int mystart=databaseobject.GetIndicesHFEt(region);
  int mylength=databaseobject.GetHFEtLength();
  int mylink=databaseobject.GetHFEtLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetRCTau(int card,int region){

  int mystart=databaseobject.GetIndicesRCTau(card,region);
  int mylength=databaseobject.GetRCTauLength();
  int mylink=databaseobject.GetRCTauLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetRCOf(int card,int region){

  int mystart=databaseobject.GetIndicesRCOf(card,region);
  int mylength=databaseobject.GetRCOfLength();
  int mylink=databaseobject.GetRCOfLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetHFFg(int region){

  int mystart=databaseobject.GetIndicesHFFg(region);
  int mylength=databaseobject.GetHFFgLength();
  int mylink=databaseobject.GetHFFgLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetNEPos(int cand){

  int mystart=databaseobject.GetIndicesNEPos(cand);
  int mylength=databaseobject.GetNEPosLength();
  int mylink=databaseobject.GetNEPosLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetNEEt(int cand){

  int mystart=databaseobject.GetIndicesNEEt(cand);
  std::cout<<"GetIndicesNEEt"<<mystart<<std::endl;
  int mylength=databaseobject.GetNEEtLength();
  int mylink=databaseobject.GetNEEtLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetIEPos(int cand){

  int mystart=databaseobject.GetIndicesIEPos(cand);
  int mylength=databaseobject.GetIEPosLength();
  int mylink=databaseobject.GetIEPosLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetIEEt(int cand){

  int mystart=databaseobject.GetIndicesIEEt(cand);
  int mylength=databaseobject.GetIEEtLength();
  int mylink=databaseobject.GetIEEtLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}

int PhysicsToBitConverter::GetRCHad(int card,int region){

  int mystart=databaseobject.GetIndicesRCHad(card,region);
  int mylength=databaseobject.GetRCHadLength();
  int mylink=databaseobject.GetRCHadLink();

  return BuildPhysicsValue(mystart,mylength,mylink);
}


int PhysicsToBitConverter::ReadBitInInt(int bit,int value){

   std::bitset<32> foo(value);
   return foo[bit];

}

int PhysicsToBitConverter::BuildPhysicsValue(int firstbit,int bitlength,int linkid){

  int myvalue=0;
  int counter=0;

  for (int m=firstbit;m<firstbit+bitlength;m++){
    myvalue|=(bitsLink[linkid][m]&(0x1)) << counter;
    counter++;
  }
  return myvalue;
}