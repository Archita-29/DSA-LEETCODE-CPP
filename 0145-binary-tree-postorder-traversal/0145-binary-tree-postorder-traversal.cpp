/**
Using only 1 stack
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
        if(root==NULL) return result;
        stack<TreeNode*>st;
        TreeNode* temp=NULL;
        while(root!=nullptr || !st.empty()){
            if(root!=nullptr){
                st.push(root);
                root=root->left;
            }else{
                temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    result.push_back(temp->val);

                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        result.push_back(temp->val);
                    }
                }else{
                    root=temp;
                }
            }
        }
        return result;
    }
};