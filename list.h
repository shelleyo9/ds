#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

//����
struct Node;
//����ṹ���ָ��
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

typedef struct PNode *PtrToPNode;
typedef PtrToPNode Polynomia;
typedef PtrToPNode PList;

typedef struct DoublyNode *PtrToDNode;
typedef PtrToDNode DPosition;
typedef PtrToDNode DoublyList;


void PrintList(List L);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L);
void InsertLast(int X, List L);
void InsertBeforeP(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);//��ȡ�������һ��λ��
int Retrieve(Position P);

void AddPolynomia(Polynomia P1, Polynomia P2, Polynomia PSum);
void MultiPolynomia(Polynomia P1, Polynomia P2, Polynomia PMul);


struct Node {
    int data;
    Position next;
};

struct PNode {
    int Coefficient;//ϵ��
    int Exponent;//ָ��
    PtrToPNode next;
};

struct DoublyNode {
    int data;
    Position next;
    Position previous;
};

#endif // LIST_H_INCLUDED
