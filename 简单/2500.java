class Solution {
    public Boolean isOne(int[] grid) {
        int count = 0;
        for(int i = 0;i < grid.length;i++) {
            if(grid[i] != -1) {
                count++;
            }
        }
        return count == 1;
    }
    public int deleteGreatestValue(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int sum = 0;
        while(!isOne(grid[0])) {
            int maxs = -1;
            for(int i = 0;i < m;i++) {
                int max = -1;
                for(int j = 0;j < n;j++) {
                    if(max == -1 || grid[i][j] > grid[i][max]) {
                        max = j;
                    }
                }
                if(max != -1) {
                    if(grid[i][max] > maxs) {
                        maxs = grid[i][max];
                    }
                    grid[i][max] = -1;
                }
            }
            if(maxs != -1) {
                sum += maxs;
            }
        }
        int maxs = -1;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] != -1) {
                    if(grid[i][j] > maxs) {
                        maxs = grid[i][j];
                    }
                }
            }
        }
        sum += maxs;
        return sum;
    }
}