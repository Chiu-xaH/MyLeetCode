class Solution {
    // 找到数组中比h大，但是相差最小的数
        // 从0~这个数进行二分递归
        // 如果时间>h 向右找
        // 否则 向左找
        // 同时比较并替换最小的k
        // 递归结束，返回k
    fun minEatingSpeed(piles: IntArray, h: Int): Int {
        var left = 1
        var right = piles.maxOrNull()!!
        var ans = right
        while (left <= right) {
            val mid = (left + right) / 2
            if (canEatAll(piles, h, mid)) {
                ans = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return ans
    }
    
    private fun canEatAll(piles: IntArray, h: Int, k: Int): Boolean {
        var hours = 0L
        piles.forEach { item ->
            if(k >= item) {
                // 一次吃完
                hours++
            } else {
                // 多次吃完
                val q = item/k
                if(item % k == 0) {
                    hours += q.toLong()
                } else {
                    hours += q.toLong()+1L
                }
            }
        }
        return hours <= h
    }
}