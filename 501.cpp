#include <iostream>
using namespace std;
class TreeNode{
public:
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int newvalue):value(newvalue),left(NULL),right(NULL){}
};
bool HasNode(TreeNode* root1,TreeNode* root2){
  if(root2==NULL)
    return true;
  if(root1==NULL)
    return false;
  if(root1->value!=root2->value)
    return false;
  return HasNode(root1->left,root2->left)&&HasNode(root1->right,root2->right);
}
bool HasSubTreeCore(TreeNode* root1,TreeNode* root2){
  bool result = false;
  if(root1->value==root2->value)
    result = HasNode(root1,root2);
  if(!result && root1->left!=NULL)
    result = HasNode(root1->left,root2);
  if(!result && root1->right!=NULL)
    result = HasNode(root1->right,root2);
  return result;
}
bool SubTree(TreeNode* root1,TreeNode* root2){
  if((root1==NULL&&root2!=NULL) || (root1!=NULL&&root2==NULL))
    return false;
  if(root1==NULL&&root2==NULL)
    return true;
  return HasSubTreeCore(root1,root2);

}

