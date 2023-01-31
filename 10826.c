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
typedef struct stack {
    Node* top;
    int cnt;
} Stack;

// function order: pop,push,create,delete,check empty,make empty,peek top
int Pop(Stack* stack);
void Push(Stack* stack, int num);
void Init_S(Stack* stack);
void Delete_S(Stack* stack);
int IsEmpty_S(Stack* stack);
void Empty_S(Stack* stack);
void Peek_S(Stack* stack);



// check all the element in stack/que(use only once, at last..)
void Look_S(Stack* stack);

int main() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    Init_S(st);
    int N;
    scanf("%d",&N);
    char mode[10];
    int temp;
    for(int i=0;i<N;i++){
        scanf("%s",mode);
        if(mode[0]=='p'&&mode[1]=='u'){
            scanf("%d",&temp);
            Push(st, temp);
        }else if(mode[0]=='p'){
            printf("%d\n",Pop(st));
        }else if(mode[0]=='s'){
            printf("%d\n", st->cnt);
        }else if(mode[0]=='e'){
        printf("%d\n", IsEmpty_S(st));
        }else if(mode[0]=='t'){
            Peek_S(st);
        }
    }

    return 0;
}

// create a stack
void Init_S(Stack* stack) {
    stack->top = NULL;
    stack->cnt = 0;
}

// delete a stack
void Delete_S(Stack* stack) { free(stack); }


// check a stack empty
int IsEmpty_S(Stack* stack) {
    if (stack->top == NULL)
        return 1;
    return 0;
}

// stack-push
void Push(Stack* stack,int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num =  num;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->cnt++;
}

// stack-pop
int Pop(Stack* stack) {
    if (IsEmpty_S(stack)) {
//        printf("Stack is empty, nothing can be poped..\n");
        return -1;
    }
    else {
        Node* trash;
        trash = stack->top;
        stack->top = stack->top->next;
        stack->cnt--;
        return trash->num;
    }
}



// look at the top of a stack
void Peek_S(Stack* stack) {
    if (IsEmpty_S(stack))
//        printf("Stack is empty");
        printf("-1\n");
    else
        printf("%d\n", stack->top->num);
}


// look all the stack(use only once!)
void Look_S(Stack* stack) {
    for (int i = 0; i < stack->cnt; i++) {
        printf("%d\n", stack->top->num);
        stack->top = stack->top->next;
    }
}
