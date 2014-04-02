#include <iostream>
#include <stack>
#include <cassert>
using namespace std;
class maxStack{
  stack<int> s;
  stack<int> smax;
public:
  void myPush(int key){
    if(!smax.empty()){
      if(key<smax.top()){
        smax.push(key);
      }
      s.push(key);
    }else{
      smax.push(key);
      s.push(key);
    }
  }
  int myPop(){
    assert(!s.empty());
    if(s.top()==smax.top()){
      smax.pop();
    }
    s.pop();
  }
  int myMax(){
    assert(!s.empty());
    return smax.top();
  }
  void printS(){
    cout<<"栈顶："<<s.top()<<endl;
    cout<<"最大值："<<smax.top()<<endl;
  }
};
int main(){
  maxStack ms;
  ms.myPush(5);
  ms.printS();
  ms.myPush(4);
  ms.printS();
  ms.myPush(1);
  ms.printS();
  ms.myPush(2);
  ms.printS();
  ms.myPush(3);
  ms.printS();
  ms.myPush(10);
  ms.printS();
  ms.myPush(9);
  ms.printS();
  ms.myPush(15);
  ms.printS();
  return 0;
}
