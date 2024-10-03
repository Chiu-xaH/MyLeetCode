#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
void reverse(char *str) {
    int len = strlen(str);
    int left = 0,right = len-1;
    while(left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char* result = (char *)malloc(sizeof(char) * (maxLen + 2)); // +2 for possible carry and null terminator
    int carry = 0, count = 0;

    int ptrA = lenA - 1, ptrB = lenB - 1;
    while (ptrA >= 0 || ptrB >= 0 || carry) {
        int sum = carry;
        if (ptrA >= 0) sum += a[ptrA--] - '0';
        if (ptrB >= 0) sum += b[ptrB--] - '0';
        result[count++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[count] = '\0';
    reverse(result);
    return result;
}
int main() {
    char a[] = "1010";
    char b[] = "1011";
    printf("%s",addBinary(a,b));
}