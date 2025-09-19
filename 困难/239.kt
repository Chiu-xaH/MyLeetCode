class Solution {
    fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {
        val result = mutableListOf<Int>()
        val deque = ArrayDeque<Int>()
        for (right in nums.indices) {
            // 保证队列单调递减
            while (deque.isNotEmpty() && nums[deque.last()] <= nums[right]) {
                deque.removeLast()
            }
            
            deque.addLast(right)

            val left = right - k + 1 

            // 比左边界小 滑出窗口
            if (deque.first() < left) {
                deque.removeFirst()
            }

            if (left >= 0) {
                result.add(nums[deque.first()])
            }
        }
        return result.toIntArray()
    }
}