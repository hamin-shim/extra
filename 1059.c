//
// Created by 심하민 on 2023/02/01.
//

#include <stdio.h>
#include <stdlib.h>
int compare(const void*a, const void*b){
    int num1 = *(int*) a;
    int num2 = *(int*) b;
    return num1<num2 ? -1 : 1;
}
int main(){
    int L, n=0;
    scanf("%d", &L);
    int* arr = (int*)malloc(sizeof(int)*L);
    for(int i=0;i<L;i++){
        scanf("%d", arr+i);
    }
    scanf("%d", &n);
//    printf("n is: %d\n", n);
    qsort(arr, L, sizeof(int), compare);
    int i, num=0;
    if(n<arr[0]){
//        printf("n is smaller than arr[0]\n");
        for(int j=1;j<n;j++){
            num+=arr[0]-n;
        }
        num+=arr[0]-n-1;
        printf("%d", num);
        return 0;
    }
    for(i=1;i<L;i++){
//        printf("n:%d, arr[%d-1]:%d\n",n,i,arr[i-1]);
        if(n==arr[i-1]){
            printf("0");
            return 0;
        }
        if(n>arr[i-1] && n<arr[i]){
            break;
        }
    }
//    printf("i is :%d\n", i);
    for(int j=arr[i-1]+1;j<n;j++){
//        printf("check from %d to %d, num:%d\n", j, arr[i]-1, arr[i]-n);
        num+=arr[i]-n;
//        printf("num: %d\n",num);
    }
    num+=arr[i]-1-n;
    printf("%d", num);
//    printf("n(%d) is between arr[%d]:%d and arr[%d]:%d", n, i-1, arr[i-1], i, arr[i]);

}