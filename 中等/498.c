/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    *returnSize = matSize * *matColSize;
    int* arr = (int*)malloc(sizeof(int) * *returnSize);
    //arr指针
    int count = 0;
    //向上走 i+1,j+1
    //向下走 i-1,j-1
    //几条路
    int pathNum = matSize + *matColSize - 1;
    //每次起点为上次终点右边 i,j+1
    //初始起点0,0
    for(int i = 0;i < pathNum;i++) {
        //向上走
        if(i % 2 == 0) {
            int row = (i < matSize) ? i : matSize - 1;
            int col = (i < matSize) ? 0 : i - matSize + 1;
            while (row >= 0 && col < *matColSize) {
                arr[count++] = mat[row][col];
                row--;
                col++;
            }
        } else {
            //向下走
            int row = (i < *matColSize) ? 0 : i - *matColSize + 1;
            int col = (i < *matColSize) ? i : *matColSize - 1;
            while (row < matSize && col >= 0) {
                arr[count++] = mat[row][col];
                row++;
                col--;
            }
        }
    }
    return arr;
}