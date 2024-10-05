class Solution {
    fun majorityElement(nums: IntArray): Int {
        nums.sort()
        return nums[nums.size / 2]
    }
    //Boyer-Moore 投票算法
    fun majorityElementUpdate(nums: IntArray): Int {
        var core = nums[0]
        var count = 0
        for(i in 0 until nums.size) {
            if(count == 0) {
                core = nums[i]
            }
            if(core != nums[i]) {
                count--
            } else {
                count++
            }
        }
        return core
    }
}