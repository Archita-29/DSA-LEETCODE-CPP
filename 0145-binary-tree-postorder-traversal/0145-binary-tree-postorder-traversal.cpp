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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        if(!root) return result;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        TreeNode* lastVisited=nullptr;
        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* peekNode=st.top();
                if(peekNode->right!=nullptr && lastVisited!=peekNode->right){
                    curr=peekNode->right;
                }else{
                    result.push_back(peekNode->val);
                    lastVisited=peekNode;
                    st.pop();
                }
            }
        }
        return result;
    }
};