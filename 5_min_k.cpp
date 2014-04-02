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
int main(){
  int A[] = {7,8,1,4,2,3,5,6};
  quick_sort(A,0,4,4);
}
