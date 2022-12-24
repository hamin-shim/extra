#include <stdio.h>
#include <stdlib.h>

int vertexNum;
int start;
int middle;
int end;
#define MAX  1000
#define _CRT_SECURE_NO_WARNINGS
void checkAdjMatrix(int **adj);
int** initialize(int **adj);
int SPA(int **arr, int startNode, int endNode);
int findMinNode(int* distance, int* set);

int main() {
    int **adj = NULL;
    adj = initialize(adj);
    int startToMiddle = SPA(adj,start, middle);
    int middleToEnd = SPA(adj,middle, end);
    printf("total path: %d",startToMiddle+middleToEnd);
//    checkAdjMatrix(adj);
    return 0;
}
int** initialize(int **arr){
    FILE *fp;
    fp = fopen("ex2.txt","r");
//    fp = fopen("info.txt","r");
    fscanf(fp,"%d %d %d %d", &vertexNum,&start,&middle,&end);
    arr = (int**) malloc ( sizeof(int*) * vertexNum );
    for(int i=0; i<vertexNum; i++){
        arr[i] = (int*) malloc ( sizeof(int) * vertexNum );
    }
    for (int i=0;i<vertexNum;i++){
        for(int j=0;j<vertexNum;j++){
            fscanf(fp,"%d", &arr[i][j]);
            if(arr[i][j]==0) arr[i][j] = MAX;
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
    return arr;
}

int SPA(int **arr, int startNode, int endNode){
    int *d = (int*) malloc ( sizeof(int) * vertexNum );
    int *s = (int*) calloc ( vertexNum,sizeof(int));
    s[startNode] = 1;
    for (int i = 0; i<vertexNum; i++) d[i] = arr[startNode][i];
//    for (int i = 0; i<vertexNum; i++) printf("%d ",d[i]);
//    printf("\n");
    for (int i = 0; i < vertexNum - 1; i++){
        int v = findMinNode(d, s);
        s[v] = 1;
//        printf("%d 'st, %d\n",v,d[v]);
        for (int u = 0; u < vertexNum; u++){
            if(s[u]==0){
//                printf("check for %d...\n",u);
                if (d[u] > d[v] + arr[v][u] ){
//                    printf("d[%d] > d[%d] + arr[%d][%d]\n",u,v,u,v);
                    d[u] = d[v] + arr[v][u];
                }
            }
        }
//        printf("after %d turn\n",i);
//        for(int k=0;k<vertexNum;k++) printf("%d ", d[k]);
//        printf("\n");
    }
    for(int k=0;k<vertexNum;k++) printf("%d ", d[k]);
    printf("\nfrom %d to %d, shortest path is %d\n",startNode,endNode,d[endNode]);
    return d[endNode];
}

int findMinNode(int* distance, int* set){
    int min = MAX;
    int idx;
//    printf("start finding min with data ");
//    for(int i=0;i<vertexNum;i++) printf("%d ", distance[i]);
//    printf("\n");
    for(int i=0;i<vertexNum;i++){
        if(!set[i] && min>distance[i]){
            min = distance[i];
            idx = i;
//            printf("new min: %d\n", min);
        }
    }
    return idx;
}

void checkAdjMatrix(int **adj){
    for (int i=0;i<vertexNum;i++){
        for(int j=0;j<vertexNum;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}