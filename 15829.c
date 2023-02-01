//
// Created by 심하민 on 2023/01/31.
//

#include <stdio.h>
#include <math.h>
#define M 1234567891
int main(){
    int N;
    scanf("%d\n", &N);
    char alp;
    long long hashed=0;
    for (int i=0;i<N;i++){
        scanf("%c",&alp);
        alp-=96;
        hashed=(hashed+alp*pow(31,i))/M;
    }
    printf("%lld", hashed);
}