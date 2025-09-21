class Solution {
    fun check(need: Map<Char, Int>, window: Map<Char, Int>): Boolean {
        for ((ch, count) in need) {
            if (window.getOrDefault(ch, 0) < count) return false
        }
        return true
    }

    fun minWindow(s: String, t: String): String {
        var resStart = 0
        var resLen = Int.MAX_VALUE
        var start = 0
        var end = 0
        val mapT = mutableMapOf<Char,Int>()
        t.forEach { ch ->
            mapT[ch] = mapT.getOrDefault(ch,0) + 1
        }
        val mapS = mutableMapOf<Char,Int>()
        // 扩大end
        while(end < s.length) {
            val ch = s[end]
            if(mapT.containsKey(ch)) {
                // 纳入
                mapS[ch] = mapS.getOrDefault(ch,0) + 1
            }    
            end++
            
            while(start < end && check(mapT,mapS)) {
                // 达到要求
                // 收缩start
                val curLen = end - start
                if(curLen < resLen) {
                    resLen = curLen
                    resStart = start
                }
                val ch = s[start]
                if(mapT.containsKey(ch)) {
                    // 舍弃
                    mapS[ch] = mapS.getOrDefault(ch,0) - 1
                } 
                start++
            }
        }
        
        val result = 
            if (resLen == Int.MAX_VALUE) ""
            else s.substring(resStart, resStart + resLen)
        return result
    }
}