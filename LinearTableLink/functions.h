#define LISTS_INIT_SIZE 50
#define LISTS_INCREMENT 10

status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(L) return INFEASIBLE;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    if(!L->next) return TRUE;
    return FALSE;
}

int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    int i;
    LinkList lp = L->next;
    for(i = 0; lp; lp = lp->next, i++);
    return i;
}

status GetElem(LinkList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList lp = L->next;
    for(int i = 1; lp; lp = lp->next, i++){
        if(lp->data == e) return i;
    }
    return ERROR;
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�LΪ�գ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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
//������Ա���L�����ڣ���ʼ��L������OK�����Ѵ����򷵻�INFEASIBLE 
	if(L.elem) return INFEASIBLE;
	if((L.elem = (LinkElem*)malloc(LISTS_INIT_SIZE*sizeof(LinkElem))) == NULL) return ERROR;
	L.length = 0;
	L.listsize = LISTS_INIT_SIZE;
	return OK;
}

status DestroyLists(LLT &L)
{
//������Ա���L���ڣ�����ɾ��������OK�����������򷵻�INFEASIBLE 
	if(!L.elem) return INFEASIBLE;
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

status AddList(LLT &L, char name[])
{
//�����Ա���L�����һ����Ϊname������������OK 
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
//ɾ�����Ա���Lists����Ϊname����������OK������������Ϊname�ı�����ERROR 
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
//�������Ա���Lists����Ϊname�������������߼���ţ�����������Ϊname�ı�����ERROR 
	if(!Lists.elem) return INFEASIBLE;
	for(int i = 0; i < Lists.length; i++)
		if(!strcmp(name, Lists.elem[i].name)) return i+1;
	return ERROR;
}

status ReverseList(LinkList &L)
{
//�����Ա�L�Ѵ��ڣ���L��ת������OK 
	if(!L) return INFEASIBLE; //��������ʱ������INFEASIBLE
	LinkList p = L->next, q = NULL, r;
	if(p){
		q = p->next;
		p->next = NULL;
		L->next = p;
	} //��ת��һ���ڵ㣬��ʹL->next��nextָ��NULL�����ԭ��� 
	while(q){
		r = q->next; //���q�ĺ�� 
		q->next = p; //p��q��ǰ������תq 
		L->next = q; //����ͷ�ڵ� 
		p = q;
		q = r; //������ 
	}
	return OK;
}

status RemoveNthFromEnd(LinkList &L, int n)
{
//�����Ա�L���ڣ�ɾ���䵹����n���ڵ㣬����OK����n���Ϸ�������ERROR 
	if(!L) return INFEASIBLE;
	if(!L->next) return ERROR; //�����Ա�Ϊ�գ���n�ض����Ϸ� 
	LinkList p = L->next, q = L->next, r = L;
	for(int i = 1; i < n; i++){
		if(!q->next) return ERROR;
		q = q->next; //p��q֮����n-1�ļ�� 
	}
	while(q->next) p = p->next, q = q->next, r = r->next; //r��q��ǰ�� 
	if(L->next == p){ //�����Ҫɾ�����ǵ�һ�� 
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
//�����Ա�L���ڣ���L�е�������������
	if(!L) return INFEASIBLE; 
	LinkList p, q;
	ElemType temp; //���������� 
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
