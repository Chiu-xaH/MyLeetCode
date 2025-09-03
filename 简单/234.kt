/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun isPalindrome(head: ListNode?): Boolean {
        if(head == null) {
            return true
        }
        val list = mutableListOf<Int>()
        var linkList = head
        while(linkList != null) {
            list.add(linkList.`val`)
            linkList = linkList.next
        }

        var left = 0
        var right = list.size-1
        while(left < right) {
            if(list[left] == list[right]) {
                left++
                right--
            } else {
                return false
            }
        }
        return true
    }
}