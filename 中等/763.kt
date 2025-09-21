class Solution {
    fun partitionLabels(s: String): List<Int> {
        val result = mutableListOf<IntArray>()
        // [0]存储左端点 [1]存储右端点
        val list = Array(26) { IntArray(2) { -1 } }
        for(i in 0 until s.length) {
            val index = s[i]-'a'
            list[index][1] = i
            if(list[index][0] == -1) {
                list[index][0]  = i
            }
        }

        // 按last排序
        list.sortBy { it[0] }
        var start = 0
        for(i in 0 until list.size) {
            val right = list[i][1]
            if(right != -1) {
                start = i
                break
            }
        }
        for(i in start until list.size) {
            val left = list[i][0]
            val right = list[i][1]
            // 结果为空 直接加入
            // 当前区间与上一个区间不重叠，直接加入
            if(result.isEmpty() || result.last()[1] < left) {
                result.add(intArrayOf(left,right))
            } else {
                result.last()[1] = maxOf(result.last()[1],right)
            }
        }
        return result.map { it[1] - it[0] + 1 }
    }
}
/*
abab|cc
last[a]=2
last[b]=3
last[c]=5

 */