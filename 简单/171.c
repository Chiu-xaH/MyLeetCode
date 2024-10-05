void reverse(char *str,int size) {
    int left = 0,right = size-1;
    while(left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int getLength(char *str) {
    int size = 0;
    while(str[size] != '\0') {
        size++;
    }
    return size;
}

int titleToNumber(char* columnTitle) {
    reverse(columnTitle,getLength(columnTitle));
    int result = 0;
    int ptr = 0;
    while(columnTitle[ptr] != '\0') {
        result += (columnTitle[ptr] - 'A' + 1) * pow(26,ptr);
        ptr++;
    }
    return result;
}