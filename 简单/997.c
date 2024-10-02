typedef struct {
	int vexs[100]; 
	int arc[100][100];
	int numNodes, numEdges; 
} MGraph;

void Create(MGraph *G,int n, int trust[][2], int trustSize)  {
    G->numEdges = trustSize;
    G->numNodes = n;

    for(int i = 0;i < G->numNodes;i++) {
        G->vexs[i] = i + 1;
    }
    for(int i = 0;i < G->numNodes;i++) {
        for(int j = 0;j < G->numNodes;j++) {
            G->arc[i][j] = 0;
        }
    }
    for(int i = 0;i < G->numEdges;i++) {    
        int a = trust[i][0] ,b = trust[i][1];
        if(a <= G->numNodes && b <= G->numNodes)
       G->arc[a-1][b-1] = 1;
    }
}


typedef struct {
    int total,in,out;
} Degree;

Degree HaveDegree(MGraph G,int v) {
    Degree degree;
    degree.in = 0;
    degree.out = 0;
    for(int i = 0;i < G.numNodes;i++) {
        int weight = G.arc[v-1][i];
        if (weight == 1) {
            degree.out++;
        }
    }
    for(int j = 0;j < G.numNodes;j++) {
        int weight = G.arc[j][v-1];
        if (weight == 1) {
            degree.in++;
        }
    }
    degree.total = degree.in + degree.out;
    return degree;  
}

int findJudge(int n, int trust[][2], int trustSize, int* trustColSize) {
    MGraph G;
    Create(&G,n,trust,trustSize);
    int ss = -1;
    for(int i = 1;i <= n;i++) {
        Degree degree = HaveDegree(G,i);
        if(degree.out == 0 && degree.in == n-1) {
            ss = i;
        }
    }
    return ss;
}