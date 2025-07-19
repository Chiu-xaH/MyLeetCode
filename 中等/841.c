void dfs(int** rooms, int roomsSize,int* roomsColSize,int i,bool* visited) {
    visited[i] = true;
    for(int j = 0;j < roomsColSize[i];j++) {
        int value = rooms[i][j];
        if(visited[value] == false) {
            dfs(rooms,roomsSize,roomsColSize,value,visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    for(int i = 0;i < roomsSize;i++) {
        visited[i] = false;
    } 
    dfs(rooms,roomsSize,roomsColSize,0,visited);   
    for(int i = 0;i < roomsSize;i++) {
        if(visited[i] == false) {
            return false;
        }
    }
    return true;
}