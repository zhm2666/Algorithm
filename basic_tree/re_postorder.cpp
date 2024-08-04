#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    void postorder(TreeNode* root){
        if (root != NULL){
            postorder(root->left);
            postorder(root->right);
            cout<< root->val << " ";
        }
    }
};

int main(){
    Solution solution;
    TreeNode* node = solution.initTree();
    solution.postorder(node);
    return 0;
}
