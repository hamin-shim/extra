//
// Created by 심하민 on 2023/01/31.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=666;
    int series = 0;
    int K;
    scanf("%d",&K);
    while(1){
        int num = i;
        while(num){
            if(num%1000==666) {
                series++;
                break;
            }
            num/=10;
        }
        if(series==K) break;
        i++;
    }
    printf("%d", i);
    return 0;
}