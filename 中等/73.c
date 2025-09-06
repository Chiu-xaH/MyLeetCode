void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int colSize = matrixColSize[0];
    bool needZeroCol = false;
    bool needZeroRow = false;
    for(int i = 0;i < matrixSize;i++) {
        if(matrix[i][0] == 0) {
            needZeroCol = true;
        }
    }
    for(int j = 0;j < colSize;j++) {
        if(matrix[0][j] == 0) {
            needZeroRow = true;
        }   
    }
    for(int i = 1;i < matrixSize;i++) {
        for(int j = 1;j < colSize;j++) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1;i < matrixSize;i++) {
        if(matrix[i][0] == 0) {
            // 使这一行都为0
            for(int j = 1;j < colSize;j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 1;j < colSize;j++) {
        if(matrix[0][j] == 0) {
            // 使这一列都为0
            for(int i = 1;i < matrixSize;i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (needZeroRow) {
        for (int j = 0; j < colSize; j++) {
            matrix[0][j] = 0;
        }
    }  
    if (needZeroCol) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}