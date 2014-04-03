/*
题目：二叉树的结点定义如下：

struct TreeNode
{
        int m_nValue;
        TreeNode* m_pLeft;
        TreeNode* m_pRight;
};
输入两棵二叉树A和B，判断树B是不是A的子结构。

例如，下图中的两棵树A和B，由于A中有一部分子树的结构和B是一样的，因此B就是A的子结构。


                 1                                                   8
               /    \                                               /    \
              8    7                                             9    2
            /    \
           9    2
                /  \
               4  7
*/

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
bool DoesTree1HaveNodesOfTree2(TreeNode* root1,TreeNode* root2){
  if(root2==NULL)
    return true;
  if(root1==NULL)
    return false;
  if(root1->value!=root2->value)
    return false;
  return DoesTree1HaveNodesOfTree2(root1->left,root2->left)&&DoesTree1HaveNodesOfTree2(root1->right,root2->right);
}
bool HasSubtreeCore(TreeNode* root1,TreeNode* root2){
  bool result = false;
  if(root1->value==root2->value){
    result = DoesTree1HaveNodesOfTree2(root1,root2);
  }
  if(!result&&root1->left!=NULL)
    result = HasSubtreeCore(root1->left,root2);
  if(!result&&root1->right!=NULL)
    result = HasSubtreeCore(root1->right,root2);

  return result;
}
bool HasSubtree(TreeNode* root1,TreeNode* root2){
  if( (root1==NULL&&root2!=NULL) || (root1!=NULL&&root2==NULL) ){
    return false;
  }
  if(root1==NULL&&root2==NULL)
    return true;
  return HasSubtreeCore(root1,root2);
}
int main(){
  TreeNode* a1 = new TreeNode(1);
  TreeNode* a2 = new TreeNode(8);
  TreeNode* a3 = new TreeNode(7);
  TreeNode* a4 = new TreeNode(9);
  TreeNode* a5 = new TreeNode(2);
  TreeNode* a6 = new TreeNode(4);
  TreeNode* a7 = new TreeNode(7);
  a5->left = a6;a5->right = a7;
  a2->left = a4;a2->right = a5;
  a1->left = a2;a1->right = a3;
  TreeNode* b1 = new TreeNode(8);
  TreeNode* b2 = new TreeNode(9);
  TreeNode* b3 = new TreeNode(2);
  b1->left = b2;b1->right = b3;
  bool m = HasSubtree(a1,b1);
  cout<<"******"<<endl;
  if(m==true)
    cout<<"OK!"<<endl;
  else
    cout<<"不是！"<<endl;
  cout<<"******"<<endl;
}
