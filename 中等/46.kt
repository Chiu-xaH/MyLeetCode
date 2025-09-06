class Solution {
    private val result = mutableListOf<List<Int>>()
    fun permute(nums: IntArray): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        val used = BooleanArray(nums.size)
        // for(i in 0 until nums.size) {
        //     used[i] = false
        // }
        fun backtrack(path: MutableList<Int>) {
            if(path.size == nums.size) {
                result.add(path.toList())
                return
            }
            for(i in 0 until nums.size) {
                if(used[i]) {
                    continue
                }
                used[i] = true
                // 未用过
                path.add(nums[i])
                backtrack(path)
                // 回溯
                path.removeAt(path.size-1)
                used[i] = false
            }
        }
        backtrack(mutableListOf<Int>())
        return result
    }
}