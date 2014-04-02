#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void Reverse(char* pStart,char* pEnd){
  if(pStart!=NULL && pEnd!=NULL){
    while(pStart<=pEnd){
      char tmp = *pStart;
      *pStart = *pEnd;
      *pEnd = tmp;
      pStart++;
      pEnd--;
    }
  }
}
char* LeftRotate(char* pStr,unsigned int n){
  if(pStr!=NULL){
    int len = static_cast<int>(strlen(pStr));
    if(len>0 && n>0 && n<len){
      char* pFirstStart = pStr;
      char* pFirstEnd = pStr+n-1;
      char* pSecondStart = pStr+n;
      char* pSecondEnd = pStr+len-1;
      Reverse(pFirstStart,pFirstEnd);
      Reverse(pSecondStart,pSecondEnd);
      Reverse(pFirstStart,pSecondEnd);
    }
  }
  return pStr;
}

