#include <stdio.h>
void moveToTail(int** arr, int* size) { 
    *arr = realloc(*arr, (*size) * sizeof(int));  // 扩展数组大小
    for (int i = *size - 1; i > 0; i--) {
        (*arr)[i] = (*arr)[i-1];
    }
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    digits[digitsSize-1]++;
    for(int i = digitsSize-1;i > 0;i--) {
        if(digits[i] >= 10) {
            digits[i-1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }
    *returnSize = digitsSize;
    while(digits[0] >= 10) {
        int c = digits[0];
        (*returnSize)++;
        moveToTail(&digits, returnSize);  
        
        digits[0] = c / 10;
        digits[1] = c % 10;
    }
    return digits;
}

int main() {
    int d[]={9,9,9,9,9,9};
    int num = 6,returnSize;
    plusOne(d,num,&returnSize);
    for(int i = 0;i < returnSize;i++) {
        printf("%d ",d[i]);
    }
}