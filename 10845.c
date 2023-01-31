//
// Created by 심하민 on 2023/01/31.
//

//
// Created by 심하민 on 2022/11/09.
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
int DeQ(Que* q);
void Init_Q(Que* q);
int IsEmpty_Q(Que* q);

// check all the element in stack/que(use only once, at last..)
void Look_Q(Que* q);

int main(void) {
    Que* q = (Que*)malloc(sizeof(Que));
    Init_Q(q);
    int N;
    scanf("%d",&N);
    char mode[10];
    int temp;
    for(int i=0;i<N;i++){
        scanf("%s",mode);
        if(mode[0]=='p'&&mode[1]=='u'){
            scanf("%d",&temp);
            EnQ(q, temp);
        }else if(mode[0]=='p'){
            printf("%d\n",DeQ(q));
        }else if(mode[0]=='s'){
            printf("%d\n", q->cnt);
        }else if(mode[0]=='e'){
            printf("%d\n", IsEmpty_Q(q));
        }else if(mode[0]=='f'){
            if(IsEmpty_Q(q)) printf("-1\n");
            else printf("%d\n",q->H->num);
        }else if(mode[0]=='b'){
            if(IsEmpty_Q(q)) printf("-1\n");
            else printf("%d\n",q->T->num);
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


// look all the queue(use only once!)
void Look_Q(Que* q) {
    Node* eachNode = q->H;
    for (int i = 0; i < q->cnt; i++) {
        printf("%d\n", eachNode->num);
        eachNode = eachNode->next;
    }
}