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
