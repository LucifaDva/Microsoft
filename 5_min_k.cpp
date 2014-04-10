/*
题目：输入n个整数，输出其中最小的k个。

例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void exchange(int& x,int& y){
  int tmp = x;
  x = y;
  y = tmp;
}
int Partition(int* A,int p,int r){
  int key = A[r];
  int i = p-1;
  for(int j=p;j<r;j++){
    if(A[j]<=key){
      i++;
      exchange(A[i],A[j]);
    }
  }
  exchange(A[i+1],A[r]);
  return (i+1);
}
void quick_sort(int* A,int p,int r,int k){
  if(p<r){
    int q = Partition(A,p,r);
    if(q==k){
      for(int i=0;i<=q;i++){
        cout<<"Case1:"<<"q="<<q<<" , k= "<<k<<endl;
        cout<<"数组变为：";
        for(int i=0;i<sizeof(A);i++)
          cout<<A[i]<<"   ";
        cout<<endl;
        cout<<A[i]<<"-->";
      }
    }else if(q<k){
      cout<<"Case2:"<<"q="<<q<<" , k= "<<k<<endl;
        cout<<"数组变为：";
        for(int i=0;i<sizeof(A);i++)
          cout<<A[i]<<"   ";
        cout<<endl;

      for(int i=p;i<=q;i++){
        cout<<A[i]<<"-->";
      }
      quick_sort(A,q+1,r,k-q);
    }else{
      cout<<"Case3:"<<"q="<<q<<" , k= "<<k<<endl;
        cout<<"数组变为：";
        for(int i=0;i<sizeof(A);i++)
          cout<<A[i]<<"   ";
        cout<<endl;

      quick_sort(A,p,q-1,k);
    }

  }
}
void min_k(int* A,int start,int end,int k){
  if(end-start+1<=k){
    cout<<"最小K个数即为原来A[]全部元素"<<endl;
    return;
  }else{
    quick_sort(A,start,end,k);
  }
}
int main(){
  int A[] = {7,8,1,4,2,3,5,6};
  int len = sizeof(A)/sizeof(A[0]);
  min_k(A,0,len-1,9);
  return 0;
}
