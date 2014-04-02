#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
template <class T>
class CQueue{
public:
  CQueue(){
   stack<T>* s1 = new stack<T>;
   stack<T>* s2 = new stack<T>;
  }
  ~CQueue(){}
  void appendTail(const T& node);
  void deleteHead();
private:
  stack<T> s1;
  stack<T> s2;
};
template <class T>
void CQueue<T>::appendTail(const T& node){
  s1.push(node);
  cout<<"PUSH:"<<node<<endl;
}
template <class T>
void CQueue<T>::deleteHead(){
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
  }
  cout<<"POP:"<<s2.top()<<endl;
  s2.pop();
}
int main(){
  CQueue<int> c;
  c.appendTail(1);
  c.appendTail(2);
  c.appendTail(3);
  c.deleteHead();

  return 0;
}
