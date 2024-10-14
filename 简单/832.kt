class Solution {
    fun flipAndInvertImage(image: Array<IntArray>): Array<IntArray> {
        for(i in 0 until image.size) {
                //逆序
                image[i].reverse()
                for(j in 0 until image.size) {
                    //反转 01替换
                    val item = image[i][j]
                    if(item == 0) {
                        image[i][j] = 1
                    } else if(item == 1) {
                        image[i][j] = 0
                    }
                }
         }
         return image
    }
}