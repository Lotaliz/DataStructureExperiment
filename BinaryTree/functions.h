#include "def.h"
#include <string.h>

status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。*/
{
    int book[1000], i;
	BiTree *v = &T, stack[1000];    
    for(i = 0; i < 1000; i++) book[i] = 0;
    i = 0;
    while(definition[i].key != -1){
		book[definition[i].key]++;
		i++;
	}
    for(i = 1; i < 1000; i++) {
		if(book[i] > 1) return ERROR;
	}
    int top = -1;
    for(i = 0; definition[i].key != -1; i++){
    	if(definition[i].key){
    		*v = (BiTree)malloc(sizeof(BiTNode));
    		if(!*v) return OVERFLOW;
    		(*v)->data.key = definition[i].key;
    		strcpy((*v)->data.others, definition[i].others);
    		(*v)->lchild = (*v)->rchild = NULL;
    		stack[++top] = *v;
    		v = &((*v)->lchild);
		}else{
			if(top >= 0){
				v = &(stack[top]->rchild);
				top--;
			}
		}
	}
	return OK;
}

status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    if(T){
        if(T->lchild) ClearBiTree(T->lchild);
        if(T->rchild) ClearBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    return OK;
}

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    if(!T) return 0;
    int l = BiTreeDepth(T->lchild), r = BiTreeDepth(T->rchild);
    return l > r ? l+1 : r+1;
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    if(!T) return NULL;
    else if(T->data.key == e) return T;
    else{
        BiTree p;
        if(p = LocateNode(T->lchild, e)) return p;
        if(p = LocateNode(T->rchild, e)) return p;
        return NULL;
    }
}

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值
{
    if(e != value.key && LocateNode(T, value.key) || !LocateNode(T, e)) return ERROR;
    if(!T) return ERROR;
    BiTree v = LocateNode(T, e);
    v->data = value;
    return OK;
}

BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    if(!T || !T->lchild && !T->rchild) return NULL;
    if(T->lchild && T->lchild->data.key == e) return T->rchild;
    else if(T->rchild && T->rchild->data.key == e) return T->lchild;
    BiTree p;
    if(p = GetSibling(T->lchild, e)) return p;
    if(p = GetSibling(T->rchild, e)) return p;
    return NULL;
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点
/*根据LR为0或者1，插入结点c到T中，作为关键字为e的结点的左或右孩子结点，结点e的原有左子树或右子树则为结点c的右子树，返回OK。如果插入失败，返回ERROR。
特别地，当LR为-1时，作为根结点插入，原根结点作为c的右子树。
*/
{
    if(LocateNode(T, c.key)) return INFEASIBLE;
    BiTree v, pre, pc;
    if(!(pc = (BiTree)malloc(sizeof(BiTNode)))) return OVERFLOW;
    pc->data = c;
    pc->lchild = pc->rchild = NULL;
    if(LR == -1){
        v = T;
        T = pc;
        T->rchild = v;
        return OK;
    }else if(!(pre = LocateNode(T, e))) return ERROR;
    if(!LR){
        v = pre->lchild;
        pre->lchild = pc;
        pc->rchild = v;
        return OK;
    }else{
        v = pre->rchild;
        pre->rchild = pc;
        pc->rchild = v;
        return OK;
    }
}

BiTNode* LocateParentNode(BiTree T,KeyType e)
//查找父母结点
{
    if(!T || !T->lchild && !T->rchild) return NULL;
    else if(T->lchild && T->lchild->data.key == e || T->rchild && T->rchild->data.key == e) return T;
    else{
        BiTree p;
        if(p = LocateParentNode(T->lchild, e)) return p;
        if(p = LocateParentNode(T->rchild, e)) return p;
        return NULL;
    }
}

status DeleteNode(BiTree &T,KeyType e)
/*删除结点。如果关键字为e的结点度为0，删除即可；
如关键字为e的结点度为1，用关键字为e的结点孩子代替被删除的e位置；
如关键字为e的结点度为2，用e的左孩子代替被删除的e位置，e的右子树作为e的左子树中最右结点的右子树。
成功删除结点后返回OK，否则返回ERROR。*/
{
    BiTree p, v, u, pc;
    if(T->data.key == e){
        pc = T;
        if(!T->lchild) T = T->rchild;
        else if(!T->rchild) T = T->lchild;
        else{
            v = T->rchild;
            u = T = T->lchild;
            while(u->rchild) u = u->rchild;
            u->rchild = v;
        }
        free(pc);
        pc = NULL;
        return OK;
    }
    if(!(p = LocateParentNode(T, e))) return ERROR;
    if(p->lchild->data.key == e){
        pc = p->lchild;
        if(!pc->lchild){
            v = pc->rchild;
            p->lchild = v;
        }else if(!pc->rchild){
            v = pc->lchild;
            p->lchild = v;
        }else{
            u = pc->lchild;
            v = pc->rchild;
            p->lchild = u;
            while(u->rchild) u = u->rchild;
            u->rchild = v;
        }
    }else{
        pc = p->rchild;
        if(!pc->lchild){
            v = pc->rchild;
            p->rchild = v;
        }else if(!pc->rchild){
            v = pc->lchild;
            p->rchild = v;
        }else{
            u = pc->lchild;
            v = pc->rchild;
            p->rchild = u;
            while(u->rchild) u = u->rchild;
            u->rchild = v;
        }
    }
    free(pc);
    pc = NULL;
    return OK;
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    BiTree stack[1000], v = T;
    int top = -1;
    while(v || top != -1){
        if(v){
            visit(v);
            stack[++top] = v;
            v = v->lchild;
        }else{
            if(top >= 0) v = stack[top--]->rchild;
        }
    }
    return OK;
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    if(T->lchild) InOrderTraverse(T->lchild, visit);
    visit(T);
    if(T->rchild) InOrderTraverse(T->rchild, visit);
    return OK;
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    if(T->lchild) PostOrderTraverse(T->lchild, visit);
    if(T->rchild) PostOrderTraverse(T->rchild, visit);
    visit(T);
    return OK;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    BiTree stage[1000];
    int head = 0, tail = 0;
    if(T) stage[tail++] = T;
    while(head < tail){
        if(stage[head]->lchild) stage[tail++] = stage[head]->lchild;
        if(stage[head]->rchild) stage[tail++] = stage[head]->rchild;
        head++;
    }
    for(int i = 0; i < tail; i++) visit(stage[i]);
    return OK;
}

status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    FILE *fp;
    if(!(fp = fopen(FileName, "w"))) return ERROR;
    BiTree stack[1000], v = T;
    int top = -1;
    while(v || top != -1){
        if(v){
            fprintf(fp, "%d %s ", v->data.key, v->data.others);
            stack[++top] = v;
            v = v->lchild;
        }else{
            fprintf(fp, "0 null ");
            if(top >= 0) v = stack[top--]->rchild;
        }
    }
    fclose(fp);
    return OK;
}

status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    FILE *fp;
    if(!(fp = fopen(FileName, "r"))) return ERROR;
	BiTree *v = &T, stack[1000]; 
    KeyType key;
    char others[30];
    int top = -1;
    for(; fscanf(fp, "%d%s", &key, others) != EOF; ){
    	if(key){
    		*v = (BiTree)malloc(sizeof(BiTNode));
    		if(!*v) return OVERFLOW;
    		(*v)->data.key = key;
    		strcpy((*v)->data.others, others);
    		(*v)->lchild = (*v)->rchild = NULL;
    		stack[++top] = *v;
    		v = &((*v)->lchild);
		}else{
			if(top >= 0){
				v = &(stack[top]->rchild);
				top--;
			}
		}
	}
    fclose(fp);
	return OK;
}

void visit(BiTree T)
{
//遍历时使用的visit函数 
    printf("%d, %s\n", T->data.key, T->data.others);
}

int MaxPathSum(BiTree T)
//二叉树T存在, 返回根节点到叶子结点的最大路径和
{
	if(!T->lchild && !T->rchild) return T->data.key;
	else{
		if(!T->lchild) return T->data.key+MaxPathSum(T->rchild);
		else if(!T->rchild) return T->data.key+MaxPathSum(T->lchild);
		else return T->data.key+(MaxPathSum(T->lchild) > MaxPathSum(T->rchild) ? MaxPathSum(T->lchild) : MaxPathSum(T->rchild));
	}
}

BiTree LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2)
//二叉树T存在，返回该二叉树中e1节点和e2节点的最近公共祖先
//若e1和e2存在公共祖先，它们一定分居公共祖先的左侧和右侧（或者存在祖孙关系） 
{
	if(!T) return NULL;
	if(T->data.key == e1 || T->data.key == e2) return T;
	BiTree l, r;
	l = LowestCommonAncestor(T->lchild, e1, e2);
	r = LowestCommonAncestor(T->rchild, e1, e2);
	if(!l && !r) return NULL;
	else if(l && !r) return l;
	else if(!l && r) return r;
	else return T;
}

status InvertTree(BiTree T)
//将二叉树T翻转，使其所有节点的左右节点互换
{
	if(!T || !T->lchild && !T->rchild) return OK;
	else{
		BiTree v = T->lchild;
		T->lchild = T->rchild;
		T->rchild = v;
		InvertTree(T->lchild);
		InvertTree(T->rchild);
		return OK;
	}
}

//以下为二叉树组管理函数 

status InitList(TreeList &L)
//初始化二叉树组 
{
	if(L.elem) return INFEASIBLE;
	L.elem = (ListElem*)malloc(sizeof(ListElem) * LISTSIZE);
	if(!L.elem) return OVERFLOW;
	L.length = 0, L.listsize = LISTSIZE;
	return OK;
}

status DestroyList(TreeList &L)
//删除二叉树组
{
	if(!L.elem) return INFEASIBLE;
	free(L.elem);
	L.elem = NULL;
	return OK;
}

status AddTree(TreeList &L, char name[])
//向二叉树组L中添加名为name的二叉树 
{
	if(L.length >= L.listsize) return OVERFLOW;
	L.elem[L.length].root = NULL;
	strcpy(L.elem[L.length].name, name);
	L.length++;
	return OK;
}

int LocateTree(TreeList L, char name[])
//在二叉树组L中查找名为name的二叉树 
{
	int i;
	for(i = 0; i < L.length; i++)
		if(!strcmp(L.elem[i].name, name)) return i+1;
	return 0;
}

status DeleteTree(TreeList &L, char name[])
//在二叉树组L中删除名为name的二叉树
{
	int i = LocateTree(L, name);
	if(!i) return ERROR;
	if(ClearBiTree(L.elem[i-1].root) != OK) return INFEASIBLE;
	ListElem temp;
	for(int j = i-1; j < L.length-1; j++) L.elem[j] = L.elem[j+1];
	L.length--;
	return OK;
} 
