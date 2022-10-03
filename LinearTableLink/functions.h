#define LISTS_INIT_SIZE 50
#define LISTS_INCREMENT 10

status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L) return INFEASIBLE;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList lp = L;
    while(L != NULL){
        lp = lp->next;
        free(L);
        L = lp;
    }
    return OK;    
}


status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList lp = L->next, lq;
    while(lp != NULL){
        lq = lp->next;
        free(lp);
        lp = lq;
    }
    L->next = NULL;
    return OK;
}

status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    if(!L->next) return TRUE;
    return FALSE;
}

int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    int i;
    LinkList lp = L->next;
    for(i = 0; lp; lp = lp->next, i++);
    return i;
}

status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    if(i <= 0) return ERROR;
    int j;
    LinkList lp = L->next;
    for(j = 1; lp; lp = lp->next, j++){
        if(j == i){
            e = lp->data;
            return OK;
        }
    }
    return ERROR;
}

int LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList lp = L->next;
    for(int i = 1; lp; lp = lp->next, i++){
        if(lp->data == e) return i;
    }
    return ERROR;
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList lp = L->next, lq = L;
    if(!lp || lp->data == e) return ERROR;
    while(lp && lp->data != e){
        lp = lp->next;
        lq = lq->next;
    }
    if(lp){
        pre = lq->data;
        return OK;
    }else return ERROR;
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList lp = L->next;
    while(lp && lp->data != e) lp = lp->next;
    if(lp && lp->next){
        next = lp->next->data;
        return OK;
    }else return ERROR;
}

status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    if(i <= 0) return ERROR;
    LinkList LP = (LinkList)malloc(sizeof(LNode));
    LP->data = e;
    LinkList lp, lq;
    lp = L->next;
    if(i == 1){
        L->next = LP;
        LP->next = lp;
        return OK;
    }else{
        int j;
        for(j = 1; j != i-1 && lp->next; lp = lp->next, j++);
        if(j == i-1){
            lq = lp->next;
            lp->next = LP;
            LP->next = lq;
            return OK;
        }else return ERROR;
    }
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    int j;
    LinkList p = L->next, q = L;
    for(j = 1; j != i && p->next; j++, p = p->next, q = q->next);
    if(j == i){
        e = p->data;
        q->next = p->next;
        free(p);
        return OK;
    }
    return ERROR;
}

status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p = L->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    return OK;
}

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    FILE *fp;
    if((fp = fopen(FileName, "w")) == NULL) return ERROR;
    LinkList p = L->next;
    while(p){
        fprintf(fp, "%d ", p->data);
        p = p->next;
    }
    fclose(fp);
    return OK;
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L为空，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if(!L || L->next) return INFEASIBLE;
    LinkList p = (LinkList)malloc(sizeof(LNode)), t = L;
    FILE *fp;
    if((fp = fopen(FileName, "r")) == NULL) return ERROR;
    while(fscanf(fp, "%d", &p->data) != EOF){
        t->next = p;
        t = p;
        p = (LinkList)malloc(sizeof(LNode));
    }
    t->next = NULL;
    free(p);
    fclose(fp);
    return OK;
}

status InitLists(LLT &L)
{
//如果线性表组L不存在，初始化L并返回OK，若已存在则返回INFEASIBLE 
	if(L.elem) return INFEASIBLE;
	if((L.elem = (LinkElem*)malloc(LISTS_INIT_SIZE*sizeof(LinkElem))) == NULL) return ERROR;
	L.length = 0;
	L.listsize = LISTS_INIT_SIZE;
	return OK;
}

status DestroyLists(LLT &L)
{
//如果线性表组L存在，将其删除并返回OK，若不存在则返回INFEASIBLE 
	if(!L.elem) return INFEASIBLE;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

status AddList(LLT &L, char name[])
{
//向线性表组L中添加一个名为name的链表，并返回OK 
	if(!L.elem) return INFEASIBLE;
	for(int i = 0; i < L.length; i++)
		if(!strcmp(name, L.elem[i].name)) return OVERFLOW;
	if(L.length == L.listsize){
		L.elem = (LinkElem*)realloc(L.elem, sizeof(LinkElem) * (L.listsize+LISTS_INCREMENT));
		if(!L.elem) return ERROR;
	}
	strcpy(L.elem[L.length].name, name);
	L.elem[L.length].L = NULL;
	InitList(L.elem[L.length].L);
	L.length++;
	return OK;
}

status RemoveList(LLT &Lists, char name[])
{
//删除线性表组Lists中名为name的链表，返回OK，若不存在名为name的表，返回ERROR 
	if(!Lists.elem) return INFEASIBLE;
	for(int i = 0; i < Lists.length; i++){
		if(!strcmp(name, Lists.elem[i].name)){
			DestroyList(Lists.elem[i].L);
			for(int j = i; j < Lists.length-1; j++) Lists.elem[j] = Lists.elem[j+1];
			Lists.length--;
			return OK;
		}
	}
	return ERROR;
}

int LocateList(LLT &Lists, char name[])
{
//查找线性表组Lists中名为name的链表，返回其逻辑序号，若不存在名为name的表，返回ERROR 
	if(!Lists.elem) return INFEASIBLE;
	for(int i = 0; i < Lists.length; i++)
		if(!strcmp(name, Lists.elem[i].name)) return i+1;
	return ERROR;
}

status ReverseList(LinkList &L)
{
//若线性表L已存在，将L翻转，返回OK 
	if(!L) return INFEASIBLE; //链表不存在时，返回INFEASIBLE
	LinkList p = L->next, q = NULL, r;
	if(p){
		q = p->next;
		p->next = NULL;
		L->next = p;
	} //翻转第一个节点，即使L->next的next指向NULL，标记原后继 
	while(q){
		r = q->next; //标记q的后继 
		q->next = p; //p是q的前驱，翻转q 
		L->next = q; //更新头节点 
		p = q;
		q = r; //向后继续 
	}
	return OK;
}

status RemoveNthFromEnd(LinkList &L, int n)
{
//若线性表L存在，删除其倒数第n个节点，返回OK，若n不合法，返回ERROR 
	if(!L) return INFEASIBLE;
	if(!L->next) return ERROR; //若线性表为空，则n必定不合法 
	LinkList p = L->next, q = L->next, r = L;
	for(int i = 1; i < n; i++){
		if(!q->next) return ERROR;
		q = q->next; //p和q之间有n-1的间隔 
	}
	while(q->next) p = p->next, q = q->next, r = r->next; //r是q的前驱 
	if(L->next == p){ //如果需要删除的是第一个 
		L->next = p->next;
		free(p);
		p = NULL;
	}else{
		r->next = p->next;
		free(p);
		p = NULL;
	}
	return OK;
}

status SortList(LinkList &L)
{
//若线性表L存在，将L中的数据升序排序
	if(!L) return INFEASIBLE; 
	LinkList p, q;
	ElemType temp; //交换数据域 
	for(p = L->next; p->next; p = p->next){
		for(q = p; q; q = q->next){
			if(p->data > q->data){
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
	return OK;
}
