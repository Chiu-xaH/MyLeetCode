int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    bool change = false;
    int count = 0;
    while(true) {
        // 感染
        for(int i = 0;i < gridSize;i++) {
            int jSize = gridColSize[i];
            for(int j = 0;j < jSize;j++) {
                if(grid[i][j] == 2) {
                    if(i-1 >= 0 && grid[i-1][j] == 1) {
                        grid[i-1][j] = 3;
                    }
                    if(i+1 < gridSize && grid[i+1][j] == 1) {
                        grid[i+1][j] = 3;
                    }
                    if(j-1 >= 0 && grid[i][j-1] == 1) {
                        grid[i][j-1] = 3;
                    }
                    if(j+1 < jSize && grid[i][j+1] == 1) {
                        grid[i][j+1] = 3;
                    }
                }
            }
        }
        for(int i = 0;i < gridSize;i++) {
            int jSize = gridColSize[i];
            for(int j = 0;j < jSize;j++) {
                if(grid[i][j] == 3) {
                    grid[i][j] = 2;
                    change = true;
                }
            }
        }
        // 复位 计数
        if(change == true) {
            count++;
            change = false;
        } else {
            break;
        }
    }
    // 存在新鲜
    for(int i = 0;i < gridSize;i++) {
        int jSize = gridColSize[i];
        for(int j = 0;j < jSize;j++) {
            if(grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return count;
}