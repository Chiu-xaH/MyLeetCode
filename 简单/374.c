public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);

            if (res == 0) {
                return mid; // 猜对了
            } else if (res < 0) {
                right = mid - 1; // 猜大了
            } else {
                left = mid + 1; // 猜小了
            }
        }
        return -1;
    }
}
