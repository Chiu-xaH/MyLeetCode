class Solution {
    fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        fun back(i : Int,cur : Int,list : MutableList<Int>) {
            if (cur == target) {
                result.add(list.toList())
                return
            }
            if(i >= candidates.size || cur > target) {
                return
            }
            // 加入当前
            list.add(candidates[i])
            back(i,cur+candidates[i],list)
            // 撤销
            list.removeAt(list.size-1)
            back(i+1,cur,list)
        }
        back(0,0,mutableListOf<Int>())
        return result
    }
}
// 力扣39 思路 