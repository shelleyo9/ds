#include <stdio.h>
#include "list.h"

void PrintList2(List L) {
    Position ptr = L;

    while(ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

void PrintList(List L) {
    Position ptr = L->next;

    while(ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

List MakeEmpty(List L) {
    L = malloc( sizeof( struct Node ) );
    if( L == NULL ) {
        printf("Out of memory");
        exit(1);
    }

    L->next = NULL;
    return L;
}

int IsEmpty(List L) {
    return (L->next==NULL);
}

int IsLast(Position P, List L) {
    return (P->next==NULL);
}

Position Find(int X, List L) {
    Position ptr = L->next;

    while(ptr!=NULL && ptr->data != X) {
        ptr = ptr->next;
    }

    return ptr;
}

void Delete(int X, List L) {
    Position prev, tmp;
    prev = FindPrevious(X, L);

    tmp = prev->next;
    prev->next = tmp->next;
    free(tmp);//?????????
}


Position FindPrevious(int X, List L){
    Position ptr = L;

    while(ptr->next != NULL && ptr->next->data != X) {
        ptr = ptr->next;
    }

    return ptr;

}

void Insert(int X, List L) {
    Position ptr = (Position)malloc(sizeof(struct Node));

    if (ptr == NULL) {
        printf("Error: Out of Space");
        exit(1);
    }

    ptr->data = X;

    ptr->next = L->next;
    L->next = ptr;
}

void InsertLast(int X, List L) {
    Position last = L;
    while(last->next!=NULL) {
        last = last->next;
    }

    Position node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Out of Memory");
        exit(1);
    }
    node->data = X;
    node->next = NULL;

    last->next = node;
}

//设定在p结点前插入一个新结点，值域为X
void InsertBeforeP(int X, List L, Position P) {
    Position newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Out of Space");
        exit(1);
    }
    newNode->data = X;

    Position prev = FindPrevious(P->data, L);
    prev->next = newNode;
    newNode->next = P;
}

void DeleteList(List L) {
    Position ptr = L, tmp;

    while(ptr) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->next;
}

Position Advance(Position P) {
    return P->next;
}

int Retrieve(Position P) {
    return P->data;
}

