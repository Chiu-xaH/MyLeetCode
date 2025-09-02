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
    fun sortList(head: ListNode?): ListNode? {
        if(head == null) {
            return null
        }

        val sortedValue = mutableListOf<Int>()
        var linkList = head
        while(linkList != null) {
            sortedValue.add(linkList.`val`)
            linkList = linkList.next
        }

        sortedValue.sort()
        
        val listHead = ListNode(0)
        var cur = listHead
        for (v in sortedValue) {
            cur.next = ListNode(v)
            cur = cur.next
        }
        return listHead.next
    }
}


/*
1 9 -1 5 3 4 0 2
1 9 -1 5 | 3 4 0 2
1 9 | -1 5 | 3 4 | 0 2


 */