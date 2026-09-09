# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        nums=[]
        def inorder(node):
            if node==None:
                return 
            inorder(node.left)
            nums.append(node.val)
            inorder(node.right)
        inorder(root)
        dummy=TreeNode(0)
        curr=dummy
        for val in nums:
            curr.right=TreeNode(val)
            curr=curr.right
        return dummy.right