class MedianFinder() {
    // 存较大的部分 peek为它的最小值 小根堆 
    private val priorityQueue1 = PriorityQueue<Int>()
    // 存较小的部分 peek为它的最大值 大根堆
    private val priorityQueue2 = PriorityQueue<Int>(compareByDescending { it })

    fun addNum(num: Int) {
        // 将要存的数是偶数 
        if(priorityQueue1.size != priorityQueue2.size) {
            priorityQueue1.add(num)
            priorityQueue2.add(priorityQueue1.poll())
        } else {
            // 将要存的数是奇数 
            priorityQueue2.add(num)
            priorityQueue1.add(priorityQueue2.poll())
        }
    }

    fun findMedian(): Double {
        // 取平均数
        return if(priorityQueue2.size == priorityQueue1.size) {
            (priorityQueue1.peek() + priorityQueue2.peek()) / 2.0
        } else {
            priorityQueue1.peek().toDouble()
        }
    }
}