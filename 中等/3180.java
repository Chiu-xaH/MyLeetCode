class Solution {
    public int maxTotalReward(int[] rewardValues) {
    Arrays.sort(rewardValues);
    int n = rewardValues.length;
    //用来标记存在的数
    boolean[] dp = new boolean[rewardValues[n-1]*2];
    dp[0] = true;
    for (int value : rewardValues) {
        //遍历可以加的数，可加的全部加，方便后续操作
        for (int i = 0; i < value; i++) {
            if(dp[i]){
                //更新存在的数
                dp[i+value] = true;
            }
        }
    }
    for (int i = dp.length-1; i >=0 ; i--) {
        //dp数组中最后存在的数一定最大
        if(dp[i]){
            return i;
        }
    }
    return -1;
}
}