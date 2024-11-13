class Solution {
    fun finalPositionOfSnake(n: Int, commands: List<String>): Int {
        var i = 0;
        var j = 0;
        for(index in 0 until commands.size) {
            if(commands[index] == "DOWN")  i++
            else if(commands[index] == "UP") i--
            else if(commands[index] == "RIGHT") j++
            else if(commands[index] == "LEFT") j--
        }
        return n*i + j;
    }
}