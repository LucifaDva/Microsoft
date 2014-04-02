/*
题目：输入一个正数n，输出所有和为n连续正数序列。

例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void PrintContinueSequence(int small,int big);
void FindContinuousSequence(int n){
  if(n<3)
    return;
  int small = 1;
  int big = 2;
  int middle = (1+n)/2;
  int sum = small+big;
  while(small<middle){
    if(sum==n)
      PrintContinueSequence(small,big);
    while(sum>n){
      sum = sum-small;
      small++;
      if(sum==n)
        PrintContinueSequence(small,big);
    }
    big++;
    sum += big;
  }
}
void PrintContinueSequence(int small,int big){
  for(int i=small;i<=big;++i)
    cout<<i<<" + ";
  cout<<endl;
}
int main(){
  int n;
  while(true){
    cout<<"N:";
    cin>>n;
    FindContinuousSequence(n);
  }
  return 0;
}
