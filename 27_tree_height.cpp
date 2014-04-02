#include <iostream>
#include <cstdlib>
using namespace std;
class TreeNode{
public:
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int newvalue):value(newvalue),left(NULL),right(NULL){}
};
int TreeDepth(TreeNode* root){
  if(!root)
    return 0;
  int nLeft = TreeDepth(root->left);
  int nRight = TreeDepth(root->right);
  return (nLeft>nRight)?(nLeft+1):(nRight+1);
}
int main(){
  TreeNode* n1 = new TreeNode(10);
  TreeNode* n2 = new TreeNode(6);
  TreeNode* n3 = new TreeNode(14);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(12);
  TreeNode* n6 = new TreeNode(16);
  n3->left = n5;n3->right = n6;
  n2->left = n4;
  n1->left = n2;n1->right = n3;
  int h = TreeDepth(n1);
  cout<<"Height:"<<h<<endl;
  return 0;
}

