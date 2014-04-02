#include <iostream>
#include <cstdlib>
using namespace std;
class ListNode{
public:
  int key;
  ListNode* next;
  ListNode(int newkey):key(newkey),next(NULL){}
};
ListNode* Reverse(ListNode* phead){
  ListNode* pReversedHead = NULL;
  ListNode* pNode = phead;
  ListNode* pPrev = NULL;
  while(pNode != NULL){
    ListNode* pNext = pNode->next;
    if(pNext==NULL)
      pReversedHead = pNode;
    pNode->next = pPrev;
    pPrev = pNode;
    pNode = pNext;
  }
  return pReversedHead;
}  
