#include<iostream>
#include<stack>
#include<vector>

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

    void postorder(TreeNode* root){
        vector<int> res;
        if (root == NULL) return;
        stack<TreeNode*> stack;
        // 先加入根节点
        stack.push(root);
        // 循环判断栈是否为空
        while (!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            res.insert(res.begin(), node->val);
            // 先压入左边，再压入右边，出栈的时候，就会先右边再左边
            if (node -> left != NULL){
                stack.push(node->left);
            }
            if (node -> right != NULL){
                stack.push(node->right);
            }
        }
        for (auto lin : res){
            cout << lin << " ";
        }
    }
};

int main(){
    Solution solution;
    TreeNode* node = solution.initTree();
    solution.postorder(node);
    return 0;
}

