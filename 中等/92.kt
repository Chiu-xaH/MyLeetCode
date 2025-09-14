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
    // 力扣92 思路 将需要翻转的链表两边断开，然后用正常的翻转，完成后重新连上
    private fun reverse(head: ListNode?): ListNode? { 
        var prev: ListNode? = null 
        var cur = head 
        while (cur != null) { 
            val nextTemp = cur.next 
            cur.next = prev
            prev = cur 
            cur = nextTemp
        }
        return prev 
    }
    fun reverseBetween(head: ListNode?, left: Int, right: Int): ListNode? {
        // 只有一个结点需要翻转
        if(head == null || right == left) {
            return head
        }

        val dummy = ListNode(0)
        dummy.next = head
        var prev : ListNode? = dummy
        // 找到两个点
        repeat(left-1) { 
            prev = prev?.next
        }
        var start = prev?.next
        var end = start
        repeat(right-left) {
            end = end?.next
        }
        // 断开
        // prev.next = null
        val next = end?.next
        end?.next = null
        val h = reverse(start)
        //接上
        prev?.next = h
        start?.next = next
        // 返回
        return dummy.next
    }
}