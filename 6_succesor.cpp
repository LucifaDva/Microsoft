#include <iostream>
#include <cstdlib>
using namespace std;
bool verifySequenceOfBST(int* sequence,int length){
  if(sequence==NULL || length<=0){
    return false;
  }
  int root = sequence[length-1];
  int i=0;
  for(;i<length-1;++i){
    if(sequence[i]>root){
      break;
    }
  }
  int j=i;
  for(;j<length-1;++j){
    if(sequence[j]<root){
      return false;
    }
  }
  bool left = true;
  if(i>0){
    left = verifySequenceOfBST(sequence,i);
  }
  bool right = true;
  if(i<length-1){
    right = verifySequenceOfBST(sequence+i,length-i-1);
  }
  return (left&&right);
}
int main(){
  int sequence[] = {5,7,6,9,11,10,8};
  bool v = verifySequenceOfBST(sequence,7);
  if(v==true)
    cout<<"有效！"<<endl;
  else
    cout<<"无效！"<<endl;
  return 0;
}
