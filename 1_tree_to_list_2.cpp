/*
题目：输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。要求不能创建任何新的结点，只调整指针的指向。

　　比如将二元查找树
                                            10
                                          /    \
                                        6       14
                                      /  \     /　 \
                                   　4     8  12 　  16
转换成双向链表

4=6=8=10=12=14=16。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void ConvertNode(BSTreeNode* pNode,BSTreeNode*& pLastNodeInList){
  if(pNode==NULL){
    return;
  }
  BSTreeNode* pCurrent = pNode;
  if(pCurrent->m_left != NULL){
    ConvertNode(pCurrent->m_left,pLastNodeInList);
  }
  pCurrent->m_left = pLastNodeInList;
  if(pLastNodeInList != NULL){
    pLastNodeInList->m_right = pCurrent;
  }
  pLastNodeInList = pCurrent;
}
