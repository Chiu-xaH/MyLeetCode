void dfs(char** grid, int gridSize, int gridColSize,int i,int j) {
    grid[i][j] = '0';
    if(i-1 >= 0 && grid[i-1][j] == '1') {
        dfs(grid,gridSize,gridColSize,i-1,j);
    }
    if(j-1 >= 0 && grid[i][j-1] == '1') {
        dfs(grid,gridSize,gridColSize,i,j-1);
    }
    if(i+1 < gridSize && grid[i+1][j] == '1') {
        dfs(grid,gridSize,gridColSize,i+1,j);
    }
    if(j+1 < gridColSize && grid[i][j+1] == '1') {
        dfs(grid,gridSize,gridColSize,i,j+1);
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int a = gridColSize[0];
    int count = 0;
    for(int i = 0;i < gridSize;i++) {
        for(int j = 0;j < a;j++) {
            int node = grid[i][j];
            if(node == '1') {
                // 开始DFS
                count++;
                dfs(grid,gridSize,a,i,j);
            }
        }
    }
    return count;
}
// 力扣200 思路 从1开始只能向上下左右走，为1则走，每走都要将其置为0，直到无路可走，count++，最后直到整张图为0，count值为岛屿数量