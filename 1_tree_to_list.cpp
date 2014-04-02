#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
struct BSTreeNode{
  int m_value;
  BSTreeNode* m_left;
  BSTreeNode* m_right;
};
BSTreeNode* ConvertNode(BSTreeNode* pNode,bool asRight){
  if(!pNode){
    return NULL;
  }
  BSTreeNode* pLeft = NULL;
  BSTreeNode* pRight = NULL;
  if(pNode->m_left){
    pLeft = ConvertNode(pNode->m_left,false);
  }
  if(pLeft){
    pLeft->m_right = pNode;
    pNode->m_left = pLeft;
  }
  if(pNode->m_right){
    pRight = ConvertNode(pNode->m_right,true);
  }
  if(pRight){
    pNode->m_right = pRight;
    pRight->m_left = pNode;
  }
  BSTreeNode* pTemp = pNode;
  if(asRight){
    while(pTemp->m_left){
      pTemp = pTemp->m_left;
    }
  }else{
    while(pTemp->m_right){
      pTemp = pTemp->m_right;
    }
  }
  return pTemp;
}
BSTreeNode* Convert(BSTreeNode* pHeadOfTree){
  return ConvertNode(pHeadOfTree,true);
}

