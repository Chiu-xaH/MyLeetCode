class Solution {
    fun compareVersion(version1: String, version2: String): Int {
        val list1 = version1.split(".")
        val list2 = version2.split(".")
        var ptr = 0
        while(ptr < list1.size && ptr < list2.size) {
            val code1 = list1[ptr].toInt()
            val code2 = list2[ptr].toInt()
            if(code1 > code2) {
                return 1
            } else if(code1 < code2) {
                return -1
            } else {
                ptr++
            }
        }  
        while(ptr < list1.size) {
            val code1 = list1[ptr].toInt()
            val code2 = 0
            if(code1 > code2) {
                return 1
            } else if(code1 < code2) {
                return -1
            } else {
                ptr++
            }
        } 
        while(ptr < list2.size) {
            val code2 = list2[ptr].toInt()
            val code1 = 0
            if(code1 > code2) {
                return 1
            } else if(code1 < code2) {
                return -1
            } else {
                ptr++
            }
        } 
        return 0
    }
}