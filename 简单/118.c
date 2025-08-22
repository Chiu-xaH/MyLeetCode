/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
*returnSize = numRows;

    // 动态分配二维数组
    int** dp = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for(int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        dp[i] = (int*)malloc((i + 1) * sizeof(int));
        dp[i][0] = 1; // 每行第一个元素
        dp[i][i] = 1; // 每行最后一个元素

        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    return dp;
}