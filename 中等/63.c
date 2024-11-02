
int uniquePathsWithObstacles(int** grid, int gridSize, int* gridColSize) {
    if(grid[0][0] == 1) return 0;

    int dp[gridSize][*gridColSize];
    dp[0][0] = 1;
    for(int i = 1;i < gridSize;i++) {
        //本题核心：无障碍dp为1 grid为0 注意区分
        dp[i][0] = grid[i][0] == 0 && dp[i-1][0] == 1;
    }
    for(int j = 1;j < *gridColSize;j++) {
        dp[0][j] = grid[0][j] == 0 && dp[0][j-1] == 1;
    }
    for(int i = 1;i < gridSize;i++) {
        for(int j = 1;j < *gridColSize;j++) {
            if(grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[gridSize-1][(*gridColSize)-1];
}