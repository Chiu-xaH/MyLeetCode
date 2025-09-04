
bool back(char** board,int boardSize,int boardColSize,char* word,int i,int j) {
    if(*word == '\0') {
        return true;
    }
    if(i >= boardSize || j >= boardColSize || i < 0 || j < 0) {
        return false;
    }
    if(board[i][j] != *word) {
        return false;
    }
    
    char temp = board[i][j]; // 保存当前格子
    board[i][j] = '#';       // 标记为已访问
    bool found = 
        back(board,boardSize,boardColSize,word+1,i+1,j) || 
        back(board,boardSize,boardColSize,word+1,i-1,j) || 
        back(board,boardSize,boardColSize,word+1,i,j+1) || 
        back(board,boardSize,boardColSize,word+1,i,j-1);

    board[i][j] = temp; // 回溯，恢复原字符

    return found;   
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int colSize = boardColSize[0];
    // 找到起点
    char startChar = word[0];
    for(int i = 0;i < boardSize;i++) {
        for(int j = 0;j < colSize;j++) {
            char val = board[i][j];
            if(val == startChar) {
                if (back(board, boardSize, colSize, word, i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}
