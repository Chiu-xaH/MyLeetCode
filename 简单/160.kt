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
    fun getIntersectionNode(headA:ListNode?, headB:ListNode?):ListNode? {
        var ptrA = headA
        var ptrB = headB
        var countA = 0
        var countB = 0
        while(ptrA != null) {
            countA++
            ptrA = ptrA.next
        }
        while(ptrB != null) {
            countB++
            ptrB = ptrB.next
        }

        ptrA = headA
        ptrB = headB
        
        var diff = kotlin.math.abs(countA - countB)
        if (countA > countB) {
            repeat(diff) { ptrA = ptrA?.next }
        } else {
            repeat(diff) { ptrB = ptrB?.next }
        }

        // 一起往前走，直到相遇
        while (ptrA != null && ptrB != null) {
            if (ptrA == ptrB) return ptrA
            ptrA = ptrA.next
            ptrB = ptrB.next
        }

        return null
    }
}