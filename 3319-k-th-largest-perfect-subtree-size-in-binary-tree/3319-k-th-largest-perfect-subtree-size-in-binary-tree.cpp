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
    pair<bool,int>dfs(TreeNode* root,vector<int>& size){
        if(root==NULL){
            return {true,0};
        }
        pair<bool,int>L=dfs(root->left,size);
        pair<bool,int>R=dfs(root->right,size);
        if((L.first==true) && (R.first==true) && (L.second==R.second)){
            int size_ps=L.second+R.second+1;
            size.push_back(size_ps);
            return {true,size_ps};
        }
        return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int>size;
        dfs(root,size);
        if(k>size.size()){
            return -1;
        }else{
            sort(size.rbegin(),size.rend());
            return size[k-1];
        }
    }
};