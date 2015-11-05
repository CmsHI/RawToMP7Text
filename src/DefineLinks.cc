#include "../interface/DefineLinks.h"

DefineLinks::DefineLinks() {

  for (int i=0;i<NwordsInLink;i++){
    for (int j=0;j<NLinks;j++){
      nMP7int[i][j]=0;
      noRSCint[i][j]=0;
    }
  }
}

void DefineLinks::ReadFileMP7(std::string fileinput) {

FILE *fp = fopen(fileinput.c_str(),"read");
if(!fp) std::cout<<"FILE NOT FOUND"<<std::endl;

int c=15;
int index;
char buffer [50];
char line[1000];
int counter=0;
  while(fgets(line,100000,fp)){
    if(line[0] != 'F') continue;
    for (int i=0;i<36;i++){
      index=c+i*11;
      if(line[index-1] != 'v') std::cout<<"Error while reading the payload, check the input file!"<<std::endl;;
      sprintf (buffer, "%c%c%c%c%c%c%c%c",line[index],line[index+1],line[index+2],line[index+3],line[index+4],line[index+5],line[index+6],line[index+7]);
      nMP7int[counter][i]=(int)strtol(buffer, NULL, 16);
    }
    counter++;
  }
}



void DefineLinks::ReadFileoRSC(std::string fileinput) {

  char nall[NLinks][10];

  FILE *fp=fopen(fileinput.c_str(),"read");
  if (fp == NULL) {
    printf("File not readable \n");
    exit(1);
  }

  counter=0;

  while(fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",nall[0],nall[1],nall[2],nall[3],nall[4],nall[5],nall[6],nall[7],nall[8],nall[9],nall[10],nall[11],nall[12],nall[13],nall[14],nall[15],nall[16],nall[17],nall[18],nall[19],nall[20],nall[21],nall[22],nall[23],nall[24],nall[25],nall[26],nall[27],nall[28],nall[29],nall[30],nall[31],nall[32],nall[33],nall[34],nall[35])!=EOF) {
    for (int index=0; index<NLinks; index++) noRSCint[counter][index]=(int)strtol(nall[index], NULL, 16);
    counter++;
  }

  for (int m=0;m<counter;m++){
    for (int n=0;n<NLinks;n++){
      nMP7int[m][maplinkfromoRSCtoMP7(n)]=noRSCint[m][n];
    }
  }
  fclose(fp);
}


void DefineLinks::WriteFileMP7Format(std::string fileoutput){

  int nFiles = 0;
  int outCounter = 0;
  bool active = true;
  while(outCounter < counter)
  {
    std::string tempFile = fileoutput + "_" + std::to_string(nFiles) + ".txt";
    std::ofstream outfile;
    outfile.open(tempFile.c_str(), std::ofstream::out);

    outfile << "Board MP7_TEST"<< std::endl;
    outfile << " Quad/Chan :    q00c0      q00c1      q00c2      q00c3      q01c0      q01c1      q01c2      q01c3      q02c0      q02c1      q02c2      q02c3      q03c0      q03c1      q03c2      q03c3      q04c0      q04c1      q04c2      q04c3      q05c0      q05c1      q05c2      q05c3      q06c0      q06c1      q06c2      q06c3      q07c0      q07c1      q07c2      q07c3      q08c0      q08c1      q08c2      q08c3"<< std::endl;
    outfile << "      Link :     00         01         02         03         04         05         06         07         08         09         10         11         12         13         14         15         16         17         18         19         20         21         22         23         24         25         26         27         28         29         30         31         32         33         34         35"<< std::endl;
    for (int i = 0; i < NwordsInLink; ++i) {
      if(i<10) outfile <<"Frame 000"<<i<<" : ";
      if(i>=10 && i<100) outfile <<"Frame 00"<<i<<" : ";
      if(i>=100 && i<1000) outfile <<"Frame 0"<<i<<" : ";
      if(i>=1000 && i<9999) outfile <<"Frame "<<i<<" : ";
      for (int j = 0; j < NLinks; ++j) {
	if(i<NwordsInLinkActive && active){
	  outfile <<"1v"<< std::hex << std::setfill('0') << std::setw(8)<< int(nMP7int[outCounter][j]) << std::dec;
	  outfile <<" ";
	}
	else{
	  outfile <<"0v"<< std::hex << std::setfill('0') << std::setw(8)<< 0 << std::dec;
	  outfile <<" ";
	}
      }
      outfile << std::endl;
      if(i<NwordsInLinkActive)
	outCounter++;
      if(outCounter >= counter) active = false;
    }
    outfile.close();
    nFiles++;
  }
}

int DefineLinks::maplinkfromoRSCtoMP7(int linkoRSCid){
  int indexfromoRSCtoMP7[NLinks]={0,1,8,9,16,17,24,25,32,33,28,29,20,21,12,13,4,5,2,3,10,11,18,19,26,27,34,35,30,31,22,23,14,15,6,7};
return indexfromoRSCtoMP7[linkoRSCid];
}

int DefineLinks::maplinkfromMP7tooRSC(int linkMP7id){
  int indexfromMP7tooRSC[NLinks]={0,1,18,19,16,17,34,35,2,3,20,21,14,15,32,33,4,5,22,23,12,13,30,31,6,7,24,25,10,11,28,29,8,9,26,27};
return indexfromMP7tooRSC[linkMP7id];
}
