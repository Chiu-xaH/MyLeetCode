class Solution {
    fun trainingPlan(head: ListNode?, cnt: Int): ListNode? {
        if(head == null) {
            return null
        }
        var left = head
        var ptr = 0
        var right = left
        while(ptr != cnt && right != null) {
            right = right.next
            ptr++
        }
        while(right != null && left != null) {
            left = left.next
            right = right.next
        }
        return left
    }
}