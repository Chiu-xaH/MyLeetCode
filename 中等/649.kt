class Solution {
    private val queueR = mutableListOf<Int>()
    private val queueD = mutableListOf<Int>()

    private fun enqueue(queue : MutableList<Int>,element : Int) = queue.add(element)

    private fun dequeue(queue : MutableList<Int>) : Int? {
        if(queue.isEmpty()) {
            return null
        }
        return queue.removeAt(0)
    }

    private fun getQueueFirst(queue : MutableList<Int>) : Int? {
        if(queue.isEmpty()) {
            return null
        }
        return queue[0]
    }

    private fun getQueueLast(queue : MutableList<Int>) : Int? {
        if(queue.isEmpty()) {
            return null
        }
        return queue.last()
    }

    fun predictPartyVictory(senate: String): String {
        var count = 0
        senate.forEach { ch ->
            if(ch == 'R') {
                enqueue(queueR,count)
            } else if(ch == 'D') {
                enqueue(queueD,count)
            }
            count++
        }
        while(queueR.isNotEmpty() && queueD.isNotEmpty()) {
            val r = dequeue(queueR) ?: -1
            val d = dequeue(queueD) ?: -1
            if(r < d) {
                // R干掉D

                // R加入下一轮行动
                enqueue(queueR,r+count)
            } else if(r > d) {
                // D干掉R
                // D加入下一轮行动
                enqueue(queueD,d+count)
            }
        }
        if(queueR.isEmpty()) {
            return "Dire"
        } else if(queueD.isEmpty()){
            return "Radiant"
        } else {
            return "X"
        }
    }
}