/*
题目：输入一个整数，求该整数的二进制表达中有多少个1。例如输入10，由于其二进制表示为1010，有两个1，因此输出2。
*/
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
