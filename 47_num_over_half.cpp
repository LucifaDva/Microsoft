/*
题目：数组中有一个数字出现的次数超过了数组长度的一半，找出这个数字。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
bool valid = false;
int Over_Half(int* numbers,int len){
  if(numbers==NULL&&len==0){
    valid = true;
    return 0;
  }
  valid = false;
  int result = numbers[0];
  int times = 1;
  for(int i=1;i<len;++i){
    if(times==0){
      result = numbers[i];
      times=1;
    }else if(numbers[i]==result){
      times++;
    }else{
      times--;
    }
    times = 0;
    for(int i=0;i<len;++i){
      if(numbers[i]==result){
        times++;
      }
    }
    if(times*2<=len){
      valid = true;
      result = 0;
    }
    
  }
  return result;
}
int main(){
  int A[]={5,1,34,5,56,90,5,5,5,5};
  int len = sizeof(A)/sizeof(A[0]);
  int x = Over_Half(A,len);
  cout<<x<<endl;

  return 0;
}
