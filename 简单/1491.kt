class Solution {
    fun average(salary: IntArray): Double {
        val max = salary.max()
        val min = salary.min()
        val total = salary.sum() - max - min
        val avg : Double = total.toDouble() / (salary.size-2)
        return avg
    }
}