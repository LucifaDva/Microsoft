/*
题目：定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。如把字符串abcdef左旋转2位得到字符串cdefab。请实现字符串左旋转的函数。要求时间对长度为n的字符串操作的复杂度为O(n)，辅助内存为O(1)。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void exchange(char& x,char& y){
  char tmp = x;
  x = y;
  y = tmp;
}
void reverse(char* A,int start,int end){
  int m = (start+end)/2;
  int sum = start+end;
  for(int i=start;i<=m;i++){
    exchange(A[i],A[sum-i]);
  }
}
void left_rotate(char* A,int k,int len){
  k = k%len;
  if(k>0){
    reverse(A,0,k-1);
    reverse(A,k,len-1);
  }
  reverse(A,0,len-1);
}
int main(){
  char s[]={'a','b','c','d','e','f'};
  int len = sizeof(s)/sizeof(s[0]);
  left_rotate(s,2,len);
  for(int i=0;i<len;i++)
    cout<<s[i]<<"****";
  cout<<endl;
  return 0;
}
