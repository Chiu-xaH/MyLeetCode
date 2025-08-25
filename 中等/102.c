
class Solution {
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        if (root == null) return result

        val queue: ArrayDeque<TreeNode> = ArrayDeque()
        // 根结点
        queue.add(root)

        while (queue.isNotEmpty()) {
            val levelSize = queue.size
            val list = mutableListOf<Int>()
            repeat(levelSize) {
                val node = queue.removeFirst()
                list.add(node.`val`)
                node?.left?.let { queue.add(it) }
                node?.right?.let { queue.add(it) }
            }
            result.add(list)   
        }

        return result 
    }
}