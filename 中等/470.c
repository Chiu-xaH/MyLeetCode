int rand10() {
    int r,c,i;
    do {
        r = rand7();
        c = rand7();
        i = c + (r-1)*7;
    } while(i > 40);
    return 1 + (i-1)%10;
}