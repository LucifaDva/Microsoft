/*
题目：定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。如把字符串abcdef左旋转2位得到字符串cdefab。请实现字符串左旋转的函数。要求时间对长度为n的字符串操作的复杂度为O(n)，辅助内存为O(1)。
*/
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

