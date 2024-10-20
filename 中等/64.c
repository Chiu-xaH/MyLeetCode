//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
int min(int a,int b) {
    return a < b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int dp[gridSize][*gridColSize];
    dp[0][0] = grid[0][0];

    for(int i = 1;i < gridSize;i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int i = 1;i < *gridColSize;i++) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for(int i = 1;i < gridSize;i++) {
        for(int j = 1;j < *gridColSize;j++) {
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[gridSize-1][(*gridColSize)-1];
}