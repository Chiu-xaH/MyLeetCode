class Solution {
    fun maxProduct(nums: IntArray): Int {
        var max = nums[0]
        var min = nums[0]
        var result = nums[0]
        for(i in 1 until nums.size) {
            var curMax = max
            var curMin = min

            // 如果当前数字是负数，先交换 curMax 和 curMin
            if (nums[i] < 0) {
                curMax = min
                curMin = max
            }

            max = maxOf(nums[i],curMax * nums[i])
            min = minOf(nums[i],curMin * nums[i])
            result = maxOf(max,result)
        }
        return result
    }
}