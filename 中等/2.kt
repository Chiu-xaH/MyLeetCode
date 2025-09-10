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
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        // 进位
        var carry = 0
        var list1 = l1
        var list2 = l2
        val head = ListNode(0)
        var newList = head
        while(list1 != null && list2 != null) {
            val total = list1.`val` + list2.`val` + carry
            val result = total % 10
            carry = total / 10

            newList.next = ListNode(result)
            newList = newList.next
            list1 = list1.next
            list2 = list2.next
        }
        while(list1 != null) {
            val total = list1.`val` + carry
            val result = total % 10
            carry = total / 10

            newList.next = ListNode(result)
            newList = newList.next
            list1 = list1.next
        }
        while(list2 != null) {
            val total = list2.`val` + carry
            val result = total % 10
            carry = total / 10

            newList.next = ListNode(result)
            newList = newList.next
            list2 = list2.next
        }
        if (carry > 0) {
            newList.next = ListNode(carry)
        }
        return head.next
    } 
}
// 力扣2 思路 两个指针从头遍历，相加，如果>=10，则将其%10的结果作为结果，将其/10的结果加到下一位进位，直到其中一个指针走到头，将另一个没走到头的落下来