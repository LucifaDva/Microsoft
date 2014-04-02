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
