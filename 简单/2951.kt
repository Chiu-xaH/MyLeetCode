class Solution {
    fun findPeaks(mountain: IntArray): List<Int> {
        val newList = mutableListOf<Int>()
        for(i in 1 until mountain.size-1) {
            val elem = mountain[i]
            if(elem > mountain[i+1] && elem > mountain[i-1]) {
                newList.add(i)
            }
        }
        return newList;
    }
}