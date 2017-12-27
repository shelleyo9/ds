/*
Errors:
1.Find()的循环条件：ptr->data!=X && ptr->next!=NULL 这两个条件的组合是错误的，如果链表为空则有错
2.Insert()使用malloc()来分配节点内存时没有考虑失败的情况
3.DeleteList()只释放了表头的空间
4.multiple definition. 因为在exce.c中include了list.c，从而导致编译了两次list.c。实际上main方法如果想调用
    list.c中的某个方法时，只需要include list.h即可，list.h中包含了对可复用方法的声明，而不包含定义。
    随着项目规模的庞大，有可能会遇到某个头文件被多次包含的情况，这时使用#ifndef #define #endif来避免
    重复头文件包含
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

int main() {
    /*
    List L=NULL;
    L = MakeEmpty(L);
    Insert(1, L);
    Insert(2, L);

    PrintList(L);
    */
    /*
    int M = 10, N=10, times=3;
    int a[10] = {64,8,216,512,27,729,0,1,343,125};

    RadixSort(a, M, N, times);
    */
    /*
    PList P1 = NULL, P2 = NULL;
    P1 = MakeEmptyP(P1);
    P2 = MakeEmptyP(P2);

    InsertPNode(P1, 3, 2);
    InsertPNode(P1, 2, 1);
    PrintPList(P1);


    InsertPNode(P2, 1, 4);
    InsertPNode(P2, 5, 2);
    InsertPNode(P2, 3, 1);
    PrintPList(P2);

    PList PSum = NULL;
    PSum = MakeEmptyP(PSum);
    AddPolynomia(P1, P2, PSum);
    PrintPList(PSum);
    */

    //Josephus2(1, 5);
    //threedoteighteen('ab');
    //Stack S = CreateStack();
    //MakeEmptyS(S);

    //printf("%d",PostFix("6523+8*+3+*"));
    //Infix2Postfix("1+2");
    //TestFinb(50);
    return 0;
}








