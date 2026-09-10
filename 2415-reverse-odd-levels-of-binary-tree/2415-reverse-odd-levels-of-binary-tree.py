# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,root1,root2,flag):
        if(root1==None or root2==None):
            return
        if(flag==True):
            root1.val,root2.val=root2.val,root1.val
        self.dfs(root1.left,root2.right,not flag)
        self.dfs(root1.right,root2.left,not flag)
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if(root!=None):
            self.dfs(root.left,root.right,True)
        return root