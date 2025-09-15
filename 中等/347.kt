class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        val map = mutableMapOf<Int,Int>()// [数字]:频率
        val pirorQueue = PriorityQueue<Pair<Int,Int>>(compareByDescending { it.second })// 优先队列
        for(num in nums) {
            map[num] = (map[num]?:0) + 1
        }
        map.forEach {
            pirorQueue.add(Pair(it.key,it.value))
        }
        val result = mutableListOf<Int>()
        repeat(k) {
            result.add(pirorQueue.poll().first)
        }
        return result.toIntArray()
    }
}