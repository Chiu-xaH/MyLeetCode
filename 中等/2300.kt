class Solution {
    fun successfulPairs(spells: IntArray, potions: IntArray, success: Long): IntArray {
        val result = mutableListOf<Int>()
        potions.sort()
        for(spell in spells) {
            var left = 0
            var right = potions.size-1
            while(left <= right) {
                val mid = (left+right)/2
                if(potions[mid].toLong()*spell.toLong() >= success) {
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            }
            result.add(potions.size - left)
        }
        return result.toIntArray()
    }
}