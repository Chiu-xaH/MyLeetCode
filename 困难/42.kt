class Solution {
    fun trap(height: IntArray): Int {
        val square1 = height.sum()
        var square2 = 0
        var curHeight = 1
        var left = 0
        var right = height.size-1
        val maxHeight = height.max()
        while(left <= right && curHeight <= maxHeight) {
            while(height[left] < curHeight && left <= right) {
                left++
            }
            while(height[right] < curHeight && left <= right) {
                right--
            }
            // 求面积 
            square2 += (right-left+1)
            curHeight++
        }
        return square2-square1
    }
}

class Solution {
    fun trap(height: IntArray): Int {
        var leftMax = 0
        var rightMax = 0
        var left = 0
        var right = height.size-1
        var water = 0
        while(left <= right) {
            if(height[left] < height[right]) {
                if(height[left] >= leftMax) {
                    leftMax = height[left]
                } else {
                    water += leftMax - height[left]
                }
                left++
            } else {
                if(height[right] >= rightMax) {
                    rightMax = height[right]
                } else {
                    water += rightMax - height[right]
                }
                right--
            }
        }
        return water
    }
}