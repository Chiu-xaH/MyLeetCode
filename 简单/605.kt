class Solution {
    fun canPlaceFlowers(flowerbed: IntArray, n: Int): Boolean {
        if(n == 0) {
            return true;
        }
        if (flowerbed.size == 1) {
            return if (flowerbed[0] == 0 && n == 1) true else n == 0
        } else
         {
            // n至少为3个
            // 找第一个0
            // 否则则继续向右查找位置
            var count = 0
            var index = 0
            while(index < flowerbed.size) {
                val value = flowerbed[index]
                if(value == 0) {
                    val leftValue = if(index == 0) {
                        0
                    } else {
                        flowerbed[index-1]
                    }
                    val rightVaule = if(index == flowerbed.size-1) {
                        0
                    } else {
                        flowerbed[index+1]
                    }
                    // 左右都为0时，才可以种花，置为1
                    if(leftValue == 0 && rightVaule == 0) {
                        flowerbed[index] = 1
                        count++
                    }
                }
                index++
            }
            return n <= count
        }
    }
}