#include <iostream>
#include <cstdlib>
using namespace std;
class TreeNode{
public:
  int value;
  TreeNode* left;
  TreeNode* right;
public:
  TreeNode(int newvalue):value(newvalue),left(NULL),right(NULL){}
};
void MirrorRecursively(TreeNode* pNode){
  if(!pNode->left && !pNode->right)
    return;
  cout<<"****"<<pNode->value<<endl;
  cout<<"left:"<<pNode->left->value<<endl;
  cout<<"right:"<<pNode->right->value<<endl;
  cout<<"****"<<endl;

  TreeNode* ptemp = pNode->left;
  pNode->left = pNode->right;
  pNode->right = ptemp;
  if(pNode->left)
    MirrorRecursively(pNode->left);
  if(pNode->right)
    MirrorRecursively(pNode->right);
}
int main(){
  TreeNode* n1 = new TreeNode(8);
  TreeNode* n2 = new TreeNode(6);
  TreeNode* n3 = new TreeNode(10);
  TreeNode* n4 = new TreeNode(5);
  TreeNode* n5 = new TreeNode(7);
  TreeNode* n6 = new TreeNode(9);
  TreeNode* n7 = new TreeNode(11);
  n3->left = n6;n3->right = n7;
  n2->left = n4;n2->right = n5;
  n1->left = n2;n1->right = n3;

  MirrorRecursively(n1);
  cout<<"n1->right: "<<n1->right->value<<endl;
  cout<<"n1->left: "<<n1->left->value<<endl;
  cout<<"n1->left->left:"<<n1->left->left->value<<endl;
  cout<<"n1->left->right:"<<n1->left->right->value<<endl;
  cout<<"n1->right->left:"<<n1->right->left->value<<endl;
  cout<<"n1->right->right:"<<n1->right->right->value<<endl;
  return 0;
}
