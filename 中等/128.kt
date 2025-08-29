class Solution {
    fun longestConsecutive(nums: IntArray): Int {
        val set = HashSet<Int>()  
        nums.forEach { num -> set.add(num) }
        var maxCount = 0
        for(item in set) {
            if(!set.contains(item-1)) {
                // 找到开头 开始计数
                var count = 1
                var i = item+1
                while(set.contains(i)) {
                    count++
                    i++
                }
                maxCount = maxOf(maxCount,count)
            }
        }
        return maxCount
    }
}

