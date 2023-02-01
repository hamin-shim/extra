//
// Created by 심하민 on 2023/01/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int compare(const void*a, const void*b){
//    int num1 = *(int*)a;
//    int num2 = *(int*)b;
//    return num1<num2 ? -1 : 1;
//}
int main(){
    int N;
    scanf("%d", &N);
    int arr[10001] = {0,};
    for (int i=0;i<N;i++){
        int n;
        scanf("%d", &n);
        arr[n]+=1;
    }
    for (int i=0;i<10001;i++){
        if(arr[i]){
            for(int j=0;j<arr[i];j++){
                printf("%d\n", i);
            }
        }
    }
}