class Solution {
    fun combinationSum3(digitCount: Int, sum: Int): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        
        fun back(current : MutableList<Int>,start : Int,total : Int) {
            if(current.size == digitCount) {
                if(total == sum) {
                    // 值满足
                    result.add(current.toList())
                }
                return
            } else {
                // 数量不足
                for(i in start..9) {
                    if(total + i > sum) break

                    current.add(i)
                    back(current,i+1,total+i)
                    // 回溯
                    current.removeLast()
                }
            }
        }

        back(mutableListOf<Int>(),1,0)

        return result
    }
}