class Solution {
    fun detectCapitalUse(word: String): Boolean {
        if(word.first().isLowerCase()) {
         word.forEach { ch->
             if(ch.isUpperCase()) {
                 return false
             }
         }
         return true
        } else {
         var count = 0
         word.forEach { ch->
             if(ch.isUpperCase()) {
                 count++
             }
         }
         return count == 0 || count == word.count() || count == 1
     }
    }
}