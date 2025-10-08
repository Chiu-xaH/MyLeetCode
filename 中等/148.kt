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
    private fun merge(left: ListNode?, right: ListNode?) : ListNode? {
        val dummy = ListNode(0)
        var tail = dummy
        var i = left
        var j = right

        while (i != null && j != null) {
            if (i.`val` <= j.`val`) {
                // 插i
                tail.next = i
                i = i.next
            } else {
                // 插j
                tail.next = j
                j = j.next
            }
            tail = tail.next!!
        }
        // 尾接剩余
        tail.next = i ?: j
        return dummy.next
    }

    fun sortList(head: ListNode?): ListNode? {
        if (head?.next == null) {
            return head
        }
        // 找中点
        var slow: ListNode? = head
        var fast: ListNode? = head.next
        while (fast?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
        }
        // 断开
        val mid = slow?.next
        slow?.next = null

        val sortedLeft = sortList(head)
        val sortedRight = sortList(mid)
        
        return merge(sortedLeft, sortedRight)
    }
}