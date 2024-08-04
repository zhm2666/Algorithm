#include<iostream>
#include<queue>
#include<vector>

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

    void print(TreeNode* root){
        vector<int> results;
        queue<TreeNode*> queue;
        if (root != NULL) {
            // 将根节点添加进入队列中
            queue.push(root);
            // 循环判断队列是否为空
            while (!queue.empty()){
                // 取出第一个元素
                TreeNode* treeNode = queue.front();
                queue.pop();
                // 加入结果集
                results.push_back(treeNode->val);
                // 如果左子树不为空，则添加至队尾
                if (treeNode -> left != NULL){
                    queue.push(treeNode->left);
                }
                // 如果右子树不为空，则添加至队尾
                if (treeNode->right != NULL){
                    queue.push(treeNode->right);
                }
            }
        } 
        for (auto v : results){
            cout << v << " ";
        }
    }
};

int main(){
    Solution solution;
    TreeNode* node = solution.initTree();
    solution.print(node);
    return 0;
}
    