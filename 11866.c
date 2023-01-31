//
// Created by 심하민 on 2023/01/31.
//
#include <stdio.h>
#include <stdlib.h>


int main(){
    int N,K,P=-1,cnt=0;
    scanf("%d %d", &N,&K);
    int *arr = (int*) malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) arr[i]=i+1;
//    for(int i=0;i<N;i++) printf("arr[%d]:%d\n",i,arr[i]);
    printf("<");
    while(1){
        if(cnt==N) break;
//        P+=K;
//        P%=N;
//        while(1){
//            if(arr[P]==0){
//                P+=1;
//                P%=N;
//            } else break;
//        }
        for(int i=0;i<K;i++){
            while(1){
                P++;
                P%=N;
                if(arr[P]==0) continue;
                else break;
            }
        }
        if(cnt!=N-1) printf("%d, ", arr[P]);
        else printf("%d>", arr[P]);
        arr[P]=0;
        cnt++;
    }
    return 0;
}