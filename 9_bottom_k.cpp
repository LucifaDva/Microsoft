/*
题目：输入一个单向链表，输出该链表中倒数第k个结点。链表的倒数第0个结点为链表的尾指针。
*/
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
class ListNode{
  int key;
  ListNode* next;
public:
  ListNode():key(NULL),next(NULL){}
  ListNode(int key):key(key),next(NULL){}
  int Getkey(){ return key; }
  ListNode* Getnext(){ return next; }
  void Setkey(int newkey){ key=newkey; }
  void Setnext(ListNode* newnext){ next=newnext; }
};

class List{
  ListNode* head;
public:
  List():head(NULL){};
  void Insert(int new_data);
  ListNode*& Gethead(){return head;}
  void Print();
  int GetBottomk(int k);
};
int List::GetBottomk(int k){
  ListNode* cur1=head,*cur2=head;
  while(k-1){
    if(cur1->Getnext()!=NULL){
      cur1 = cur1->Getnext();
      k--;
      cout<<"k-1 = "<<k-1<<"   ** cur1:"<<cur1->Getkey()<<endl;
    }else{
      return -1;
    }
  }
  while(cur1->Getnext()!=NULL){
    cur1 = cur1->Getnext();
    cur2 = cur2->Getnext();
    cout<<"### "<<cur2->Getkey()<<endl;
  }
  return cur2->Getkey();
}
void List::Insert(int new_data){
  ListNode* add = new ListNode(new_data);
  if(head==NULL){
    head = add;
  }else{
    add->Setnext(head->Getnext());
    head->Setnext(add);
  }
}
void List::Print(){
  ListNode* cur = head;
  while(cur->Getnext()!=NULL){
    cout<<cur->Getkey()<<"-->";
    cur = cur->Getnext();
  }
  cout<<cur->Getkey();
  cout<<endl;
}
int main(){
  List* l = new List;
  l->Insert(5);
  l->Print();
  l->Insert(6);
  l->Print();
  l->Insert(3);
  l->Print();
  l->Insert(8);
  l->Print();
  l->Insert(2);
  l->Print();
  int bottomk = l->GetBottomk(8);
  if(bottomk==-1){
    cout<<"k超过链表长度"<<endl;
  }
  else
    cout<<bottomk<<endl;
}
