int furthestDistanceFromOrigin(char * moves) {
    int distance = 0;
    int ptr = 0;
    int rightCount = 0;
    while(moves[ptr] != '\0') {
        char ch = moves[ptr];
        if(ch == 'L') {
            rightCount--;
        } else if(ch == 'R') {
            rightCount++;
        }
        ptr++;
    }
    bool isRight = (rightCount > 0);
    ptr = 0;
    while(moves[ptr] != '\0') {
        char ch = moves[ptr];
        if(ch == 'L') {
            distance--;
        } else if(ch == 'R') {
            distance++;
        } else {
            if(isRight) {
                distance++;
            } else {
                distance--;
            }
        }
        ptr++;
    }
    return fabs(distance);
}