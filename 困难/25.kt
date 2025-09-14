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

    fun reverseKGroup(head: ListNode?, k: Int): ListNode? {
        if (head == null || k == 1) {
            return head
        }

        val dummy = ListNode(0)
        dummy.next = head
        var prev : ListNode? = dummy
        var end : ListNode? = dummy
        while(true) {
            // 找到尾
            repeat(k) {
                end = end?.next
            }
            if(end == null) {
                // 数量不够 无需翻转了
                break
            }
            // 进行翻转
            val start = prev?.next
            val next = end?.next
            // 断开下一段
            end?.next = null
            // 翻转前面
            prev?.next = reverse(start)
            // 接上翻转后的前链表
            start?.next = next
            prev = start
            end = prev
        }
        return dummy.next
    }
}