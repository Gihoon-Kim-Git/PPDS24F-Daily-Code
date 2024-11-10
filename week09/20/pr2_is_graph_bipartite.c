#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool dfs(int** graph, int* color, int node, int col, int* graphColSize){
    color[node] = col;
    for(int k = 0; k<graphColSize[node]; k++){
        int neighbor = graph[node][k];
        if(color[neighbor]==-1){
            if(!dfs(graph,color,neighbor,1-col,graphColSize))
                return false;
            }
        else if(color[neighbor]==col) return false;
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize*sizeof(int));

    for(int i=0;i<graphSize;i++){
        color[i] = -1;
    }

    for(int j=0;j<graphSize;j++){
        if(color[j]==-1){
            if(!dfs(graph,color,j,0,graphColSize)){
                free(color);
               return false;
            }
        }
    }
    free(color);
    return true;
}