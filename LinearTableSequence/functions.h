#include <string.h>

status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L.elem != NULL) return INFEASIBLE;
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(L.elem == NULL) return INFEASIBLE;
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    return OK;
}


status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(L.elem == NULL) return INFEASIBLE;
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L.elem) return INFEASIBLE;
    if(!L.length) return TRUE;
    else return FALSE;
}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(!L.elem) return INFEASIBLE;
    else return L.length;
}

status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L.elem) return INFEASIBLE;
    if(i > L.length || i <= 0) return ERROR;
    else{
        e = L.elem[i-1];
        return OK;
    }
}

int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE。 
{
    if(!L.elem) return INFEASIBLE;
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] == e) return i+1;
    }
    return 0;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
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
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
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
// 当Lists不存在时，创建LISTS并初始化 
{
	if(Lists.elem) return INFEASIBLE;
	Lists.elem = ((SqElem*)malloc(sizeof(SqElem) * LISTS_INIT_SIZE));
	Lists.length = 0;
	Lists.listsize = LISTS_INIT_SIZE;
	return OK;
}

status DestroyLists(LISTS &Lists)
// 当Lists不存在时，创建LISTS并初始化 
{
	if(!Lists.elem) return INFEASIBLE;
	free(Lists.elem);
	Lists.length = 0;
	Lists.listsize = LISTS_INIT_SIZE;
	Lists.elem = NULL;
	return OK;
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    if(Lists.length >= Lists.listsize) return OVERFLOW;
	strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.length++;
    Lists.elem[Lists.length-1].L.elem = NULL;
    InitList(Lists.elem[Lists.length-1].L);
    return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
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
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    for(int i = 0; i < Lists.length; i++)
        if(!strcmp(Lists.elem[i].name, ListName)) return i+1;
    return 0;
}

int MaxSubArray(SqList &L)
// 线性表L已存在且非空，找出具有最大和的连续子数组（子数组最少包含一个元素），操作结果是其最大和
{
	if(!L.elem || !L.length) return INFEASIBLE;
	int i = 0, nowmax = 0, max = 0;
	//动态规划，nowmax表示当前以L.elem[i]结尾的子表的和的最大值，nowmax = max{nowmax + L.elem[i], L.max}
	//最终结果是所有出现过的nowmax中的最大值 
	while(i < L.length){
		nowmax = L.elem[i] > L.elem[i]+nowmax ? L.elem[i] : L.elem[i] + nowmax;
		if(nowmax > max) max = nowmax;
		i++;
	}
	return max;
}

int SubArrayNum(SqList &L, int k)
// 线性表L已存在且非空, 操作结果是该数组中和为k的连续子数组的个数
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
// 线性表L已存在；操作结果是将L由小到大排序
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
