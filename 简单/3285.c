int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int ptr = 1;
    int* list = (int*)malloc(sizeof(int)*heightSize);
    *returnSize = 0;
    while(ptr < heightSize){
        if(height[ptr-1] > threshold){
            list[*returnSize] = ptr;
             (*returnSize)++;
        }
        ptr++;
    }
    return list;
}