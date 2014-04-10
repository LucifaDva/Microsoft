/*
题目：输入n个整数，输出其中最小的k个。

例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void exchange(int&,int&);
void Max_heapify(int* A,int i,int heap_len){
  int l = 2*i+1;
  int r = 2*(i)+2;
  int largest;
  if(l<heap_len && A[l]>A[i]) {
    largest = l;
  }else{
    largest = i;
  }
  if(r<heap_len && A[r] > A[largest]){
    largest = r;
  }
  if(largest != i){
    exchange(A[i],A[largest]);
    Max_heapify(A,largest,heap_len);
  }
}
void build_max_heap(int* A,int heap_len){
  for(int i=(heap_len)/2+1;i>=0;i--){
    Max_heapify(A,i,heap_len);
  }
}
void exchange(int& a,int& b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
void heap_sort(int* A,int heap_len){
  build_max_heap(A,heap_len);
  for(int i=heap_len-1;i>=0;i--){
    cout<<A[0]<<endl;
    exchange(A[0],A[i]);
    heap_len--;
    Max_heapify(A,0,heap_len);
  }
}
int main(){
  int A[]={4,1,3,2,16,9,10,14,8,7};
  int len = sizeof(A)/sizeof(A[0]);
  int k = 4;
  //如果K大于数组长度，直接输出原数组即可
  if(k>=len){
    for(int i=0;i<len;i++)
      cout<<A[i]<<"-->";
    cout<<endl;
    return 0;
  }
  build_max_heap(A,k);
  for(int j=k;j<len;j++){
    if(A[j]<A[0]){
      exchange(A[j],A[0]);
      Max_heapify(A,0,k);
    }
  }
  for(int i=0;i<k;i++)
    cout<<A[i]<<"-->";
  cout<<endl;
  return 0;
}

