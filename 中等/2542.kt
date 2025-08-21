class Solution {
    private val heap = mutableListOf<Pair<Int,Int>>()
    fun maxScore(nums1: IntArray, nums2: IntArray, k: Int): Long {
        val pairs = nums1.indices
            .map { i -> nums2[i] to nums1[i] }
            .sortedByDescending { it.first }
        val heap = PriorityQueue<Int>() // 小顶堆，存 num1
        var sum = 0L
        var result = 0L
        for((num2,num1) in pairs) {
            heap.add(num1)
            sum += num1

            if(heap.size > k) {
                sum -= heap.poll() // 弹出最小
            }
            if(heap.size == k) {
                // num2已经是降序排列了,每次遍历取得都是最小值
                result = maxOf(result,sum * num2)
            }
        }
        return result
    }
}

// 思路 对两个数组进行哈希映射，然后按nums2排序，维护容量k的堆