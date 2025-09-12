
int dfs(int** grid, int gridSize, int gridColSize,int i,int j) {
    grid[i][j] = 0;
    int count = 1;
    if(i-1 >= 0 && grid[i-1][j] == 1) {
        count += dfs(grid,gridSize,gridColSize,i-1,j);
    }
    if(j-1 >= 0 && grid[i][j-1] == 1) {
        count += dfs(grid,gridSize,gridColSize,i,j-1);
    }
    if(i+1 < gridSize && grid[i+1][j] == 1) {
        count += dfs(grid,gridSize,gridColSize,i+1,j);
    }
    if(j+1 < gridColSize && grid[i][j+1] == 1) {
        count += dfs(grid,gridSize,gridColSize,i,j+1);
    }
    return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int a = gridColSize[0];
    int maxCount = 0;
    for(int i = 0;i < gridSize;i++) {
        for(int j = 0;j < a;j++) {
            int node = grid[i][j];
            if(node == 1) {
                // 开始DFS
                int count = dfs(grid,gridSize,a,i,j);
                if(count > maxCount) {
                    maxCount = count;
                }
            }
        }
    }
    return maxCount;
}
