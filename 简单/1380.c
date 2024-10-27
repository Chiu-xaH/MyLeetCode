/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int a,int b){
    return a > b ? a : b;
}

int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *luckyList = (int*)malloc(sizeof(int) * matrixSize * *matrixColSize);
    *returnSize = 0;
   for(int i = 0; i < matrixSize; i++) {
        // 找到第 i 行的最小值及其列索引
        int rowMin = matrix[i][0];
        int minColIndex = 0;
        for(int j = 1; j < matrixColSize[i]; j++) {
            if(matrix[i][j] < rowMin) {
                rowMin = matrix[i][j];
                minColIndex = j;
            }
        }
        
        // 检查该列是否为列的最大值
        int isLucky = 1;
        for(int k = 0; k < matrixSize; k++) {
            if(matrix[k][minColIndex] > rowMin) {
                isLucky = 0;
                break;
            }
        }
        
        // 如果是幸运数，将其添加到结果列表
        if(isLucky) {
            luckyList[(*returnSize)++] = rowMin;
        }
    }
    return luckyList;
}