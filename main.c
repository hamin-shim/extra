#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX  1000

int vertexNum;
int start;
int middle[3];
int middleNum;
int end;

typedef struct path{
    int distance;
    int *pathInfo;
} Path;

void checkAdjMatrix(int **adj);
int** initialize(int **adj);
Path SPA(int **arr, int startNode, int endNode);
int findMinNode(int* distance, int* set);
void printAnswer(Path ans, int s, int e);

int main() {
    int **adj = NULL;
    adj = initialize(adj);
    Path ans1 = SPA(adj, start,end);
    printf("1. without waypoint\n");
    printAnswer(ans1, start, end);
//    printf("middle number:%d\n", middleNum);
    printf("2. when there is waypoint\n");
    for(int i=0;i<middleNum;i++){
//        printf("middle node:%d\n",middle[i]);
        if(i==0) {
            Path ans2 = SPA(adj,start,middle[i]);
            printAnswer(ans2, start, middle[i]);
        }else{
            Path ans2 = SPA(adj,middle[i-1],middle[i]);
            printf("path :: %d\n", ans2.pathInfo[middle[i]]);
            printAnswer(ans2, middle[i-1], middle[i]);
        }
    }
    return 0;
}

int** initialize(int **arr){
    FILE *fp;
    fp = fopen("ex2.txt","r");
//    fp = fopen("info.txt","r");
    fscanf(fp,"%d %d %d", &vertexNum,&start,&end);
    middleNum=0;
    while(1){
        char ch = fgetc(fp);
        if(ch=='\n'){
            break;
        }else if(ch != ' '){
            middle[middleNum++] = ch-48;
        }
    }
//    for (int i=0;i<middleNum;i++){
//        printf("%d'st : %d\n", i, middle[i]);
//    }
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

Path SPA(int **arr, int startNode, int endNode){
    int *d = (int*) malloc ( sizeof(int) * vertexNum );
    int *s = (int*) calloc ( vertexNum,sizeof(int));
    int *p = (int*) malloc ( sizeof(int) * vertexNum );

    s[startNode] = 1;
    for (int i = 0; i<vertexNum; i++) {
        d[i] = arr[startNode][i];
        p[i] = -1;
    }
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
                    p[u] = v;
                }
            }
        }
//        printf("after %d turn\n",i);
//        for(int k=0;k<vertexNum;k++) printf("%d ", d[k]);
//        printf("\n");
    }
//    for(int k=0;k<vertexNum;k++) printf("%d ", d[k]);
//    printf("\nfrom %d to %d, shortest path is %d\n",startNode,endNode,d[endNode]);
    Path res;
    res.distance = d[endNode];
    res.pathInfo = p;
    return res;
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

void printAnswer(Path ans, int s, int e){
    int *temp = (int*)malloc(sizeof(int) * vertexNum );
    for(int i=0;i<vertexNum;i++){
        printf("%d ", temp[i]);
    }
    printf("\n");
    int wp = ans.pathInfo[end];
    if(wp!=-1){
        *temp = wp;
        while (ans.pathInfo[wp]!=-1){
            *(temp+1) = ans.pathInfo[wp];
            wp = ans.pathInfo[wp];
        }
    }
    for(int i=0;i<vertexNum;i++){
        printf("%d", temp[i]);
    }
    printf("\n");
    printf("Path info:");
    printf("%d->",s);
    int tempSize = sizeof(temp) / sizeof(int);
    printf("temp size:%d\n",tempSize);
    for (int i = 1; i <= tempSize; ++i) {
        printf("%d->",temp[tempSize-i]);
    }
    printf("%d,",e);
    printf("Total distance:%d\n",ans.distance);
}