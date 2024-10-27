/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *newM = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int max = -1;
    int maxs = -1;
    for(int i = 0;i < matSize;i++) {
        int count = 0;
        for(int j = 0;j < *matColSize;j++) {
            if(mat[i][j] == 1) {
                count++;
            }
        }
        if(count > max) {
            max = count;
            maxs = i;
        }
    }
    newM[0] = maxs;
    newM[1] = max;
    return newM;
}