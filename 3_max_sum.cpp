/*
题目：输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。求所有子数组的和的最大值。要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，因此输出为该子数组的和18。
*/
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
int MaxSum(int* A){
  int len = sizeof(A);
  int sum = A[0];
  int b = A[0];
  for(int i=0;i<len;i++){
    if(b<0){
      b = A[i];
    }else{
      b = b+A[i];
    }if(sum<b){
      sum = b;
    }
  }
  return sum;
}
int main(){
  int A[]={1,-2,3,10,-4,7,2,-5};
  cout<<MaxSum(A)<<endl;
}
