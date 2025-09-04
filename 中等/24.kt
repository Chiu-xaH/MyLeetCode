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
    fun swapPairs(head: ListNode?): ListNode? {
        if(head == null || head.next == null) {
            return head
        }
        // 增加头结点
        val dummy = ListNode(0)
        dummy.next = head
        // 头结点
        var prev = dummy
        while(prev.next != null && prev.next?.next != null) {
            val first = prev.next
            val second = first?.next
            // 互换
            first?.next = second?.next
            second?.next = first
            prev.next = second
            // 前进
            prev = first
        }
        return dummy.next     
    }
}