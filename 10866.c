//
// Created by 심하민 on 2023/01/31.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    int num;
    struct node* next;
} Node;
typedef struct que {
    Node* H;
    Node* T;
    int cnt;
} Que;

// function order: enqueue,dequeue,create,delete,check empty,make empty
void EnQ(Que* q,int num);
void EnQ_F(Que* q, int num);
int DeQ(Que* q);
int DeQ_B(Que* q);
void Init_Q(Que* q);
int IsEmpty_Q(Que* q);

// check all the element in stack/que(use only once, at last..)
void Look_Q(Que* q);

int main(void) {
    Que* q = (Que*)malloc(sizeof(Que));
    Init_Q(q);

//    if(IsEmpty_Q(q)) printf("-1\n"); //-1
//    else printf("%d\n",q->H->num);
//    if(IsEmpty_Q(q)) printf("-1\n"); //-1
//    else printf("%d\n",q->T->num);
//    printf("deq %d\n",DeQ(q)); // -1
//    printf("deq back %d\n",DeQ_B(q)); // -1
//    EnQ(q, 1); //1
//    if(IsEmpty_Q(q)) printf("-1\n"); //1
//    else printf("%d\n",q->H->num);
//    printf("deq back %d\n",DeQ_B(q)); // 1
//    EnQ(q,2); //2
//    if(IsEmpty_Q(q)) printf("-1\n"); //2
//    else printf("%d\n",q->T->num);
//    DeQ(q);
//    EnQ_F(q, 10); //10
//    EnQ_F(q, 333); //333,10
//    if(IsEmpty_Q(q)) printf("-1\n"); //333
//    else printf("%d\n",q->H->num);
//
//    if(IsEmpty_Q(q)) printf("-1\n"); //10
//    else printf("%d\n",q->T->num);
//    Look_Q(q);


    int N;
    scanf("%d",&N);
    char mode[10];
    int temp;
    for(int i=0;i<N;i++){
        scanf("%s",mode);
        if(mode[0]=='p'&&mode[1]=='u'){
            scanf("%d",&temp);
            mode[5]=='b' ? EnQ(q,temp) : EnQ_F(q, temp);
            Look_Q(q);
        }else if(mode[0]=='p'){
            mode[4]=='b' ? printf("pop back %d\n",DeQ_B(q)) : printf("pop front %d\n",DeQ(q));
            Look_Q(q);
        }else if(mode[0]=='s'){
            printf("size : %d\n", q->cnt);
            Look_Q(q);
        }else if(mode[0]=='e'){
            printf("empty : %d\n", IsEmpty_Q(q));
            Look_Q(q);
        }else if(mode[0]=='f'){
            if(IsEmpty_Q(q)) printf("-1\n");
            else printf("front : %d\n",q->H->num);
            Look_Q(q);
        }else if(mode[0]=='b'){
            if(IsEmpty_Q(q)) printf("-1\n");
            else printf("back : %d\n",q->T->num);
            Look_Q(q);
        }
    }
    return 0;
}

// create a queue
void Init_Q(Que* q) {
    q->H = NULL;
    q->T = NULL;
    q->cnt = 0;
}


// check a queue empty
int IsEmpty_Q(Que* q) {
    if (q->cnt)
        return 0;
    return 1;
}


// queue->Enqueue
void EnQ(Que* q, int num) {
    printf("push back %d\n",num);
    Node* new = (Node*)malloc(sizeof(Node));
    new->num = num;
    new->next = NULL;
    if (IsEmpty_Q(q)) {
        q->H = new;
    }
    else {
        q->T->next = new;
    }
    q->cnt++;
    q->T = new;
}
void EnQ_F(Que* q, int num) {
    printf("push front %d\n",num);
    Node* new = (Node*)malloc(sizeof(Node));
    new->num = num;
    new->next = q->H;
    q->cnt++;
    q->H = new;
//    if (IsEmpty_Q(q)) {
//        q->H = new;
//    }
//    else {
//        q->T->next = new;
//    }
}

// queue->Dequeue
int DeQ(Que* q) {
    if (IsEmpty_Q(q)) {
//        printf("Since Que is empty.. DeQue doesn't work\n");
        return -1;
    }
    else {
        Node* trash;
        trash = q->H;
        q->H = q->H->next;
        q->cnt--;
        return trash->num;
    }
}

int DeQ_B(Que* q) {
    if (IsEmpty_Q(q)) {
//        printf("Since Que is empty.. DeQue doesn't work\n");
        return -1;
    }
    else {
//        Node* trash;
//        trash = q->T;
//        q->T = q->H->next;
//        q->cnt--;
//        return trash->num;
//        printf("size of que:%d\n",q->cnt);
        Node* eachNode = q->H;
        if(q->cnt==1){
            int num = q->H->num;
            q->cnt--;
            q->H = NULL;
            return num;
        }
        else if(q->cnt==2){
            int num = q->T->num;
            q->cnt--;
            q->T = q->H;
            return num;
        }
        else{
            for (int i = 0; i < q->cnt-2; i++) {
    //            printf("%d\n", eachNode->num);
                eachNode = eachNode->next;
            }
        }
//        printf("before tail : %d, at tail: %d\n", eachNode->num, eachNode->next->num);
        int num = eachNode->next->num;
        q->T = eachNode;
        q->cnt--;
        return num;
    }
}


// look all the queue(use only once!)
void Look_Q(Que* q) {
    printf("info-cnt:%d\n",q->cnt);
    Node* eachNode = q->H;
    for (int i = 0; i < q->cnt; i++) {
        printf("%d ", eachNode->num);
        eachNode = eachNode->next;
    }
    printf("\n");
}