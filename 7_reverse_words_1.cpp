#include <iostream>
#include <cstdlib>
using namespace std;
void Reverse(char* pBegin,char* pEnd){
  if(pBegin==NULL || pEnd==NULL){
    return;
  }
  while(pBegin<pEnd){
    char temp = *pBegin;
    *pBegin = *pEnd;
    *pEnd = temp;
    pBegin++;
    pEnd--;
  }
}
char* ReverseSentence(char* pData){
  if(pData==NULL){
    return NULL;
  }
  char *pBegin = pData;
  char *pEnd = pData;
  while(*pEnd != '\0'){
    pEnd++;
  }
  pEnd--;
  Reverse(pBegin,pEnd);
  pBegin = pEnd = pData;
  while(*pBegin !='\0'){
    if(*pBegin == ' '){
      pBegin++;
      pEnd++;
      continue;
    }else if(*pEnd==' '||*pEnd=='\0'){
      Reverse(pBegin,--pEnd);
      pBegin = ++pEnd;
    }else{
      pEnd++;
    }
  }
  return pData;
}
int main(){
  char data[]="I am a Student.";
  int len = sizeof(data)/sizeof(data[0]);
  ReverseSentence(data);
  for(int i=0;i<len;i++)
    cout<<data[i]<<"--->";
  cout<<endl;

  return 0;
}
