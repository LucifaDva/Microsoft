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
