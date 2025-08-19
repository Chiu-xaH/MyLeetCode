class Solution {
    private val MAX = Int.MAX_VALUE
    fun totalCost(costs: IntArray, k: Int, candidates: Int): Long {
        // val list = costs.toMutableList()
        // var count = 0
        // var result = 0L
        // while(count < k) {
        //     if(list.size < candidates) {
        //         // 雇佣他们中代价最小的一人 选择下标更小的一位工人
        //         var index = 0
        //         var i = 0
        //         var min = MAX
        //         while(i < list.size) {
        //             val value = list[i]
        //             if(value < min) {
        //                 min = value
        //                 index = i
        //             } else if(value == min) {
        //                 // 比较两者下标
        //                 if(i < index) {
        //                     index = i
        //                 }
        //             }
        //             i++
        //         }
        //         result += min.toLong()
        //         list.removeAt(index)
        //     } else {
        //         var left = candidates-1
        //         var right = list.size - candidates

        //         var min = MAX
        //         var index = left

        //         while(left >= 0) {
        //             val value = list[left]
        //             if(value < min) {
        //                 min = value
        //                 index = left
        //             }
        //             left--
        //         }

                
        //         while(right < list.size) {
        //             val value = list[right]
        //             if(value < min) {
        //                 min = value
        //                 index = right
        //             } else if(value == min) {
        //                 // 比较两者下标
        //                 if(right < index) {
        //                     index = right
        //                 }
        //             }
        //             right++
        //         }

        //         // 删除
        //         list.removeAt(index)
        //         result += min.toLong()
        //     } 
        //     count++
        // } 
        // return result

        val n = costs.size
        var leftIndex = 0
        var rightIndex = n - 1
        val leftHeap = PriorityQueue<Int>()
        val rightHeap = PriorityQueue<Int>()
        var result = 0L

        // 初始化左右堆
        repeat(candidates) {
            if(leftIndex <= rightIndex) leftHeap.add(costs[leftIndex++])
        }
        repeat(candidates) {
            if(leftIndex <= rightIndex) rightHeap.add(costs[rightIndex--])
        }

        repeat(k) {
            val leftMin = leftHeap.peek() ?: MAX
            val rightMin = rightHeap.peek() ?: MAX

            if(leftMin <= rightMin) {
                result += leftHeap.poll()?.toLong() ?: 0L
                if(leftIndex <= rightIndex) leftHeap.add(costs[leftIndex++])
            } else {
                result += rightHeap.poll()?.toLong() ?: 0L
                if(leftIndex <= rightIndex) rightHeap.add(costs[rightIndex--])
            }
        }

        return result
    }
}