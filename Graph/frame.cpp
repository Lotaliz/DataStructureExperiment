/* Graph */
#include "functions.h"

int i, op = 1, flag;
status s;
GraphKind k;
VertexType V[MAX_VERTEX_NUM], value;
KeyType VR[MAX_VERTEX_NUM][2], v, w, *set;
NetType N[MAX_VERTEX_NUM];
char filename[255], ch;

int main(){
	Graphs Gs;
	Gs.elem = NULL;
	int op = 1;
	while(op){
		system("cls");	printf("\n\n");
		printf("            Menu for Graph \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitGraphs       4. DeleteGraph\n");
		printf("    	  2. DestroyGraphs    5. LocateGraph\n");
		printf("    	  3. AddGraph         6. OperateGraph \n");
		printf("    	  0. Exit\n");
		printf("    ��ѡ����Ĳ���[0~6]:");
		scanf("%d",&op);
		switch(op){
	    	case 1:
		    	if(InitGraphs(Gs)==OK) printf("ͼ�鴴���ɹ���\n");
				else printf("ͼ�鴴��ʧ�ܣ�\n");
				getchar();
				system("pause");
				break;
	   		case 2:
				if(DestroyGraphs(Gs) == OK) printf("ͼ��ɾ���ɹ���\n");
				else printf("ͼ��ɾ��ʧ�ܣ�\n");
				getchar();				
				system("pause");
				break;
	   		case 3:
				if(!Gs.elem) printf("ͼ�鲻���ڣ�\n"); 
				else{
					printf("������ͼ���ƣ�");
					scanf("%s", filename);
					s = AddGraph(Gs, filename);
					if(s == OK) printf("ͼ��ӳɹ���\n");
					else if(s == ERROR) printf("�Ѵ�����Ϊ %s ��ͼ��\n", filename);
					else printf("���ʧ�ܣ�ͼ��������\n");
				} 
				getchar();
				system("pause");
				break;
	   		case 4:
				if(!Gs.elem) printf("ͼ�鲻���ڣ�\n"); 
				else{
					printf("������Ҫɾ����ͼ����");
					scanf("%s", filename);
					if(DeleteGraph(Gs, filename) == OK) printf("ͼɾ���ɹ���\n");
					else printf("����������Ϊ %s ��ͼ��\n", filename);
				}
				getchar();
				system("pause");
				break;
	   		case 5:
				if(!Gs.elem) printf("ͼ�鲻���ڣ�\n"); 
				else{
					printf("������Ҫ���ҵ�ͼ����");
					scanf("%s", filename);
					i = LocateGraph(Gs, filename);
					if(i) printf("ͼλ�ڵ� %d ����\n", i);
					else printf("����������Ϊ %s ��ͼ��\n", filename);
				}
				getchar();
				system("pause");
				break;
	    	case 6:
				if(!Gs.elem){
					printf("ͼ�鲻���ڣ�\n"); 
					getchar();
					system("pause");
					break;
				}
				else{
					printf("������Ҫ������ͼ����");
					scanf("%s", filename);
					i = LocateGraph(Gs, filename);
					if(i){
						printf("ͼλ�ڵ� %d ����\n", i);
		ALGraph &G = Gs.elem[i-1].G;
		while(op){
						printf("ѡ��������ܣ�\n");
		printf("              Menu for Graph \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateGraph    7. DeleteVex\n");
		printf("    	  2. DestroyGraph   8. InsertArc \n");
		printf("    	  3. PutVex         9. DeleteArc \n");
		printf("    	  4. FirstAdjVex    10. LocateVex\n");
		printf("    	  5. NextAdjVex     11. DFSTraverse \n");
		printf("    	  6. InsertVex      12. BFSTraverse \n");
		printf("\n");
		printf("      Menu for Additional Functions \n");
		printf("    	  13. VerticesSetLessThanK\n");
		printf("    	  14. ShortestPathLength\n");
		printf("    	  15. ConnectedComponentsNums\n");
		printf("    	  16. SaveGraph\n");
		printf("    	  17. LoadList\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~17]:");
		scanf("%d",&op);
		switch(op){
	   		case 1:
	input1: 
				printf("������Ҫ������ͼ���ͣ���Ȩͼ��N����Ȩͼ��G��ȡ����Q��");
				getchar();
				scanf("%c", &ch);
				if(ch == 'n' || ch == 'N'){
					i = 0;
					printf("��������Ĺؼ��ֺ��������Կո�ָ���-1������\n");
					do{
    					scanf("%d%s", &V[i].key, V[i].others);
					}while(V[i++].key != -1);
					printf("����������ӵĶ���Ĺؼ��ֺʹ˱ߵ�Ȩ���Կո�ָ���-1������\n");
					i = 0;
					do{
    					scanf("%d%d%d", &N[i].v1, &N[i].v2, &N[i].weight);
    				}while(N[i++].v1 != -1);
    				if(CreateNet(G, V, N) == OK) printf("��Ȩͼ�����ɹ���\n");
    				else printf("����ʧ�ܣ������Ƿ��ж��ر߻��ظ��ؼ��֣�\n");
				}else if(ch == 'g' || ch == 'G'){
					i = 0;
					printf("��������Ĺؼ��ֺ��������Կո�ָ���-1������\n");
					do{
    					scanf("%d%s", &V[i].key, V[i].others);
					}while(V[i++].key != -1);
					printf("����������ӵĶ���Ĺؼ��֣��Կո�ָ���-1������\n");
					i = 0;
					do{
    					scanf("%d%d", &VR[i][0], &VR[i][1]);
    				}while(VR[i++][0] != -1);
    				if(CreateGraph(G, V, VR) == OK) printf("��Ȩͼ�����ɹ���\n");
    				else printf("����ʧ�ܣ������Ƿ��ж��ر߻��ظ��ؼ��֣�\n");
				}else if(ch == 'q' || ch == 'Q');
				else{
					printf("�����ͼ���Ͳ��Ϸ������������룡\n");
					goto input1;
				}
				getchar();
				system("pause");
				break;
	   		case 2:
				if(DestroyGraph(G) == OK) printf("ͼ�����٣�\n");
				getchar();
				system("pause");
				break;
	   		case 3:
				if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					printf("������Ҫ�޸ĵĽ��ؼ��֣�");
					scanf("%d", &v);
					printf("�������޸ĺ�Ĺؼ��ֺ��������Կո�ָ���\n");
					scanf("%d %s", &value.key, value.others);
					if(PutVex(G, v, value) == OK) printf("����޸ĳɹ���\n");
					else printf("�޸�ʧ�ܣ������Ƿ����ظ��ؼ��ּ�Ŀ��ؼ����Ƿ���ڣ�\n");
				}
				getchar();
				system("pause");
				break;
	    	case 4:
				if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					printf("������Ҫ�����ڽӵĽ��ؼ��֣�");
					scanf("%d", &v);
					i = FirstAdjVex(G, v);
					if(i != -1) printf("%d �ĵ�һ�ڽӽ���λ��Ϊ %d\n", v, i);
					else printf("������ %d �ĵ�һ�ڽӽ�㣡\n", v);
				}
				getchar();
				system("pause");
				break;
	    	case 5:
	    		if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					printf("������Ҫ���ҵĽ��ؼ��ֺ���һ���ڽӽ��Ĺؼ��֣��Կո�ָ���");
					scanf("%d%d", &v, &w);
					i = NextAdjVex(G, v, w);
					if(i != -1) printf("%d ������� %d ����һ�ڽӽ��λ���� %d ��\n", v, w, i);
					else printf("δ�ҵ� %d ������� %d ����һ�ڽӽ�㣡\n", v, w);
				}
				getchar();
				system("pause");
				break;
	    	case 6: 				
				printf("���������Ľ��ؼ��ֺ��������Կո�ָ���\n");
				scanf("%d%s", &value.key, value.others);
				s = InsertVex(G, value);
				if(s == OK) printf("������ɹ���\n");
				else if(s == OVERFLOW) printf("����ʧ�ܣ���������Ѵ����ޣ�\n"); 
				else printf("����ʧ�ܣ��Ѵ��ڹؼ���Ϊ %d �Ľ�㣡\n", v);			
				getchar();
				system("pause");
				break;
	    	case 7:
				if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					printf("������Ҫɾ���Ľ��ؼ��֣�");
					scanf("%d", &v);
					s = DeleteVex(G, v);
					if(s == OK) printf("���ɾ���ɹ���\n");
					else printf("ɾ��ʧ�ܣ������ڹؼ���Ϊ %d �Ľ�㣡\n", v);
				}
				getchar();
				system("pause");
				break;
	    	case 8:
	    		if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					if(G.kind == UDG){
						printf("���������ı������ӵĽ��ؼ��֣��Կո�ָ���");
						scanf("%d%d", &v, &w);
						s = InsertArc(G, v, w, 0);
					}else if(G.kind == UDN){
						printf("���������ı������ӵĽ��ؼ����Լ����룬�Կո�ָ���");
						scanf("%d%d%d", &v, &w, &i);
						s = InsertArc(G, v, w, i);
					}					
					if(s == OK) printf("�߲���ɹ���\n");
					else if(s == INFEASIBLE) printf("����ʧ�ܣ���㲻���ڣ�\n");
					else printf("����ʧ�ܣ��Ѵ��������ߣ�\n");
				}
				getchar();
				system("pause");
				break;
	    	case 9:
	    		if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					printf("������Ҫɾ���ı������ӵĽ��ؼ��֣��Կո�ָ���");
					scanf("%d%d", &v, &w);
					s = DeleteArc(G, v, w);
					if(s == OK) printf("��ɾ���ɹ���\n");
					else if(s == INFEASIBLE) printf("ɾ��ʧ�ܣ���㲻���ڣ�\n");
					else printf("ɾ��ʧ�ܣ������������ߣ�\n");
				}
				getchar();
				system("pause");
				break;
	    	case 10:  
				if(!G.vexnum) printf("ͼΪ�գ�\n");  
				else{
					printf("������Ҫ����λ��Ľ��ؼ��֣�");
					scanf("%d", &v);
					i = FindIndex(G, v);
					if(i != -1) printf("��� %d ��λ��Ϊ %d ��\n", v, i);
					else printf("�����ڹؼ���Ϊ %d �Ľ�㣡\n", v);
				}
				getchar();
				system("pause");
				break;
			case 11:
				if(!G.vexnum) printf("ͼΪ�գ�\n"); 
				else{
					printf("��ͼ����������ȱ�����\n");
					DFSTraverse(G, visit);
				} 							
				getchar();
				system("pause");
				break;
			case 12:
				if(!G.vexnum) printf("ͼΪ�գ�\n"); 
				else{
					printf("��ͼ���й�����ȱ�����\n");
					BFSTraverse(G, visit);
				} 				
				getchar();
				system("pause");
				break;
			case 13:
				if(!G.vexnum) printf("ͼΪ�գ�\n"); 
				else{
					flag = 1;
					printf("������Ŀ����ؼ�����������ޣ��Կո�ָ���");
					scanf("%d%d", &v, &i);
					set = VerticesSetLessThanK(G, v, i);					
					for(int j = 0; j < G.vexnum; j++)
						if(set[j]){
							if(flag){
								printf("�� %d ����С�� %d �Ľ���У�\n", v, i);
								flag = 0;
							}
							printf("%d ", G.vertices[j].data.key);
						}
					if(flag) printf("�������� %d ����С�� %d �Ľ�㣡\n", v, i);
					else printf("\n");
				} 				
				getchar();
				system("pause");
				break;
			case 14:
				if(!G.vexnum) printf("ͼΪ�գ�\n"); 
				else{
					printf("������Ŀ����ؼ��֣��Կո�ָ���");
					scanf("%d%d", &v, &w);
					i = ShortestPathLength(G, v, w);
					if(i != -1) printf("��� %d ���� %d ����̾���Ϊ %d\n", v, w, i);
					else printf("���֮�䲻������̾��룡\n");
				}				
				getchar();
				system("pause");
				break;
			case 15:
				if(!G.vexnum) printf("ͼΪ�գ�\n"); 
				else printf("ͼ�� %d ����ͨ����\n", ConnectedComponentsNums(G));
				getchar();
				system("pause");
				break;
			case 16:
				if(!G.vexnum) printf("ͼΪ�գ�\n"); 
				else{
					printf("������Ҫ���浽���ļ�����");
					scanf("%s", filename);
					s = SaveGraph(G, filename);
					if(s == OK) printf("�ļ�����ɹ���\n");
					else printf("����ʧ�ܣ����ļ�ʧ�ܣ�\n");
				}
				getchar();
				system("pause");
				break;
			case 17:
				if(G.vexnum) printf("ͼ��Ϊ�գ�������ո�ͼ��\n"); 
				else{					
		input2:
					printf("������Ҫ������ͼ���ͣ���Ȩͼ��N����Ȩͼ��G��ȡ����Q��");
					getchar();
					scanf("%c", &ch);
					if(ch == 'n' || ch == 'N') k = UDN;
					else if(ch == 'g' || ch == 'G') k = UDG;
					else if(ch == 'q' || ch == 'Q') goto end1;
					else{
						printf("�����ͼ���Ͳ��Ϸ��������ԣ�\n");
						goto input2;
					} 
					printf("������Ҫ������ļ�����");
					scanf("%s", filename);
					s = LoadGraph(G, filename, k);
					if(s == OK) printf("ͼ���سɹ���\n");
					else printf("����ʧ�ܣ����ļ�ʧ�ܣ�\n");
				}
		end1:
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	op = 1;
	printf("��ͼ������ϡ�\n");
	system("pause");
	}//end of if
					else printf("����������Ϊ %s ��ͼ��\n", filename);
				}
				getchar();
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	system("pause");
}//end of main()
