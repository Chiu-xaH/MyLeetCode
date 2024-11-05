public class Solution {
    public string LosingPlayer(int x, int y) {
        return Math.Min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
}