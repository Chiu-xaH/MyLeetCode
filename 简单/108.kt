class Solution {
    private fun binary(nums : IntArray,start : Int,end : Int) : TreeNode? {
        if(start > end) {
            return null
        }
        val mid = (start + end) / 2
        val node = TreeNode()
        node.`val` = nums[mid]
        node.left = binary(nums,start,mid-1)
        node.right = binary(nums,mid+1,end)
        return node
    }
    fun sortedArrayToBST(nums: IntArray): TreeNode? = binary(nums,0,nums.size-1)
}