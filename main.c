/*
Errors:
1.Find()��ѭ��������ptr->data!=X && ptr->next!=NULL ����������������Ǵ���ģ��������Ϊ�����д�
2.Insert()ʹ��malloc()������ڵ��ڴ�ʱû�п���ʧ�ܵ����
3.DeleteList()ֻ�ͷ��˱�ͷ�Ŀռ�
4.multiple definition. ��Ϊ��exce.c��include��list.c���Ӷ����±���������list.c��ʵ����main������������
    list.c�е�ĳ������ʱ��ֻ��Ҫinclude list.h���ɣ�list.h�а����˶Կɸ��÷����������������������塣
    ������Ŀ��ģ���Ӵ��п��ܻ�����ĳ��ͷ�ļ�����ΰ������������ʱʹ��#ifndef #define #endif������
    �ظ�ͷ�ļ�����
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








