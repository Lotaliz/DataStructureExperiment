#include <string.h>

status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem != NULL) return INFEASIBLE;
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if(L.elem == NULL) return INFEASIBLE;
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    return OK;
}


status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem == NULL) return INFEASIBLE;
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(!L.length) return TRUE;
    else return FALSE;
}

status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    else return L.length;
}

status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(i > L.length || i <= 0) return ERROR;
    else{
        e = L.elem[i-1];
        return OK;
    }
}

int LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE�� 
{
    if(!L.elem) return INFEASIBLE;
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] == e) return i+1;
    }
    return 0;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(L.elem[0] == e) return ERROR;
    for(int i = 0, j = -1; i < L.length; i++, j++){
        if(L.elem[i] == e){
            pre = L.elem[j];
            return OK;
        }
    }
    return ERROR;
}

status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(L.elem[L.length-1] == e) return ERROR;
    for(int i = L.length, j = L.length-1; j >= 0; i--, j--){
        if(L.elem[j] == e){
            next = L.elem[i];
            return OK;
        }
    }
    return ERROR;
}

status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(L.length == L.listsize){
        L.elem = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if(!L.elem) return ERROR;
        L.listsize += LISTINCREMENT;
    }
    if(i <= 0 || i > L.length+1) return ERROR;
    for(int j = L.length-1; j >= i-1; j--)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(i <= 0 || i > L.length) return ERROR;
    e = L.elem[i-1];
    for(int j = i-1; j < L.length-1; j++)
        L.elem[j] = L.elem[j+1];
    L.length--;
    return OK;
}

status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    if(!L.length) return ERROR;
    else{
        for(int i = 0; i < L.length; i++)
            printf("%d ", L.elem[i]);
    }
    printf("\n");
    return OK;
}

status SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    FILE *fp;
    if((fp = fopen(FileName, "w")) == NULL) return ERROR;
    for(int i = 0; i < L.length; i++)
        fprintf(fp, "%d ", L.elem[i]);
    fclose(fp);
    return OK;
}

status LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if(!L.elem) return INFEASIBLE;
    FILE *fp;
    ElemType temp;
    if((fp = fopen(FileName, "r")) == NULL) return ERROR;
    while(1){
        if((fscanf(fp, "%d", &temp)) == EOF) break;
        if(L.length == L.listsize){
            L.elem = (ElemType*)realloc(L.elem, (sizeof(ElemType)*(L.listsize+LISTINCREMENT)));
            if(!L.elem) return ERROR;
            L.listsize += LISTINCREMENT;
        }
        L.elem[L.length] = temp;
        L.length++;
    }
    fclose(fp);
    return OK;
}

status InitLists(LISTS &Lists)
// ��Lists������ʱ������LISTS����ʼ�� 
{
	if(Lists.elem) return INFEASIBLE;
	Lists.elem = ((SqElem*)malloc(sizeof(SqElem) * LISTS_INIT_SIZE));
	Lists.length = 0;
	Lists.listsize = LISTS_INIT_SIZE;
	return OK;
}

status DestroyLists(LISTS &Lists)
// ��Lists������ʱ������LISTS����ʼ�� 
{
	if(!Lists.elem) return INFEASIBLE;
	free(Lists.elem);
	Lists.length = 0;
	Lists.listsize = LISTS_INIT_SIZE;
	Lists.elem = NULL;
	return OK;
}

status AddList(LISTS &Lists,char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
    if(Lists.length >= Lists.listsize) return OVERFLOW;
	strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.length++;
    Lists.elem[Lists.length-1].L.elem = NULL;
    InitList(Lists.elem[Lists.length-1].L);
    return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
    for(int i = 0; i < Lists.length; i++){
        if(!strcmp(Lists.elem[i].name, ListName)){
            for(int j = i; j < Lists.length-1; j++)
                Lists.elem[j] = Lists.elem[j+1];
            Lists.length--;
            return OK;
        }
    }
    return ERROR;
}

int LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
    for(int i = 0; i < Lists.length; i++)
        if(!strcmp(Lists.elem[i].name, ListName)) return i+1;
    return 0;
}

int MaxSubArray(SqList &L)
// ���Ա�L�Ѵ����ҷǿգ��ҳ��������͵����������飨���������ٰ���һ��Ԫ�أ������������������
{
	if(!L.elem || !L.length) return INFEASIBLE;
	int i = 0, nowmax = 0, max = 0;
	//��̬�滮��nowmax��ʾ��ǰ��L.elem[i]��β���ӱ�ĺ͵����ֵ��nowmax = max{nowmax + L.elem[i], L.max}
	//���ս�������г��ֹ���nowmax�е����ֵ 
	while(i < L.length){
		nowmax = L.elem[i] > L.elem[i]+nowmax ? L.elem[i] : L.elem[i] + nowmax;
		if(nowmax > max) max = nowmax;
		i++;
	}
	return max;
}

int SubArrayNum(SqList &L, int k)
// ���Ա�L�Ѵ����ҷǿ�, ��������Ǹ������к�Ϊk������������ĸ���
{
	if(!L.elem) return INFEASIBLE;
	int sum, cnt = 0;
	for(int i = 1; i < L.length; i++){
		sum = 0;
		for(int j = i; j < L.length; j++){
			sum += L.elem[j];
			if(sum == k) cnt++;
		}
	}
	return cnt;
}

status SortList(SqList &L)
// ���Ա�L�Ѵ��ڣ���������ǽ�L��С��������
{
	if(!L.elem) return INFEASIBLE;
	ElemType temp;
	for(int i = 0; i < L.length-1; i++){
		for(int j = i; j < L.length; j++){
			if(L.elem[i] > L.elem[j]){
				temp = L.elem[i];
				L.elem[i] = L.elem[j];
				L.elem[j] = temp;
			}
		}
	}
	return OK;
}
