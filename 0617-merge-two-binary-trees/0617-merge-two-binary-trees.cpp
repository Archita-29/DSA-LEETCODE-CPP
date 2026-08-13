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
//  USING STACK
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL){
            return root2;
        }
        if(root2==NULL){
            return root1;
        }
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({root1,root2});
        while(!st.empty()){
            pair<TreeNode*,TreeNode*>p=st.top();
            st.pop();
            TreeNode* t1=p.first;
            TreeNode* t2=p.second;
            if(t1==NULL || t2==NULL){
                continue;
            }
            t1->val=t1->val+t2->val;
            if(t1->left==NULL){
                t1->left=t2->left;
            }
            else{
                st.push({t1->left,t2->left});
            }
            if(t1->right==NULL){
                t1->right=t2->right;
            }
            else{
                st.push({t1->right,t2->right});
            }
        }
        return root1;
    }
};