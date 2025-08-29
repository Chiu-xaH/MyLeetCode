class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        // -1,0,1,2,-1,-4
        nums.sort()
        // -4,-1,-1,0,1,2
        
        for (i in nums.indices) {
            // 跳过重复数
            if (i-1 >= 0 && nums[i-1] == nums[i]) {
                continue
            }
            
            var left = i + 1
            var right = nums.size - 1
            
            while (left < right) {
                val sum = nums[i] + nums[left] + nums[right]
                when {
                    sum == 0 -> {
                        result.add(listOf(nums[i], nums[left], nums[right]))
                        // 跳过重复数 右移到首个不同元素
                        while (left < right && nums[left] == nums[left + 1]) left++
                        // 跳过重复数 左移到首个不同元素
                        while (left < right && nums[right] == nums[right - 1]) right--
                        // 移动指针
                        left++
                        right--
                    }
                    sum < 0 -> left++
                    else -> right--
                }
            }
        }
        return result
    }
}