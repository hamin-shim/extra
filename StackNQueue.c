//
// Created by 심하민 on 2022/11/09.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    char value[10];
    struct node* next;
} Node;
typedef struct que {
    Node* H;
    Node* T;
    int cnt;
} Que;
typedef struct stack {
    Node* top;
    int cnt;
} Stack;

// function order: pop,push,create,delete,check empty,make empty,peek top
char* Pop(Stack* stack);
void Push(Stack* stack, char value[10]);
void Init_S(Stack* stack);
void Delete_S(Stack* stack);
int IsEmpty_S(Stack* stack);
void Empty_S(Stack* stack);
void Peek_S(Stack* stack);

// function order: enqueue,dequeue,create,delete,check empty,make empty
void EnQ(Que* q, char value[10]);
char* DeQ(Que* q);
void Init_Q(Que* q);
void Delete_Q(Que* q);
int IsEmpty_Q(Que* q);
void Empty_Q(Que* q);

// check all the element in stack/que(use only once, at last..)
void Look_S(Stack* stack);
void Look_Q(Que* q);

int main(void) {
    int mode;
    printf("What type of program you want? 0:Stack, 1:Queue\n");
    scanf("%d", &mode);
    char stOrQ[10];
    mode ? strcpy(stOrQ, "Queue") : strcpy(stOrQ, "Stack");
    Stack* st = (Stack*)malloc(sizeof(Stack));
    Que* Q = (Que*)malloc(sizeof(Que));
    printf("%s is selected, initializing...\n", stOrQ);
    mode ? Init_Q(Q) : Init_S(st);
    int empty_result;
    while (1) {
        int func_mode;
        char temp[10];
        printf("Select what you want to do...\n");
        mode ? printf("1.Enqueue, 2.Dequeue, 3.Delete queue, 4.Check empty, 5.Make "
                      "empty\n====================================::Press 0 to exit::====================================\n")
             : printf("1.Push, 2.Pop, 3.Delete a stack, 4.Check a stack empty, "
                      "5.Make a stack empty, 6.Peek\n====================================::Press 0 to exit::====================================\n");
        scanf("%d", &func_mode);
        if (func_mode == 0)
            break;
        switch (func_mode) {
            case 1:
                printf("What word do you want to save?(Warn: Max length is 10!)\n");
                scanf("%s", temp);
                mode ? EnQ(Q, temp) : Push(st, temp);
                break;
            case 2:
                mode ? printf("Dequeue: %s\n", DeQ(Q)) : printf("Pop: %s\n", Pop(st));
                break;
            case 3:
                mode ? Delete_Q(Q) : Delete_S(st);
                printf("You deleted the %s.. so recommend you should re-execute this "
                       "program.",
                       stOrQ);
                break;
            case 4:
                if (mode)
                    empty_result = IsEmpty_Q(Q);
                else
                    empty_result = IsEmpty_S(st);
                empty_result ? printf("%s is empty\n", stOrQ)
                             : printf("%s is not empty\n", stOrQ);
                break;
            case 5:
                mode ? Empty_Q(Q) : Empty_S(st);
                break;
            case 6:
                mode ? printf("You choose wrong option.. do again") : Peek_S(st);
                break;
            default:
                printf("Please choose between 1~5(6)");
        }
    }
    printf("Exit: Now, in %s, there is\n", stOrQ);
    mode ? Look_Q(Q) : Look_S(st);
    printf("Fin.");
    return 0;
}

// create a stack
void Init_S(Stack* stack) {
    stack->top = NULL;
    stack->cnt = 0;
}

// create a queue
void Init_Q(Que* q) {
    q->H = NULL;
    q->T = NULL;
    q->cnt = 0;
}

// delete a stack
void Delete_S(Stack* stack) { free(stack); }

// delete a stack
void Delete_Q(Que* q) { free(q); }

// check a stack empty
int IsEmpty_S(Stack* stack) {
    if (stack->top == NULL)
        return 1;
    return 0;
}

// check a queue empty
int IsEmpty_Q(Que* q) {
    if (q->cnt)
        return 0;
    return 1;
}

// stack-push
void Push(Stack* stack, char value[10]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    //    newNode->value = value;
    strcpy(newNode->value, value);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->cnt++;
}

// stack-pop
char* Pop(Stack* stack) {
    if (IsEmpty_S(stack)) {
        printf("Stack is empty, nothing can be poped..\n");
        return NULL;
    }
    else {
        Node* trash;
        trash = stack->top;
        stack->top = stack->top->next;
        stack->cnt--;
        return trash->value;
    }
}

// queue->Enqueue
void EnQ(Que* q, char value[10]) {
    Node* new = (Node*)malloc(sizeof(Node));
    strcpy(new->value, value);
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
char* DeQ(Que* q) {
    if (IsEmpty_Q(q)) {
        printf("Since Que is empty.. DeQue doesn't work\n");
        return NULL;
    }
    else {
        Node* trash;
        trash = q->H;
        q->H = q->H->next;
        q->cnt--;
        return trash->value;
    }
}

// look at the top of a stack
void Peek_S(Stack* stack) {
    if (IsEmpty_S(stack))
        printf("Stack is empty");
    else
        printf("Peek the top: %s\n", stack->top->value);
}

// make stack empty
void Empty_S(Stack* stack) {
    while (!IsEmpty_S(stack)) {
        printf("Pop %s\n", stack->top->value);
        Pop(stack);
        printf("After pop, stack size is..%d\n", stack->cnt);
        if (stack->cnt == 0) printf("Done, Stack is empty now.\n");
    }
}

// make queue empty
void Empty_Q(Que* q) {
    while (!IsEmpty_Q(q)) {
        printf("Dequeue %s\n", q->H->value);
        DeQ(q);
        printf("After dequeue, queue size is..%d\n", q->cnt);
        if (q->cnt == 0) printf("Done, Queue is empty now.\n");
    }
}

// look all the stack(use only once!)
void Look_S(Stack* stack) {
    for (int i = 0; i < stack->cnt; i++) {
        printf("%s\n", stack->top->value);
        stack->top = stack->top->next;
    }
}

// look all the queue(use only once!)
void Look_Q(Que* q) {
    Node* eachNode = q->H;
    for (int i = 0; i < q->cnt; i++) {
        printf("%s\n", eachNode->value);
        eachNode = eachNode->next;
    }
}