#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LISTSIZE 10
#define TREESIZE 500

typedef int status;
typedef int KeyType; 
typedef struct {
    KeyType  key;
    char others[20];
} TElemType; //������������Ͷ���

typedef struct BiTNode{  //����������Ķ���
    TElemType  data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct{
	BiTree root;
	char name[30];
} ListElem;

typedef struct{
	ListElem *elem;
	int length;
	int listsize;
} TreeList;
