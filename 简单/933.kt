class RecentCounter() {
    private val list = mutableListOf<Int>()
    private val RANGE = 3000
    
    fun ping(t: Int): Int {
        list.add(t)
        var i = 0
        list.forEach { item ->
            if(item in t-RANGE..t) {
                i++
            }
        }
        return i
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = RecentCounter()
 * var param_1 = obj.ping(t)
 */