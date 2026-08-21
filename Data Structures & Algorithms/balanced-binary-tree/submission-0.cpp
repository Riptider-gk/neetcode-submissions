/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
bool ans;
private: 
    int dfs(TreeNode* node){
        if(!node) return 0;
        TreeNode* l=node->left;
        TreeNode* r=node->right;
        return 1+max(dfs(l), dfs(r));
    }
    bool bal(TreeNode* node){
        if(!node) return true;
        TreeNode* left=node->left;
        TreeNode* right=node->right;
        if(abs(dfs(right)-dfs(left))>1) return false;
        return (bal(right)&&bal(left));
    }
public:
    bool isBalanced(TreeNode* root) {
        return bal(root);
    }
};
