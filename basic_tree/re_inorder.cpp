#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* initTree(){
        TreeNode* treeNode = new TreeNode(1);
        treeNode->left = new TreeNode(2);
        treeNode->right = new TreeNode(3);
        treeNode->left->left = new TreeNode(4);
        treeNode->left->right = new TreeNode(5);
        treeNode->right->left = new TreeNode(6);
        return treeNode;
    }

    void inorder(TreeNode* root){
        if (root != NULL){
            // 访问左子树
            inorder(root->left);
            // 打印根节点
            cout<< root->val << " ";
            // 访问右子树
            inorder(root->right); 
        }
    }
};

int main(){
    Solution solution;
    TreeNode* node = solution.initTree();
    solution.inorder(node);
    return 0;
}




