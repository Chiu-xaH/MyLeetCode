void initVisited(bool* visited,int isConnectedSize) {
    for(int i = 0;i < isConnectedSize;i++) {
        visited[i] = false;
    }
}
void DFS(int** isConnected,int isConnectedSize,bool* visited,int i) {
    visited[i] = true;
    for(int j = 0;j < isConnectedSize;j++) {
        if(isConnected[i][j] == 1 && visited[j] == false) {
            DFS(isConnected,isConnectedSize,visited,j);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    // 思路：求联通分量
    int count = 0;
    bool visited[isConnectedSize];
    initVisited(visited,isConnectedSize);
    for(int i = 0;i < isConnectedSize;i++) {
        if(visited[i] == false) {
            count++;
            DFS(isConnected,isConnectedSize,visited,i);
        }
    }
    return count;
}

