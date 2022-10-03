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
} VertexType; //顶点类型定义

typedef struct ArcNode {         //表结点类型定义
	int adjvex;              //顶点位置编号 
	int distance;			//弧的权值 
   	struct ArcNode  *nextarc;	   //下一个表结点指针
} ArcNode;

typedef struct{			//创建网时弧信息的定义 
	KeyType v1, v2;		//弧连接的结点的关键字 
	int weight; 		//弧的权值 
} NetType;

typedef struct VNode{				//头结点及其数组类型定义
	VertexType data;       	//顶点信息
   	ArcNode *firstarc;      	 //指向第一条弧
   	} VNode,AdjList[MAX_VERTEX_NUM];
typedef  struct {  //邻接表的类型定义
    AdjList vertices;     	 //头结点数组
    int vexnum,arcnum;   	  //顶点数、弧数
    GraphKind  kind;        //图的类型
} ALGraph;

typedef struct{ //多个图的管理表元素的定义 
	ALGraph G;
	char name[30];
} GraphsElem;

typedef struct{ //图的管理表的定义 
	GraphsElem *elem;
	int length;
	int listsize;
} Graphs;
