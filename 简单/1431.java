class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int len = candies.length;
        Boolean[] result = new Boolean[len];
        int max = Arrays.stream(candies).max().getAsInt();
        for(int i = 0;i < len;i++) {
            int r = candies[i] + extraCandies;
            if(r >= max) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return Arrays.asList(result);
    }
}