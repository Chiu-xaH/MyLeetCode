int count = 0;

void dfs(int point,int** graph,bool* visited,int n) {
    visited[point] = true;
    for(int i = 0;i < n;i++) {
        int v = graph[point][i];
        if(v != 0 && !visited[i]) {
            if(v == 1) {
                count++;
            }
            dfs(i,graph,visited,n);
        }
    }
}

void createGraph(int** connections, int connectionsSize,int** graph,int n) {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];
        graph[a][b] = 1;   // 原方向
        graph[b][a] = -1;  // 反方向
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    bool *visited = calloc(n, sizeof(bool));
    for(int i = 0;i < n;i++) {
        visited[i] = false;
    }

    int **graph = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = calloc(n, sizeof(int));
    }

    createGraph(connections,connectionsSize,graph,n);

    count = 0;
    dfs(0,graph,visited,n);

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);
    return count;
}

/////////////////////////////////////////////写法2

typedef struct {
    int to;
    int dir; // 1 表示原方向 point->to, -1 表示反方向
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} AdjList;

int count = 0;

void addEdge(AdjList *graph, int u, int v, int dir) {
    if (graph[u].size == graph[u].capacity) {
        graph[u].capacity = graph[u].capacity ? graph[u].capacity * 2 : 4;
        graph[u].edges = realloc(graph[u].edges, graph[u].capacity * sizeof(Edge));
    }
    graph[u].edges[graph[u].size++] = (Edge){v, dir};
}

void dfs(int point, AdjList *graph, bool *visited) {
    visited[point] = true;
    for (int i = 0; i < graph[point].size; i++) {
        int v = graph[point].edges[i].to;
        int dir = graph[point].edges[i].dir;
        if (!visited[v]) {
            if (dir == 1) { // 原方向需要反转
                count++;
            }
            dfs(v, graph, visited);
        }
    }
}

int minReorder(int n, int **connections, int connectionsSize, int *connectionsColSize) {
    bool *visited = calloc(n, sizeof(bool));
    AdjList *graph = calloc(n, sizeof(AdjList));

    // 建立邻接表
    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];
        addEdge(graph, a, b, 1);   // 原方向
        addEdge(graph, b, a, -1);  // 反方向
    }

    count = 0;
    dfs(0, graph, visited);

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(graph[i].edges);
    }
    free(graph);
    free(visited);

    return count;
}