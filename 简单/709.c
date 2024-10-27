char* toLowerCase(char* s) {
    int ptr = 0;
    while(s[ptr] != '\0') {
        if(s[ptr] >= 'A' && s[ptr] <= 'Z') {
            s[ptr] += 32;
        }
        ptr++;
    }
    return s;
}