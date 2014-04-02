#include <iostream>
#include <cstdlib>
#include <deque>
using namespace std;
class TreeNode{
public:
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int newvalue):value(newvalue),left(NULL),right(NULL){}
};
deque<TreeNode*> q;
void floor_tree(TreeNode* root){
  if(!root->left && !root->right)
    return;
  q.push_back(root);
  while(q.size()){
    TreeNode* pNode = q.front();
    q.pop_front();
    cout<<pNode->value<<"****";
    if(pNode->left)
      q.push_back(pNode->left);
    if(pNode->right)
      q.push_back(pNode->right);
  }

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
  floor_tree(n1);
  return 0;
}
