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

//基数排序，基于桶排序，进行多次桶排序，每次用最高位进行排序
//为什么使用链表实现基数排序？因为每个桶中数据的个数是不确定的，这种情况下适合用链表
/*
    @param M 桶的数量
    @param N 待排序的整数的数量
    @param times 进行桶排序的次数
*/
void RadixSort(int a[], int M, int N, int times) {
    List Bucket[10];
    Position ptr;
    int i, j, k, r, index, modulo;

    for (i=0; i<times; i++) {
        //初始化桶
        for (r=0; r<M; r++) {
            Bucket[r] = MakeEmpty(Bucket[r]);
        }

        //数据入桶
        for (j=0; j<N; j++) {
            modulo = (a[j]/(int)pow(10, i))%10;
            InsertLast(a[j], Bucket[modulo]);
        }

        //数据出桶，回归到原始结构中，此时已经进行了一次桶排序
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

