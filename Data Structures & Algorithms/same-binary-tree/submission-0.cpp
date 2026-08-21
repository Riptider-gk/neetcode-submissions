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
private: 
    bool check(TreeNode* p, TreeNode* q){
        if(!p&&!q) return true;
        if(!p||!q) return false;
        if(p->val!=q->val) return false;
        return (check(p->right, q->right)&&check(p->left, q->left));
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return(check(p,q));
    }
};
