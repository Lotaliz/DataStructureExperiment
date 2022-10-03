#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define MAX_GRAPH_NUM 50
#define PEAK 65536
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct {
    KeyType  key;
    char others[20];
} VertexType; //�������Ͷ���

typedef struct ArcNode {         //�������Ͷ���
	int adjvex;              //����λ�ñ�� 
	int distance;			//����Ȩֵ 
   	struct ArcNode  *nextarc;	   //��һ������ָ��
} ArcNode;

typedef struct{			//������ʱ����Ϣ�Ķ��� 
	KeyType v1, v2;		//�����ӵĽ��Ĺؼ��� 
	int weight; 		//����Ȩֵ 
} NetType;

typedef struct VNode{				//ͷ��㼰���������Ͷ���
	VertexType data;       	//������Ϣ
   	ArcNode *firstarc;      	 //ָ���һ����
   	} VNode,AdjList[MAX_VERTEX_NUM];
typedef  struct {  //�ڽӱ�����Ͷ���
    AdjList vertices;     	 //ͷ�������
    int vexnum,arcnum;   	  //������������
    GraphKind  kind;        //ͼ������
} ALGraph;

typedef struct{ //���ͼ�Ĺ����Ԫ�صĶ��� 
	ALGraph G;
	char name[30];
} GraphsElem;

typedef struct{ //ͼ�Ĺ����Ķ��� 
	GraphsElem *elem;
	int length;
	int listsize;
} Graphs;
