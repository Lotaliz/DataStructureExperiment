#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define LISTS_INIT_SIZE 50
typedef struct{  //˳���˳��ṹ���Ķ���
	ElemType* elem;
	int length;
	int listsize;
}SqList;
typedef struct{
	SqList L;
	char name[30];
}SqElem;
typedef struct{  //���Ա�Ĺ������
    SqElem* elem;
    int length;
    int listsize;
 }LISTS;
