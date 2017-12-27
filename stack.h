#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct StackRecord;
typedef struct StackRecord *Stack;

struct FakeStackRecord;
typedef struct FakeStackRecord *FakeStack;

//***********************************
Stack CreateStack();
int IsEmptyS(Stack S);
int IsFull(Stack S);
void DisposeStack(Stack S);
void MakeEmptyS(Stack S);
void Push(Stack S, int X);
int Top(Stack S);
int Pop(Stack S);



struct StackRecord{
    int Capacity;
    int TopOfStack;
    int *Array;
};

struct FakeStackRecord{
    int ptr1;
    int ptr2;
    int *Array;
};

#endif // STACK_H_INCLUDED
