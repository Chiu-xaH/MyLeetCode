class Solution {
    fun searchRange(nums: IntArray, target: Int): IntArray {
        var left = 0
        var right = nums.size-1
        while(left <= right) {
            val mid = (left + right) / 2
            if(nums[mid] > target) {
                right = mid - 1
            } else if(nums[mid] < target) {
                left = mid + 1
            } else {
                // 开始找左右边界
                var start = mid
                var end = mid
                while(start >= 0 && nums[start] == nums[mid]) {
                    start--
                }
                while(end < nums.size && nums[end] == nums[mid]) {
                    end++
                }
                return intArrayOf(start+1,end-1)
            }
        }
        return intArrayOf(-1,-1)
    }
}