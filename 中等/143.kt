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
    fun reverse(head: ListNode?): ListNode? {
        var prev: ListNode? = null
        var curr = head
        while (curr != null) {
            val next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        }
        return prev
    }
    fun reorderList(head: ListNode?) {
        if(head == null || head.next == null) {
            return
        }
        // 寻找中间结点
        var fast = head
        var slow : ListNode = head
        while (fast?.next != null && fast.next?.next != null) {
            // 移动两步
            fast = fast.next!!.next
            // 移动一步
            slow = slow.next!!
        }
        // slow后面断开
        val head2 = slow.next
        slow.next = null
        // 反转 head2
        val newHead2 = reverse(head2)
        // newHead2向head交替合并
        var ptr1 = head
        var ptr2 = newHead2
        while(ptr1 != null && ptr2 != null) {
            val next2 = ptr2.next
            val next1 = ptr1.next

            ptr1.next = ptr2
            ptr2.next = next1

            ptr1 = next1
            ptr2 = next2
        }
        // 断开的第二个链表总是少于前面链表 肯定能接完
    }
}