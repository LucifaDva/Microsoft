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

