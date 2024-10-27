int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int** newImg = (int**)malloc(imgSize * sizeof(int*));
    for (int i = 0; i < imgSize; i++) {
        newImg[i] = (int*)malloc(*imgColSize * sizeof(int));
    }
    *returnSize = imgSize;
    *returnColumnSizes = (int*)malloc(imgSize * sizeof(int));
    for (int i = 0; i < imgSize; i++) {
        (*returnColumnSizes)[i] = *imgColSize;
    }

    for(int i = 0;i < imgSize;i++) {
        for(int j = 0;j < *imgColSize;j++) {
            int res = img[i][j];
            int count = 1;
            if(i-1 >= 0) {
                res += img[i-1][j];
                count++;
            }
                
            if(i+1 < imgSize) {
                res += img[i+1][j];
                count++;
            }
                
            if(j-1 >= 0) {
                res += img[i][j-1];
                count++;
            }
                
            if(j+1 < *imgColSize) {
                res += img[i][j+1];
                count++;
            }
                
            if(i+1 < imgSize && j+1 < *imgColSize) {
                res += img[i+1][j+1];
                count++;
            }
                
            if(j-1 >= 0 && i+1 < imgSize) {
                res += img[i+1][j-1];
                count++;
            }
                
            if(j+1 < *imgColSize && i-1 >= 0) {
                res += img[i-1][j+1];
                count++;
            }
                
            if(i-1 >= 0 && j-1 >= 0) {
                res += img[i-1][j-1];
                count++;
            }
            newImg[i][j] = res / count;
        }
    }
    return newImg;
}