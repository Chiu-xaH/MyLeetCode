class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val totalSize = nums1.size+nums2.size
        return if(totalSize % 2 == 0) {
            // 需要找两个数 为第totalSize/2大和第totalSize/2+1大的数
            val k1 = totalSize / 2 
            val k2 = k1 + 1
            // 寻找
            (getKth(nums1, nums2, k1) + getKth(nums1, nums2, k2)) / 2.0
        } else {
            // 需要找一个数
            val k = totalSize / 2
            // 寻找
            getKth(nums1, nums2, totalSize / 2 + 1).toDouble()
        }
    }

    fun getKth(nums1: IntArray, nums2: IntArray, k: Int): Int {
        var index1 = 0
        var index2 = 0
        var kk = k

        while (true) {
            // 如果一个数组空了，就直接在另一个数组里取第 k 个
            if (index1 == nums1.size) return nums2[index2 + kk - 1]
            if (index2 == nums2.size) return nums1[index1 + kk - 1]
            // 第一个最小值
            if (kk == 1) return minOf(nums1[index1], nums2[index2])
            // 二分
            val half = kk / 2
            // 如果长度不够，就取末尾
            val newIndex1 = minOf(index1 + half, nums1.size) - 1
            val newIndex2 = minOf(index2 + half, nums2.size) - 1
            val pivot1 = nums1[newIndex1]
            val pivot2 = nums2[newIndex2]

            if (pivot1 <= pivot2) {
                // nums1 里前 half 个元素不可能是第 k 小
                kk -= (newIndex1 - index1 + 1)
                index1 = newIndex1 + 1
            } else {
                // nums2 里前 half 个元素不可能是第 k 小
                kk -= (newIndex2 - index2 + 1)
                index2 = newIndex2 + 1
            }
        }
    }
}