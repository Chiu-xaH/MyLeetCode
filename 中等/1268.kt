class Solution {
    fun suggestedProducts(products: Array<String>, searchWord: String): List<List<String>> {
        products.sort()
        val result = mutableListOf<List<String>>()
        for(i in 1..searchWord.length) {
            val str = searchWord.substring(0,i)
            val list = mutableListOf<String>()
            var count = 0
            products.forEach { item ->
                if(count < 3 && item.startsWith(str)) {
                    list.add(item)
                    count++
                }
            }
            result.add(list)
        }
        return result
    }
}