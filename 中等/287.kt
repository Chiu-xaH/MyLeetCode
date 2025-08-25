class Solution {
    fun findDuplicate(nums: IntArray): Int {
        nums.sort()
        var i = 0
        while(i+1 < nums.size) {
            if(nums[i] == nums[i+1]) {
                return nums[i]
            } else {
                i++
            }
        }
        return -1
    }
}