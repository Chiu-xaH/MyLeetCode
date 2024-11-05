//按主对角线翻折，再将列逆序
//将图像顺时针旋转 90 度
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i = 0;i < matrixSize;i++) {
        for(int j = i+1;j < *matrixColSize;j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        int left = 0, right = *matrixColSize - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}