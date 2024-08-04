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
    void preorder(TreeNode* root){
        stack<TreeNode*> stack;
        // 树为空直接返回
        if(root == NULL) return;
        // 将根节点压入栈中
        stack.push(root);
        while (!stack.empty()){
            // 取出栈顶元素
            TreeNode* node = stack.top();
            stack.pop();
            // 输出当前根节点
            cout << node->val << " ";
            // 先将右子树压入栈中
            if(node->right != NULL) stack.push(node->right); 
            // 再将左子树压入栈中
            if(node->left != NULL) stack.push(node->left);
        }
    }
};

int main(){
    Solution solution;
    TreeNode* node = solution.initTree();
    solution.preorder(node);
    return 0;
}

