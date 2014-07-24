#include "DataBase.h"


DataBase::DataBase() {

  RCETlength=10;
  RCTaulength=1;
  RCOflength=1;
  HFEtlength=8;
  HFFglength=1;
  IEEtlength=6;
  IEPoslength=4;
  NEEtlength=6;
  NEPoslength=4;
  RCHadlength=1;

  RCETlink=0;
  RCTaulink=0;
  RCOflink=0;
  HFEtlink=1;
  HFFglink=1;
  IEEtlink=1;
  IEPoslink=1;
  NEEtlink=1;
  NEPoslink=1; 
  RCHadlink=1;

  RCEt_start[0][0]=8;  
  RCEt_start[0][1]=18;  
  RCEt_start[1][0]=28;  
  RCEt_start[1][1]=38;  
  RCEt_start[2][0]=48;  
  RCEt_start[2][1]=58;  
  RCEt_start[3][0]=68; 
  RCEt_start[3][1]=78; 
  RCEt_start[4][0]=88;  
  RCEt_start[4][1]=98;  
  RCEt_start[5][0]=108; 
  RCEt_start[5][1]=118; 
  RCEt_start[6][0]=128; 
  RCEt_start[6][1]=138;
  
  RCTau_start[0][0]=148; 
  RCTau_start[0][1]=149; 
  RCTau_start[1][0]=150; 
  RCTau_start[1][1]=151; 
  RCTau_start[2][0]=152; 
  RCTau_start[2][1]=153; 
  RCTau_start[3][0]=154;
  RCTau_start[3][1]=155; 
  RCTau_start[4][0]=156; 
  RCTau_start[4][1]=157; 
  RCTau_start[5][0]=158; 
  RCTau_start[5][1]=159; 
  RCTau_start[6][0]=160; 
  RCTau_start[6][1]=161;
  
  RCOf_start[0][0]=162; 
  RCOf_start[0][1]=163; 
  RCOf_start[1][0]=164; 
  RCOf_start[1][1]=165; 
  RCOf_start[2][0]=166; 
  RCOf_start[2][1]=167; 
  RCOf_start[3][0]=168;
  RCOf_start[3][1]=169; 
  RCOf_start[4][0]=170; 
  RCOf_start[4][1]=171; 
  RCOf_start[5][0]=172; 
  RCOf_start[5][1]=173; 
  RCOf_start[6][0]=174; 
  RCOf_start[6][1]=175;
  
  HFEt_start[0]=8; 
  HFEt_start[1]=16; 
  HFEt_start[2]=24; 
  HFEt_start[3]=32; 
  HFEt_start[4]=40; 
  HFEt_start[5]=48; 
  HFEt_start[6]=56; 
  HFEt_start[7]=64; 
  
  HFFg_start[0]=72; 
  HFFg_start[1]=73; 
  HFFg_start[2]=74; 
  HFFg_start[3]=75; 
  HFFg_start[4]=76; 
  HFFg_start[5]=77; 
  HFFg_start[6]=78; 
  HFFg_start[7]=79; 
  
  IEEt_start[0]=80; 
  IEEt_start[1]=90; 
  IEEt_start[2]=100; 
  IEEt_start[3]=110; 
  
  IEPos_start[0]=86; 
  IEPos_start[1]=96; 
  IEPos_start[2]=106; 
  IEPos_start[3]=116; 
  
  NEEt_start[0]=120; 
  NEEt_start[1]=130; 
  NEEt_start[2]=140; 
  NEEt_start[3]=150; 
  
  NEPos_start[0]=126; 
  NEPos_start[1]=136; 
  NEPos_start[2]=146; 
  NEPos_start[3]=156;
  
  RCHad_start[0][0]=160; 
  RCHad_start[0][1]=161; 
  RCHad_start[1][0]=162; 
  RCHad_start[1][1]=163; 
  RCHad_start[2][0]=164; 
  RCHad_start[2][1]=165; 
  RCHad_start[3][0]=166; 
  RCHad_start[3][1]=167; 
  RCHad_start[4][0]=168; 
  RCHad_start[4][1]=169; 
  RCHad_start[5][0]=170; 
  RCHad_start[5][1]=171; 
  RCHad_start[6][0]=172; 
  RCHad_start[6][1]=173; 

}

