# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: TreeNode | None) -> int:
        self.total=0
        self.maxP=0
        def get_total(node):
            if not node:
                return 0
            return node.val+get_total(node.left)+get_total(node.right)

        self.total=get_total(root)

        def get_subtree_sum(node):
            if not node:
                return 0
            sub_sum=node.val+get_subtree_sum(node.left)+get_subtree_sum(node.right)
            product=sub_sum*(self.total-sub_sum)
            if product>self.maxP:
                self.maxP=product

            return sub_sum
        get_subtree_sum(root)
        MOD=10**9+7
        return self.maxP%MOD