class Solution {
    fun gcdOfStrings(str1: String, str2: String): String {
        if(str1 == str2) {
            return str1
        }   
        if(str1.length > str2.length) {
            if(str1.startsWith(str2)) {
                return gcdOfStrings(str2,str1.substringAfter(str2))
            } else {
                return ""
            }
        } else if(str1.length < str2.length) {
            if(str2.startsWith(str1)) {
                return gcdOfStrings(str1,str2.substringAfter(str1))
            } else {
                return ""
            }
        } else {
            return ""
        }
    }
}