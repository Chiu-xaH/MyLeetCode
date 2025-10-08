fun mergeSort(arr: IntArray): IntArray {
    if(arr.size <= 1) {
        return arr
    }
    val mid = arr.size / 2
    val left = arr.sliceArray(0 until mid)
    val right = arr.sliceArray(mid until arr.size)
    
    val sortedLeft = mergeSort(left)
    val sortedRight = mergeSort(right)
    
    return merge(sortedLeft, sortedRight)
}

fun merge(left: IntArray, right: IntArray) : IntArray {
    var i = 0
    var j = 0
    var k = 0

    val merged = IntArray(left.size + right.size)
    
    while(i < left.size && j < right.size) {
        if(left[i] > right[j]) {
            // 插j
            merged[k++] = right[j++]
        } else {
            // 插i
            merged[k++] = left[i++]
        }
    }
    // 处理剩余
    while(i < left.size) {
        merged[k++] = left[i++]
    }
    while(j < right.size) {
        merged[k++] = right[j++]
    }
    
    return merged
}


fun main() {
    val arr = intArrayOf(5, 2, 4, 7, 1, 3, 2, 6)
    val sorted = mergeSort(arr)
    println("排序后结果：${sorted.joinToString(", ")}")
}