//
// Created by 심하민 on 2023/01/31.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} cor;
int compare(const void *a, const void *b){
    cor* c1 = (cor*) a;
    cor* c2 = (cor*) b;
    if(c1->x == c2->x){
        return c1->y < c2->y ? -1 : 1;
    }
    return c1->x < c2->x ? -1 : 1;
}
int main(){
    int N;
    scanf("%d", &N);
    cor* cors = (cor*) malloc(sizeof (cor)*N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &cors[i].x,&cors[i].y);
    }
    qsort(cors, N, sizeof (cor), compare);
    for(int i=0;i<N;i++){
        printf("%d %d\n", cors[i].x,cors[i].y);
    }
    return 0;
}