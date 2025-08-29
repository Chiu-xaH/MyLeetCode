

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0;
    int j = matrixColSize[0]-1;
    while(i < matrixSize && j >= 0) {
        int root = matrix[i][j];
        if(target > root) {
            // 向右子树找
            i++;
        } else if (target < root) {
            // 向左子树找
            j--;
        } else {
            return true;
        }
    }
    return false;
}