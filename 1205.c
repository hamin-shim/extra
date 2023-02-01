//
// Created by 심하민 on 2023/02/01.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, num, P, rank=1;
    scanf("%d %d %d", &N,&num,&P);
    if(N==0){
        printf("1");
        return 0;
    }
    int *rank_list = (int*)malloc(sizeof(int)*P);
    for (int i=0;i<N;i++){
        scanf("%d", rank_list+i);
    }
    for (int i=0;i<N;i++){
        if(num>=rank_list[i]){
//            printf("num(%d) is bigger than rank[%d](%d)\n", num, i, rank_list[i]);
            break;
        }else{
            rank++;
        }
    }
    if(rank<P){
        if(num==rank_list[N-1]) N==P ? printf("-1") : printf("%d", rank);
        else printf("%d", rank);
    }else if(rank==P){
        if(num==rank_list[N-1]) printf("-1");
        else printf("%d", rank);
    }else{
        printf("-1");
    }
//    printf("%d", rank);
}