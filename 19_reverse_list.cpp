/*
题目：输入一个链表的头结点，反转该链表，并返回反转后链表的头结点。链表结点定义如下：

struct ListNode
{
      int       m_nKey;
      ListNode* m_pNext;
};
*/
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
