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
