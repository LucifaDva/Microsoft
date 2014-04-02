#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
  int n;
  cout<<"N:";
  cin>>n;
  int sum = 0;
  unsigned int flag = 1;
  while(flag){
    if(n&flag){
      sum++;
    }
    flag = flag<<1;
  }
  cout<<"共有 "<<sum<<" 个1！"<<endl;
  return 0;
}
