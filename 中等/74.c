bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int colSize = matrixColSize[0];
    int up = 0;
    int down = matrixSize-1;
    int row = -1;

    while(up <= down) {
        int mid = (up + down) / 2;
        int vStart = matrix[mid][0];
        int vEnd = matrix[mid][colSize-1];
        if(target < vStart) {
            down = mid-1;
        } else if(target > vEnd){
            up = mid+1;
        } else {
            // 在这一行
            row = mid;
            break;
        }
    }

    if(row == -1) {
        return false;
    }

    // 从down找
    int left = 0;
    int right = colSize-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        int v = matrix[row][mid];
        if(target < v) {
            right = mid-1;
        } else if(target > v) {
            left = mid+1;
        } else {
            return true;
        }
    }
    return false;
}