/*
题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
char FirstNotRepeatingChar(char* pString){
  if(!pString)
    return 0;
  const int tableSize = 256;
  unsigned int hashTable[tableSize];
  for(unsigned int i=0;i<tableSize;++i)
    hashTable[i] = 0;
  char* pHashKey = pString;
  while(*(pHashKey)!='\0')
    hashTable[*(pHashKey++)]++;
  pHashKey = pString;
  while(*pHashKey != '\0'){
    if(hashTable[*pHashKey]==1)
      return *pHashKey;
    pHashKey++;
  }
  return 0;
}
int main(){
  char s[]="abaccdeff";
  char l = FirstNotRepeatingChar(s);
  cout<<l<<"******"<<endl;
  return 0;
}
