class Solution {
    fun swap(nums : IntArray,ptrL : Int,ptrR : Int) {
        val temp = nums[ptrL]
        nums[ptrL] = nums[ptrR]
        nums[ptrR] = temp
    }
    fun nextPermutation(nums: IntArray) {
        var ptrL = -1
        for(i in nums.size-1 downTo 1) {
            if(nums[i] > nums[i-1]) {
                // 找到
                ptrL = i-1
                break
            } 
        }
        if(ptrL == -1) {
            // 直接反转
            var left = 0
            var right = nums.size-1
            while(left < right) {
                swap(nums,left,right)
                left++
                right--
            }
            return
        }
        var ptrR = -1
        for(i in nums.size-1 downTo ptrL+1) {
            if(nums[i] > nums[ptrL]) {
                // 找到
                ptrR = i
                break
            } 
        }
        // 交换
        swap(nums,ptrL,ptrR)
        // 反转i后面的元素
        var left = ptrL+1
        var right = nums.size-1
        while(left < right) {
            swap(nums,left,right)
            left++
            right--
        }
    }
}
// 从最后向前寻找非降序的a[i-1]
// 从最后寻找第一个a[i] < a[j]
// 交换a[i]a[j]
// 反转a[i+1~n]

/*
1 3 2
1 2 3
 */