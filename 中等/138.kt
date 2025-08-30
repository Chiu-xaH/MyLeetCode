class Solution {
    private val map = mutableMapOf<Node,Node>()
    fun copyRandomList(node: Node?): Node? {
        if(node == null) {
            return null
        }
        if(!map.containsKey(node)) {
            val newNode = Node(node.`val`)
            map[node] = newNode
            newNode.next = copyRandomList(node.next)
            newNode.random = copyRandomList(node.random)
        }
        return map[node]
    }
}