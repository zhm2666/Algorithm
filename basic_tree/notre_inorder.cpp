#include<iostream>
#include<stack>

using namespace std;
struct TreeNode{
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

    void inorder(TreeNode* root){
        stack<TreeNode*> stack;
        while (root != NULL || !stack.empty()){
            while (root != NULL){
                // 将当前节点压栈
                stack.push(root);
                // 遍历其左子树
                root = root->left;
            }
            // 出栈
            root = stack.top();
            stack.pop();
            // 当前节点被遍历
            cout << root->val << " ";
            // 右节点
            root = root->right;
        }
    }
};

int main(){
    Solution solution;
    TreeNode* node = solution.initTree();
    solution.inorder(node);
    return 0;
}
