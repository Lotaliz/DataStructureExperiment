#include "def.h"

int FindIndex(ALGraph G, KeyType k)
//���ݽ��Ĺؼ���k������λ�򲢷��أ�����ʧ���򷵻�-1 
{
	for(int i = 0; i < G.vexnum; i++){
		if(G.vertices[i].data.key == k) return i;
	}
	return -1;
}

void visit(VertexType V)
//����ʱ���õķ��ʺ��� 
{
	printf("%d %s ", V.key, V.others);
}

status CreateNet(ALGraph &G, VertexType V[], NetType N[])
/*����V��N������G������OK�����V��N����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR��*/
{
	G.kind = UDN;
	G.arcnum = G.vexnum = 0;
	if(V[0].key == -1) return INFEASIBLE;
	ArcNode *p;
	int flag, v1, v2;
	for(int i = 0; V[i+1].key != -1; i++){  //�����Ƿ����ظ��ؼ��ֻ򳬳���Χ�Ľ������ 
        if(i+1 >= MAX_VERTEX_NUM) return ERROR;
		for(int j = i+1; V[j].key != -1; j++) 
			if(V[i].key == V[j].key) return ERROR;
	}
	for(int i = 0; V[i].key != -1; i++){
		G.vertices[i].data = V[i];
		G.vertices[i].firstarc = NULL;
		G.vexnum++;
	}
	for(int i = 0; N[i].v1 != -1; i++){
		v1 = FindIndex(G, N[i].v1), v2 = FindIndex(G, N[i].v2);
		if(v1 == -1 || v2 == -1) return ERROR;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v2;
		p->distance = N[i].weight;
		if(!G.vertices[v1].firstarc) p->nextarc = NULL;
		else p->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p;
		
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v1;
		p->distance = N[i].weight;
		if(!G.vertices[v1].firstarc) p->nextarc = NULL;
		else p->nextarc = G.vertices[v2].firstarc;
		G.vertices[v2].firstarc = p;
		
		G.arcnum++;
	}
	return OK;
}

status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*����V��VR����ͼG������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR��*/
{
	G.kind = UDG; 
	G.arcnum = G.vexnum = 0;
	if(V[0].key == -1) return INFEASIBLE;
	ArcNode *p;
	int flag, v1, v2;
	for(int i = 0; V[i+1].key != -1; i++){
        if(i+1 >= MAX_VERTEX_NUM) return ERROR;
		for(int j = i+1; V[j].key != -1; j++) 
			if(V[i].key == V[j].key) return ERROR;
	}
	for(int i = 0; V[i].key != -1; i++){
		G.vertices[i].data = V[i];
		G.vertices[i].firstarc = NULL;
		G.vexnum++;
	}
	for(int i = 0; VR[i][0] != -1; i++){
		v1 = FindIndex(G, VR[i][0]), v2 = FindIndex(G, VR[i][1]);
		if(v1 == -1 || v2 == -1) return ERROR;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v2;
		p->distance = 1;
		if(!G.vertices[v1].firstarc) p->nextarc = NULL;
		else p->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p;
		
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v1;
		p->distance = 1;
		if(!G.vertices[v1].firstarc) p->nextarc = NULL;
		else p->nextarc = G.vertices[v2].firstarc;
		G.vertices[v2].firstarc = p;
		
		G.arcnum++;
	}
	return OK;
}

status DestroyGraph(ALGraph &G)
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
{
    ArcNode *p, *q;
    for(int i = 0; i < G.vexnum; i++){
    	p = G.vertices[i].firstarc;
    	if(!p) continue;
    	while(p){
    		q = p->nextarc;
    		free(p);
    		p = q;
		}
	}
	G.arcnum = G.vexnum = 0;
	return OK;
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
	for(int i = 0; i < G.vexnum; i++)
		if(G.vertices[i].data.key == value.key) return ERROR;
	for(int i = 0; i < G.vexnum; i++){
		if(G.vertices[i].data.key == u){
			G.vertices[i].data = value;
			return OK;
		}
	}
	return ERROR;
}

int FirstAdjVex(ALGraph G,KeyType u)
//���ݹؼ���u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
    for(int i = 0; i < G.vexnum; i++){
    	if(G.vertices[i].data.key == u){
    		if(G.vertices[i].firstarc) return G.vertices[i].firstarc->adjvex;
    		else return -1;
		}
	}
	return -1;
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//���ݹؼ���u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
{
    ArcNode *p;
	for(int i = 0; i < G.vexnum; i++){
    	if(G.vertices[i].data.key == v){
    		p = G.vertices[i].firstarc;
    		if(p){
    			while(p->nextarc){
    				if(G.vertices[p->adjvex].data.key == w){
    					if(p->adjvex) return p->nextarc->adjvex;
    					else return -1;
					}
					p = p->nextarc;
				}    			
			}
		}
	}
	return -1;
}

int FirstAdjVex1(ALGraph G, int v)
//����λ��v��ͼG�в��Ҷ��㣬���ҳɹ����ض���v�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
    if(v >= 0 && v < G.vexnum && G.vertices[v].firstarc) return G.vertices[v].firstarc->adjvex;
	else return -1;
}

int NextAdjVex1(ALGraph G, int v, int w)
//����λ��v��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
{
    ArcNode *p;
	if(v >= 0 && v < G.vexnum){
    	p = G.vertices[v].firstarc;
    	while(p){
    		if(p->adjvex == w){
    			if(p->nextarc) return p->nextarc->adjvex;
    			else return -1;
    		}
			p = p->nextarc;
		}
	}
	return -1;
}


status InsertVex(ALGraph &G,VertexType v)
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
	if(FindIndex(G, v.key) != -1) return ERROR;
	if(G.vexnum >= MAX_VERTEX_NUM) return OVERFLOW;
	G.vertices[G.vexnum].data = v;
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
	return OK;
}

status DeleteVex(ALGraph &G,KeyType v)
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
	if(G.vexnum < 1) return ERROR;
	ArcNode *p, *q, *r;
    int idx;
	for(int i = 0; i < G.vexnum; i++){
    	if(G.vertices[i].data.key == v){
    		p = G.vertices[i].firstarc;
    		while(p){
    			idx = p->adjvex;
    			q = p->nextarc;
    			free(p);
    			p = q;
    			r = G.vertices[idx].firstarc;
    			if(G.vertices[r->adjvex].data.key == v){    				
    				G.vertices[idx].firstarc = r->nextarc;
    				free(r);
    				r = NULL;
				}else{
					while(G.vertices[r->nextarc->adjvex].data.key != v) r = r->nextarc;
					q = r->nextarc;
					r->nextarc = r->nextarc->nextarc;
					free(q);
					q = NULL;
				}
				G.arcnum--;
			}
			for(int j = i; j < G.vexnum-1; j++)
				G.vertices[j] = G.vertices[j+1];
			G.vexnum--;
			for(int j = 0; j < G.vexnum; j++){
				p = G.vertices[j].firstarc;
				while(p){
					if(p->adjvex > i) p->adjvex--;
					p = p->nextarc; 
				}
			}
			return OK;
		}
	}
	return ERROR;
}

status InsertArc(ALGraph &G,KeyType v,KeyType w, int dis)
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    int v1, v2;
    ArcNode *p, *q;
	v1 = FindIndex(G, v), v2 = FindIndex(G, w);
	if(v1 == -1 || v2 == -1) return INFEASIBLE;
	p = G.vertices[v1].firstarc;
	q = (ArcNode*)malloc(sizeof(ArcNode));
	q->adjvex = v2;
	if(dis) q->distance = dis;
	else q->distance = 1;
	q->nextarc = p;
	G.vertices[v1].firstarc = q;
	
	q = (ArcNode*)malloc(sizeof(ArcNode));
	q->adjvex = v1;
	q->nextarc = G.vertices[v2].firstarc;
	if(dis) q->distance = dis;
	else q->distance = 1;
	G.vertices[v2].firstarc = q;
	
	G.arcnum++;
	return OK;
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
    int v1, v2, flag = 1;
    ArcNode *p, *q;
	v1 = FindIndex(G, v), v2 = FindIndex(G, w);
	if(v1 == -1 || v2 == -1) return INFEASIBLE;
	p = q = G.vertices[v1].firstarc;
	if(p->adjvex == v2){
		flag = 0;
		G.vertices[v1].firstarc = p->nextarc;
		free(p);
		p = NULL;
	}else{
		p = p->nextarc;
		while(p){
			if(p->adjvex == v2){
				flag = 0;
				q->nextarc = p->nextarc;
				free(p);
				p = NULL;
				break;
			}else p = p->nextarc, q = q->nextarc;
		}
		if(flag) return ERROR;
	}
	
	p = q = G.vertices[v2].firstarc;
	if(p->adjvex == v1){
		G.vertices[v2].firstarc = p->nextarc;
		free(p);
		p = NULL;
	}else{
		p = p->nextarc;
		while(p){
			if(p->adjvex == v1){
				q->nextarc = p->nextarc;
				free(p);
				p = NULL;
				break;
			}else p = p->nextarc, q = q->nextarc;
		}
	}
	G.arcnum--;
	return OK;
}

void DFS(ALGraph G, int *visited, int v, void(*visit)(VertexType))
//������������ĸ������� 
{
	visited[v] = 1;
	visit(G.vertices[v].data);
	for(int w = FirstAdjVex1(G, v); w >= 0; w = NextAdjVex1(G, v, w))
		if(!visited[w]) DFS(G, visited, w, visit);
}

status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
	int* book = (int*)malloc(sizeof(int) * G.vexnum);
	for(int i = 0; i < G.vexnum; i++) book[i] = 0;
	for(int i = 0; i < G.vexnum; i++)
		if(!book[i]) DFS(G, book, i, visit);
	return OK;
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    int visited[100], queue[100], head = 0, tail = 0, u;
	for(int i = 0; i < G.vexnum; i++) visited[i] = 0;
	for(int v = 0; v < G.vexnum; v++){
		if(!visited[v]){
			visited[v] = 1;
			visit(G.vertices[v].data);
			queue[tail++] = v;
			while(head != tail){
				u = queue[head++];
				for(int w = FirstAdjVex1(G, u); w >= 0; w = NextAdjVex1(G, u, w)){
					if(w == -1) break;
					if(!visited[w]){
						visit(G.vertices[w].data);
						visited[w] = 1;
						queue[tail++] = w;
					}
				}
			}
		}
	}
}

status SaveGraph(ALGraph G, char FileName[])
//��ͼ������д�뵽�ļ�FileName��
{
    FILE *fp;
    ArcNode *p;
    if((fp = fopen(FileName, "w")) == NULL) return ERROR;
    if(G.kind == UDG){
    	for(int i = 0; i < G.vexnum; i++)
    		fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
    	fprintf(fp, "-1 nil ");
    	for(int i = 0; i < G.vexnum; i++){
    		p = G.vertices[i].firstarc;
    		while(p){
    			fprintf(fp, "%d ", p->adjvex);
    			p = p->nextarc;
			}
			fprintf(fp, "-2 ");
		} 
		fprintf(fp, "-1 -1 ");	
	}else if(G.kind == UDN){
		for(int i = 0; i < G.vexnum; i++)
    		fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
    	fprintf(fp, "-1 nil ");
    	for(int i = 0; i < G.vexnum; i++){
    		p = G.vertices[i].firstarc;
    		while(p){
    			fprintf(fp, "%d %d ", p->adjvex, p->distance);
    			p = p->nextarc;
			}
			fprintf(fp, "-2 0 ");
		} 
		fprintf(fp, "-1 -1 ");	
	}
	fclose(fp);
	return OK;
}

status LoadGraph(ALGraph &G, char FileName[], GraphKind k)
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
    FILE *fp;
    if((fp = fopen(FileName, "r")) == NULL) return ERROR;
    G.arcnum = G.vexnum = 0;
    VertexType t;
    ArcNode *p, *q;
    int idx, dis;
	while(1){
    	fscanf(fp, "%d%s", &t.key, t.others);
    	if(t.key == -1) break;
    	G.vertices[G.vexnum].data = t;
    	G.vertices[G.vexnum++].firstarc = NULL;
	}
	for(int i = 0; i < G.vexnum; i++){
		while(1){
			if(k == UDG) fscanf(fp, "%d", &idx);
			else if(k == UDN) fscanf(fp, "%d%d", &idx, &dis);
			if(idx != -2){
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = idx;
				if(k == UDN) p->distance = dis;
				else p->distance = 1;
				p->nextarc = NULL;
				if(!G.vertices[i].firstarc) G.vertices[i].firstarc = p;
				else{
					q = G.vertices[i].firstarc;
					while(q->nextarc) q = q->nextarc;
					q->nextarc = p;
					q = q->nextarc;
				}
				G.arcnum++;
			}else break;
		}
	}
	G.arcnum /= 2;
	fclose(fp);
	return OK;
}

//����Ϊ��ͼ�����Ĺ��ܺ���
status InitGraphs(Graphs &Gs)
{
	if(Gs.elem) return INFEASIBLE;
	Gs.elem = (GraphsElem*)malloc(sizeof(GraphsElem) * MAX_GRAPH_NUM);
	Gs.length = 0;
	Gs.listsize = MAX_GRAPH_NUM;
	return OK;
} 

status DestroyGraphs(Graphs &Gs)
{
	if(!Gs.elem) return INFEASIBLE;
	free(Gs.elem);
	Gs.elem = NULL;
	return OK;
}

status AddGraph(Graphs &Gs, char graphname[])
{
	if(!Gs.elem) return INFEASIBLE;
	if(Gs.length >= Gs.listsize) return OVERFLOW;
	for(int i = 0; i < Gs.length; i++)
		if(!strcmp(Gs.elem[i].name, graphname)) return ERROR;
	strcpy(Gs.elem[Gs.length].name, graphname);
	Gs.elem[Gs.length].G.arcnum = Gs.elem[Gs.length].G.vexnum = 0;
	Gs.length++;
	return OK;
}

int LocateGraph(Graphs &Gs, char graphname[])
{
	if(!Gs.elem) return -1;
	for(int i = 0; i < Gs.length; i++)
		if(!strcmp(Gs.elem[i].name, graphname)) return i+1;
	return 0;
}

status DeleteGraph(Graphs &Gs, char graphname[])
{
	if(!Gs.elem) return INFEASIBLE;
	int i = LocateGraph(Gs, graphname)-1;
	if(i == -1) return ERROR;
	DestroyGraph(Gs.elem[i].G);
	for(int j = i; j < Gs.length-1; j++) Gs.elem[j] = Gs.elem[j+1];
	Gs.length--;
	return OK;
}

//����Ϊ�������ݵĹ��ܺ���
KeyType* VerticesSetLessThanK(ALGraph G, KeyType v, int k)
//ͼG���ڣ���������Ƿ����붥��v����С��k�Ķ��㼯�� 
{
	KeyType *set = (KeyType*)malloc(sizeof(KeyType) * (G.vexnum));
	int dis[G.vexnum], vn = FindIndex(G, v), min, mini;
	if(vn == -1) return NULL;
	for(int i = 0; i < G.vexnum; i++) set[i] = 0, dis[i] = PEAK;
	dis[vn] = 0;
	ArcNode* p = G.vertices[vn].firstarc;
	while(p){
		dis[p->adjvex] = p->distance;
		p = p->nextarc;
	}
	for(int i = 0; i < G.vexnum-1; i++){
		min = PEAK;
		for(int j = 0; j < G.vexnum; j++)
			if(dis[j] != 0 && dis[j] < min && !set[j]) min = dis[j], mini = j;
		set[mini] = 1;
		p = G.vertices[mini].firstarc;
		while(p){
			if(p->distance + min < dis[p->adjvex])
				dis[p->adjvex] = p->distance + min;
			p = p->nextarc;
		}
	}
	for(int i = 0; i < G.vexnum; i++) if(dis[i] >= k) set[i] = 0;
	return set;
}

int ShortestPathLength(ALGraph G, KeyType v, KeyType w)
//ͼG���ڣ���������Ƿ��ض���v�붥��w�����·���ĳ���
{
	int dis[G.vexnum], set[G.vexnum], v1 = FindIndex(G, v), v2 = FindIndex(G, w), min, mini;
	if(v1 == -1 || v2 == -1) return -1;
	for(int i = 0; i < G.vexnum; i++) set[i] = 0, dis[i] = PEAK;
	dis[v1] = 0;
	ArcNode* p = G.vertices[v1].firstarc;
	while(p){
		dis[p->adjvex] = p->distance;
		p = p->nextarc;
	}
	for(int i = 0; i < G.vexnum-1; i++){
		min = PEAK;
		for(int j = 0; j < G.vexnum; j++)
			if(dis[j] != 0 && dis[j] < min && !set[j]) min = dis[j], mini = j;
		set[mini] = 1;
		p = G.vertices[mini].firstarc;
		while(p){
			if(p->distance + min < dis[p->adjvex])
				dis[p->adjvex] = p->distance + min;
			p = p->nextarc;
		}
	}
	if(dis[v2] == PEAK) return -1;
	else return dis[v2];
}

int ConnectedComponentsNums(ALGraph G)
{
	int visited[G.vexnum], queue[G.vexnum+1], head, tail, u, v, cnt = 0;
	for(int i = 0; i < G.vexnum; i++) visited[i] = 0;
	head = tail = 0;
	for(int t = 0; t < G.vexnum; t++)
		if(!visited[t]){
			cnt++;
			v = t;
			if(!visited[v]){
				visited[v] = 1;
				queue[tail++] = v;
				while(head != tail){
					u = queue[head++];
					for(int w = FirstAdjVex1(G, u); w >= 0; w = NextAdjVex1(G, u, w)){
						if(!visited[w]){
							visited[w] = 1;
							queue[tail++] = w;
						}
					}
				}
			}			
		}
	return cnt;	
}
