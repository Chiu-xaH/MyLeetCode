class Solution {
    fun largestAltitude(gain: IntArray): Int {
        var length = 0
        var maxLength = length
        gain.forEach { item ->
            length += item
            if(length > maxLength) {
                maxLength = length
            }
        }
        return maxLength
    }
}