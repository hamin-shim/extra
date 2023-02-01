//
// Created by 심하민 on 2023/01/31.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int w;
    int h;
}person;
int compare(person* lists,int N, person a){
    int res = 1;
    for(int i=0;i<N;i++){
        if(a.w<lists[i].w && a.h<lists[i].h) res++;
    }
    printf("%d ", res);
}
int main(){
    int N;
    scanf("%d\n",&N);
    person* lists = (person*) malloc(sizeof(person)*N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &lists[i].w, &lists[i].h);
    }
    for(int i=0;i<N;i++){
        compare(lists, N,lists[i]);
    }
}
