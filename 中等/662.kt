 // 右结点下标=父结点下标*2+1
 // 左结点下标=父结点下标*2
 // 最左侧始终为0
class Solution {
    fun widthOfBinaryTree(root: TreeNode?): Int {
        if (root == null) return 0

        val queue: ArrayDeque<Pair<TreeNode, Long>> = ArrayDeque()
        queue.add(Pair(root, 0L)) 
        var maxWidth = 0
        while (queue.isNotEmpty()) {
            val levelSize = queue.size
            val firstIndex = queue.first().second 
            var lastIndex = firstIndex
            repeat(levelSize) {
                val (node, index) = queue.removeFirst()
                val normalizedIndex = index - firstIndex // 相对下标，避免溢出
                // 更新为最右侧结点的下标
                lastIndex = index
                node.left?.let { queue.add(Pair(it, normalizedIndex * 2)) }
                node.right?.let { queue.add(Pair(it, normalizedIndex * 2 + 1)) }
            }
            maxWidth = maxOf(maxWidth, (lastIndex - firstIndex + 1).toInt())
        }
        return maxWidth
    }
}