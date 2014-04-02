/*
题目：输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。要求时间复杂度为O(n)。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void exchange(int& x,int& y){
  int tmp = x;
  x = y;
  y = tmp;
}
void Reorder(int* A,int len){
  int j = len-1;
  for(int i=0;i<j;i++){
    if(A[i]%2==0){
      while(A[j]%2==0){
        j--;
      }
      cout<<"Exchange: A[i]="<<A[i]<<" A[j]="<<A[j]<<endl;
      exchange(A[i],A[j]);
      j--;
    }
  }
}
int main(){
  int A[] = {1,2,38,56,324,33,56,4,5,6};
  int len = sizeof(A)/sizeof(A[0]);
  Reorder(A,len);
  for(int i=0;i<len;i++)
    cout<<A[i]<<"-->";
  cout<<endl;
  return 0;
}
