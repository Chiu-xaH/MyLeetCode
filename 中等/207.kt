class Solution {
    fun canFinish(numCourses: Int, prerequisites: Array<IntArray>): Boolean {
        val graph = Array(numCourses) { mutableListOf<Int>() }  // 邻接表
        val indegree = IntArray(numCourses) { 0 }
        // 建图
        for(edge in prerequisites) {
            val from = edge[1]
            val to = edge[0]
            graph[from].add(to)
            indegree[to]++
        }
        // 队列
        val queue = ArrayDeque<Int>()
        for(i in 0 until numCourses) {
            if(indegree[i] == 0) {
                queue.add(i)
            }
        }
        //拓扑
        var count = 0
        while(queue.isNotEmpty()) {
            val i = queue.removeFirst()
            count++
            for(next in graph[i]) {
                indegree[next]--
                if(indegree[next] == 0) {
                    queue.add(next)
                }
            }
        }
        return count == numCourses
    }
}