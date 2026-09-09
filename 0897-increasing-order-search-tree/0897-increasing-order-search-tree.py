# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    dummy=TreeNode(0)
    head=dummy
    def increasingBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def inorder(node):
            if node==None:
                return
            inorder(node.left)
            node.left=None
            self.dummy.right=node
            self.dummy=self.dummy.right
            inorder(node.right)
        inorder(root)
        return self.head.right