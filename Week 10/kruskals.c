
#include<stdio.h>

void main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int c[n][n];
    printf("Enter cost adjacency matrix: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &c[i][j]);
        }
    }
    int ne = 0, mincost = 0;
    int parent[n];
    for(int i = 0; i < n; i++){
        parent[i] = -1;
    }
    int u = -1, v = -1, a, b;
    while(ne != n - 1){
        int min = 9999;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] < min && c[i][j] > 0) {
                    int root_u = i;
                    int root_v = j;
                    while (parent[root_u] != -1) {
                        root_u = parent[root_u];
                    }
                    while (parent[root_v] != -1) {
                        root_v = parent[root_v];
                    }
                    if (root_u != root_v) {
                        min = c[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            printf("(%d, %d, %d) ", u + 1, v + 1, min);
            parent[v] = u;
            mincost += min;
            ne++;
        }
        c[a][b] = 9999;
        c[b][a] = 9999;
    }
    printf("Mincost: %d", mincost);
}

