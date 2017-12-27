/*
*   Errors:
*   1.DisposeStack()������ͨ��ָ��Sָ��Array��ǰ����뱣֤S��ΪNULL
*   2.ջ�Ĵ����⡪���Կ�ջ��Pop������ջ��Push
*
*/
#include "stack.h"
#include <stdio.h>

Stack CreateStack() {
    Stack S;
    S = malloc(sizeof(struct StackRecord));
    if (!S)
        exit(1);

    S->Array = malloc(sizeof(int)*1024);
    if (!S->Array)
        exit(1);

    S->Capacity = 1024;
    S->TopOfStack = -1;

    return S;
}

int IsEmptyS(Stack S) {
    return S->TopOfStack == -1;
}

int IsFull(Stack S) {
    return S->TopOfStack == S->Capacity-1;
}

void DisposeStack(Stack S) {
    if (S) {
        free(S->Array);
        free(S);
    }
}

void MakeEmptyS(Stack S) {
    S->TopOfStack = -1;
}

void Push(Stack S, int X) {
    if (IsFull(S)) {
        printf("Full Stack");
        exit(1);
    }
    S->Array[++S->TopOfStack] = X;
}

int Top(Stack S) {
    if (IsEmptyS(S)) {
        printf("Empty Stack");
        exit(1);
    }
    return S->Array[S->TopOfStack];
}

int Pop(Stack S) {
    if (IsEmptyS(S)) {
        printf("Empty Stack");
        exit(1);
    }
    else {
        int top = S->Array[S->TopOfStack];
        S->TopOfStack--;
        return top;
    }
}
