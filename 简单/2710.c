char * removeTrailingZeros(char * num){
    
    int size = 0;
    while(num[size] != '\0') {
        size++;
    }

    int ptr = size-1;

    while(num[ptr] == '0') {
        num[ptr] = '\0';
        ptr--;
    }
    return num;
}