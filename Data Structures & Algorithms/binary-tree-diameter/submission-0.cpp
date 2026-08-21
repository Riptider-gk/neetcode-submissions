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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int,int>> mp;
        mp[nullptr]={0,0};
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node=st.top();

            if(node->left && mp.find(node->left)==mp.end()) st.push(node->left);
            else if(node->right && mp.find(node->right)==mp.end()) 
                st.push(node->right);
            else {
                node=st.top();
                st.pop();

                auto[lh, ld]=mp[node->left];
                auto[rh, rd]=mp[node->right];

                int height=1+max(lh, rh);
                int diameter=max(lh+rh, max(ld,rd));

                mp[node]={height, diameter};
            }
        }
        return mp[root].second;
    }
};
