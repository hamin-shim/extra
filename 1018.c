//
// Created by 심하민 on 2023/01/30.
//

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);
    char **arr = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (char *)malloc(sizeof(char) * M);
    }
     for (int i = 0; i < N; i++) {
       for (int j = 0; j < M; j++) {
         scanf('%c', &arr[N][M]);
       }
     }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf('%c', arr[N][M]);
        }
    }
    return 0;
}