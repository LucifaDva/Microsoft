/*
题目：输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。

例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int Pair_sum(int* A,int key,int len){
  cout<<len<<"****"<<endl;
  int start = 0;
  int end = len-1;
  int n = 0;
  while(start<end){
    if(A[start]+A[end]<key){
      start++;
    }else if(A[start]+A[end]>key){
      end--;
    }else{
      n++;
      cout<<A[start]<<" + "<<A[end]<<" = "<<key<<endl;
      break;
    }
  }
  return n;
}
int main(){
  int A[] = {1,2,4,7,11,15};
  int key = 10;
  int len = sizeof(A)/sizeof(A[0]);
  int n = Pair_sum(A,key,len);
  if(n==0){
    cout<<"没有两个数的和为："<<key<<endl;
  }
  return 0;
}
