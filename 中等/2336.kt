class SmallestInfiniteSet() {
    private val map = mutableListOf<Int>()

    fun popSmallest(): Int {
        var i = 1
        while(map.contains(i)) {
            i++
        }
        map.add(i)
        return i
    }

    fun addBack(num: Int) {
        if(map.contains(num)) {
            map.remove(num)
        }
    }

}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */