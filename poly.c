#include <stdio.h>
#include "list.h"

void PrintPList(PList L) {
    Polynomia ptr = L->next;

    while (ptr != NULL) {
        printf("%d", ptr->Coefficient);
        if (ptr->Exponent != 0 ) {
            printf("x^%d", ptr->Exponent);
        }
        if (ptr->next != NULL) {
            printf("+");
        }
        ptr = ptr->next;
    }
    printf("\n");
}

PList MakeEmptyP(PList L) {
    L = malloc(sizeof(struct PNode));
    if( L == NULL ) {
        printf("Out of memory");
        exit(1);
    }

    L->next = NULL;
    return L;
}

void InsertPNode(PList L, int Coefficient, int Exponent) {
    Polynomia ptr = malloc(sizeof(struct PNode));
    if (ptr==NULL) {
        printf("Out of Memory!");
        exit(1);
    }
    ptr->Coefficient = Coefficient;
    ptr->Exponent = Exponent;

    ptr->next = L->next;
    L->next = ptr;
}


/*
** P1.P2 are assumed to be increasing order in terms of exp
*/
void AddPolynomia(PList P1, PList P2, PList PSum) {
    Polynomia ptr1 = P1->next, ptr2 = P2->next, ptr3;
    int tmp;

    while (ptr1!=NULL && ptr2!=NULL) {
        if (ptr1->Exponent == ptr2->Exponent) {
            InsertPNode(PSum, ptr1->Coefficient+ptr2->Coefficient, ptr1->Exponent);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->Exponent < ptr2->Exponent) {
            InsertPNode(PSum, ptr1->Coefficient, ptr1->Exponent);
            ptr1 = ptr1->next;
        }
        else {
            InsertPNode(PSum, ptr2->Coefficient, ptr2->Exponent);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1!=NULL) {
        InsertPNode(PSum, ptr1->Coefficient, ptr1->Exponent);
        ptr1 = ptr1->next;
    }
    while (ptr2!=NULL) {
        InsertPNode(PSum, ptr2->Coefficient, ptr2->Exponent);
        ptr2 = ptr2->next;
    }
}

void MultiPolynomia(PList P1, PList P2, PList PMul){
    Polynomia ptr1=P1->next, ptr2=P2->next, ptr3, tmp, prev;

    while (ptr1!=NULL) {
        while (ptr2!=NULL) {
            InsertPNode(PMul, ptr1->Coefficient*ptr2->Coefficient, ptr1->Exponent+ptr2->Exponent);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    ptr3 = PMul->next;
    //目标：合并同类项
    while (ptr3!=NULL) {
        prev = ptr3;
        while ((tmp=ptr3->next)!=NULL) {
            if (ptr3->Exponent == tmp->Exponent) {
                ptr3->Coefficient += tmp->Coefficient;
                prev->next = tmp->next;
            }
            tmp = tmp->next;
            prev = prev->next;
        }
        ptr3 = ptr3->next;
    }
}

void PowerPolynomia(PList P, PList PPow, int n) {
    while (n--) {
        MultiPolynomia(P, P, PPow);
        P = PPow;
    }
}
