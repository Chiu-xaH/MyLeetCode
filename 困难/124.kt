/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    private var maxNum = Integer.MIN_VALUE
    fun maxPathSum(root: TreeNode?): Int {
        maxGain(root)
        return maxNum
    }
    private fun maxGain(node : TreeNode?) : Int {
        if(node == null) {
            return 0
        }
        val left = maxOf(maxGain(node.left),0)
        val right = maxOf(maxGain(node.right),0)

        val total = node.`val` + left + right
        maxNum = maxOf(maxNum,total)

        return node.`val` + maxOf(left,right)
    }
}