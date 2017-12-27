/*
*   Errors:
*   1.检测平衡符号程序中，比较字符串内容是否相同需要使用strcmp，如果char A[]=..., char B[]=...,
*       if A==B will only check the addr of these two strings.
*   2.由于Stack中存储的元素类型不同所以需要定义多个Stack结构体和对应的例程。。。
*/
#include <stdio.h>
#include "list.h"
#include "stack.h"

void threedottwo(List L, List P) {
    int gap = 0;
    Position header_l = L->next, header_p = P->next;

    while (header_p!=NULL) {
        gap = header_p->data - gap;
        while (header_l!=NULL && gap--) {
            printf("%d", header_l->data);
            header_l = header_l->next;
        }
        header_p = header_p->next;
    }
}

void threedotthreedotoen(List L) {
    Position p = L->next;
    Position pre,tmp;

    while (p && p->next) {
        pre = FindPrevious(p->data, L);
        tmp = p->next;
        p->next = tmp->next;
        tmp->next = p;
        pre->next = tmp;

        p = p->next;
    }
}

void threedotthreedottwo(DoublyList L) {
    DPosition p = L->next;
    DPosition tmp;

    while (p && p->next) {
        tmp = p->next;
        p->previous->next = tmp;
        p->next = tmp->next;
        tmp->next = p;

        tmp->previous = p->previous;
        p->previous = tmp;
        //p->next->previous = p;
    }
}

void threedotfour(List L1, List L2) {
    Position p1 = L1->next, p2 = L2->next;

    while (p1 && p2) {
        if (p1->data == p2->data) {
            printf("%d", p1->data);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->data < p2->data) {
            p1 = p1->next;
        }
        else {
            p2 = p2->next;
        }
    }
}

void threedotfive(List L1, List L2) {
    Position p1 = L1->next, p2 = L2->next;

    while (p1 && p2) {
        if (p1->data == p2->data) {
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->data < p2->data) {
            printf("%d", p1->data);
            p1 = p1->next;
        }
        else {
            printf("%d", p2->data);
            p2 = p2->next;
        }
    }

    while (p1) {
        printf("%d", p1->data);
        p1 = p1->next;
    }

    while (p2) {
        printf("%d", p2->data);
        p2 = p2->next;
    }
}

/*
** Errors:
** 1. 应该使用一个数组标记已经出局的人
** 2. 对于出局的人，标记数组对应的值改变
** 3. M代表传递的次数，所以如果用count来标识一轮游戏的话，count需要累加(M+1)次，因为count在当前玩家存活的情况下+1
** 4. 新一轮游戏从上一轮出局玩家的后一位存活玩家开始
** 5. 玩家物理上是一个圈所以对应的数组需要逻辑上首尾相连
*/
void Josephus(int M, int N) {
    int round=0, ptr=0, count=0, isdead[N];
    memset(isdead, 0, sizeof(isdead));

    //run (N-1) times to get the man surviving at the end
    for (round = 0; round < N-1; round++) {
        count = 0;
        while (count <= M) {
            if (!isdead[ptr]) {
                count++;
            }
            ptr++;
            if (ptr == N)
                ptr = 0;
        }
        isdead[(ptr-1+N)%N] = 1;
        printf("No.%d\n",(ptr-1+N)%N);

        while(isdead[ptr]) {
            ptr++;
            if (ptr == N)
                ptr = 0;
        }
    }
}

List CreateCircledList(List L, int N) {
    Position tmp,r;
    Position p = malloc(sizeof(struct Node));
    p->data = --N;
    p->next = NULL;
    L = p;
    r = L;

    while (N-- != -1) {
        Position p = malloc(sizeof(struct Node));
        p->data = N;
        tmp = L;

        L = p;
        p->next = tmp;
    }

    r->next = L;
    return L;
}

void Josephus2(int M, int N) {
    List L = NULL;
    L = CreateCircledList(L, 5);
    Position ptr = L, pre;
    //PrintList(L);

    int count, isdead[N];
    memset(isdead, 0, sizeof(isdead));

    while(--N) {
        count = 0;
        while(count <= M) {
            if (!isdead[ptr->data]) {
                count++;
            }
            pre = ptr;
            ptr = ptr->next;
        }
        printf("No,%d player is out", pre->data);
        isdead[pre->data] = 1;
    }
}

/*
* 在尾节点处进行前插
*/
void threedottwelvedotone(List L) {
    Position r = L->next, p = L->next, tmp;

    while(r->next) {
        r= r->next;
    }

    while(p != r) {
        tmp = p->next;
        p->next = r->next;
        r->next = p;
        p = tmp;
    }
}

/*
*  从第二个node开始往Head前插
*/
void ReverseList(List L) {
    Position p = L->next, current;

    while (p->next) {
        current = p->next;
        p = current->next;
        current->next = L->next;
        L->next = current;
    }
}

Position threedoteleven(List L, int X) {
    Position p = L->next;

    while (p && p->data != X) {
        p = p->next;
    }

    return p;
}

Position RecursiveFindList(List L, int X) {
    if (L == NULL)
        return NULL;
    if (L->data == X)
        return L;
    return RecursiveFindList(L->next, X);
}

void SelfAdjustingInsert(int A[], int N, int x) {
    int i;
    for (i=N-1; i>0; i--) {
        A[i] = A[i-1];
    }
    A[0] = x;
}

void SelfAdjustingFind(int A[], int N, int x) {
    int index, i;
    for (i=0; i<N; i++) {
        if (A[i] == x){
            index = i;
            break;
        }
    }

    for (i=index; i>0; i--) {
        A[i] = A[i-1];
    }
    A[0] = A[index];
}

//3.16
void DeleteDuplicate(int A[], int N) {
    int i, j, r, LastPosition = N-1;
    for (i=0; i<LastPosition; i++) {
        j = i+1;
        while(j < LastPosition) {
            if (A[j] == A[i]) {
                for (r=j+1; r < LastPosition; r++) {
                    A[r] = A[r+1];
                }
                LastPosition--;
            }
            else {
                j++;
            }
        }
    }
}

char *left[3] = {"(", "[", "{"};
    char *right[3] = {")", "]", "}"};
    char *pair[3] = {"()", "[]", "{}"};
//q:如何表示一对平衡符号是匹配的？
//3.18
int threedoteighteen(char input[], int N) {
    int i, j, k;
    Stack S;
    S = CreateStack();

    for(i=0; i<N; i++) {
        for(j=0; j<3; j++) {
            if (input[i] == left[j]) {
                Push(S, input[i]);
            }
            else if (input[i] == right[j]) {
                if (IsEmpty(S))
                    return -1;
                for (k=0; k<3; k++) {
                    if (!strcmp(strcat(Top(S),input[i])), pair[k]) {
                        Pop(S);
                        break;
                    }
                }
                if (k == 3)
                    return -1;
            }
        }
    }

    if (!IsEmpty(S))
        return -1;

    return 1;
}

/*
    3.19 计算后缀表达式的值，支持加减乘除
    q:如果pop返回结果为-1.调用函数该如何处理？
*/
int PostFix(char *cal) {
    int i, N = strlen(cal), x, y;
    Stack S = CreateStack();


    for (i=0; i<N; i++) {
        if (cal[i] >= '0' && cal[i] <='9') {
            Push(S, (int)cal[i]-48);
        }
        else {
            switch (cal[i]) {
            case '+' :
                y = Pop(S);
                x = Pop(S);
                x = x + y;
                Push(S, x);
                break;
            case '-' :
                y = Pop(S);
                x = Pop(S);
                x = x - y;
                Push(S, x);
                break;
            case '*' :
                y = Pop(S);
                x = Pop(S);
                x = x * y;
                Push(S, x);
                break;
            case '/' :
                y = Pop(S);
                x = Pop(S);
                x = x / y;
                Push(S, x);
                break;
            }
        }
    }

    return Top(S);
}

/*
*   3.20 对输入的运算符进行优先级比较
*/
int OperationPriority(char x, char y) {
    int pos, pos1, i, j;
    char operation[6] = {'(', ')', '+', '-', '*', '/'};

    for (i=0; i<6; i++) {
        if (operation[i] == x)
            pos = i;
        if (operation[i] == y)
            pos1 = j;
    }

    if (i==j)
        return 0;
    else if (i>j)
        return 1;
    else
        return -1;
}

//3.20
//q:怎么表示运算符的优先级
void Infix2Postfix(char *input) {
    Stack S = CreateStack();
    int i, N = strlen(input);

    for (i=0; i<N; i++) {
        if (input[i] >= '0' && input[i] <= '9')
            printf("%d", input[i]-48);
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            //if input's priority > TopOfStack or stack is empty or TopOfStack is (, push it into stack
            if (IsEmptyS(S) || OperationPriority(input[i], Top(S)) == 1 ||  Top(S) == '(') {
                Push(S, input[i]);
            }
            //if input's priority <= TopOfStack, pop TopOfStack and repush it after computation
            else {
                while (OperationPriority(input[i], Top(S)) <= 0) {
                    printf("%c", Top(S));
                    Pop(S);
                }
            }
        }
        else if (input[i] == '(') {
                    Push(S, input[i]);
            }
        else if (input[i] == ')') {
            while (Top(S) != '(') {
                    printf("%c", Top(S));
                    Pop(S);
            }
            Pop(S);
        }
    }
}

int TestFinb(int N) {
    if (N==1 || N==0)
        return 1;
    return TestFinb(N-1)+TestFinb(N-2);
}

