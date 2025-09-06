class Solution {
    fun subsets(nums: IntArray): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        fun backtrack(i : Int,arr : List<Int>) {
            // 到结尾了
            if (i == nums.size) {
                result.add(arr)
                return
            }
            // 不选
            backtrack(i + 1, arr)
            // 选
            backtrack(i + 1, arr + nums[i])
        }
        backtrack(0,emptyList())
        return result
    }
}