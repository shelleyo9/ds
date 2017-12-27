#include <stdio.h>
#include <math.h>
#include <string.h>
#include "list.h"

void BucketSort(int a[], int Bucket[], int M, int N) {
    int i;
    for (i=0; i<N; i++) {
        Bucket[a[i]]++;
    }

    for (i=0; i<M; i++) {
        while(Bucket[i]--){
            printf("%d,", i);
        }
    }
}

//�������򣬻���Ͱ���򣬽��ж��Ͱ����ÿ�������λ��������
//Ϊʲôʹ������ʵ�ֻ���������Ϊÿ��Ͱ�����ݵĸ����ǲ�ȷ���ģ�����������ʺ�������
/*
    @param M Ͱ������
    @param N �����������������
    @param times ����Ͱ����Ĵ���
*/
void RadixSort(int a[], int M, int N, int times) {
    List Bucket[10];
    Position ptr;
    int i, j, k, r, index, modulo;

    for (i=0; i<times; i++) {
        //��ʼ��Ͱ
        for (r=0; r<M; r++) {
            Bucket[r] = MakeEmpty(Bucket[r]);
        }

        //������Ͱ
        for (j=0; j<N; j++) {
            modulo = (a[j]/(int)pow(10, i))%10;
            InsertLast(a[j], Bucket[modulo]);
        }

        //���ݳ�Ͱ���ع鵽ԭʼ�ṹ�У���ʱ�Ѿ�������һ��Ͱ����
        index = 0;
        for (k=0; k<M; k++) {
            ptr = Bucket[k]->next;
            while(ptr!=NULL) {
                a[index++] = ptr->data;
                ptr = ptr->next;
            }
        }
    }

    for (i=0; i<N; i++) {
        printf("%d,", a[i]);
    }
}

