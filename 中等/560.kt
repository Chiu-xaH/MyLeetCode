class Solution {
    fun subarraySum(nums: IntArray, k: Int): Int {
        var sum = 0
        var count = 0
        val map = mutableMapOf<Int,Int>()
        map[0] = 1
        for(i in nums.indices) {
            sum += nums[i]
            count += map[sum - k] ?: 0 
            map[sum] = (map[sum] ?: 0) + 1
        }
        return count
    }
}

/*
1 2 1 2

1 3 4 6
map{
    1 to 1
    
}
 */