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
		printf("    请选择你的操作[0~6]:");
		scanf("%d",&op);
		switch(op){
	    	case 1:
		    	if(InitGraphs(Gs)==OK) printf("图组创建成功！\n");
				else printf("图组创建失败！\n");
				getchar();
				system("pause");
				break;
	   		case 2:
				if(DestroyGraphs(Gs) == OK) printf("图组删除成功！\n");
				else printf("图组删除失败！\n");
				getchar();				
				system("pause");
				break;
	   		case 3:
				if(!Gs.elem) printf("图组不存在！\n"); 
				else{
					printf("请输入图名称：");
					scanf("%s", filename);
					s = AddGraph(Gs, filename);
					if(s == OK) printf("图添加成功！\n");
					else if(s == ERROR) printf("已存在名为 %s 的图！\n", filename);
					else printf("添加失败！图组已满！\n");
				} 
				getchar();
				system("pause");
				break;
	   		case 4:
				if(!Gs.elem) printf("图组不存在！\n"); 
				else{
					printf("输入需要删除的图名：");
					scanf("%s", filename);
					if(DeleteGraph(Gs, filename) == OK) printf("图删除成功！\n");
					else printf("不存在名称为 %s 的图！\n", filename);
				}
				getchar();
				system("pause");
				break;
	   		case 5:
				if(!Gs.elem) printf("图组不存在！\n"); 
				else{
					printf("输入需要查找的图名：");
					scanf("%s", filename);
					i = LocateGraph(Gs, filename);
					if(i) printf("图位于第 %d 个。\n", i);
					else printf("不存在名称为 %s 的图！\n", filename);
				}
				getchar();
				system("pause");
				break;
	    	case 6:
				if(!Gs.elem){
					printf("图组不存在！\n"); 
					getchar();
					system("pause");
					break;
				}
				else{
					printf("输入需要操作的图名：");
					scanf("%s", filename);
					i = LocateGraph(Gs, filename);
					if(i){
						printf("图位于第 %d 个。\n", i);
		ALGraph &G = Gs.elem[i-1].G;
		while(op){
						printf("选择操作功能：\n");
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
		printf("    请选择你的操作[0~17]:");
		scanf("%d",&op);
		switch(op){
	   		case 1:
	input1: 
				printf("请输入要创建的图类型：加权图（N）无权图（G）取消（Q）");
				getchar();
				scanf("%c", &ch);
				if(ch == 'n' || ch == 'N'){
					i = 0;
					printf("请输入结点的关键字和描述，以空格分隔，-1结束：\n");
					do{
    					scanf("%d%s", &V[i].key, V[i].others);
					}while(V[i++].key != -1);
					printf("请输入边连接的顶点的关键字和此边的权，以空格分隔，-1结束：\n");
					i = 0;
					do{
    					scanf("%d%d%d", &N[i].v1, &N[i].v2, &N[i].weight);
    				}while(N[i++].v1 != -1);
    				if(CreateNet(G, V, N) == OK) printf("加权图创建成功！\n");
    				else printf("创建失败！请检查是否有多重边或重复关键字！\n");
				}else if(ch == 'g' || ch == 'G'){
					i = 0;
					printf("请输入结点的关键字和描述，以空格分隔，-1结束：\n");
					do{
    					scanf("%d%s", &V[i].key, V[i].others);
					}while(V[i++].key != -1);
					printf("请输入边连接的顶点的关键字，以空格分隔，-1结束：\n");
					i = 0;
					do{
    					scanf("%d%d", &VR[i][0], &VR[i][1]);
    				}while(VR[i++][0] != -1);
    				if(CreateGraph(G, V, VR) == OK) printf("无权图创建成功！\n");
    				else printf("创建失败！请检查是否有多重边或重复关键字！\n");
				}else if(ch == 'q' || ch == 'Q');
				else{
					printf("输入的图类型不合法！请重新输入！\n");
					goto input1;
				}
				getchar();
				system("pause");
				break;
	   		case 2:
				if(DestroyGraph(G) == OK) printf("图已销毁！\n");
				getchar();
				system("pause");
				break;
	   		case 3:
				if(!G.vexnum) printf("图为空！\n");  
				else{
					printf("请输入要修改的结点关键字：");
					scanf("%d", &v);
					printf("请输入修改后的关键字和描述，以空格分隔：\n");
					scanf("%d %s", &value.key, value.others);
					if(PutVex(G, v, value) == OK) printf("结点修改成功！\n");
					else printf("修改失败！请检查是否有重复关键字及目标关键字是否存在！\n");
				}
				getchar();
				system("pause");
				break;
	    	case 4:
				if(!G.vexnum) printf("图为空！\n");  
				else{
					printf("请输入要查找邻接的结点关键字：");
					scanf("%d", &v);
					i = FirstAdjVex(G, v);
					if(i != -1) printf("%d 的第一邻接结点的位序为 %d\n", v, i);
					else printf("不存在 %d 的第一邻接结点！\n", v);
				}
				getchar();
				system("pause");
				break;
	    	case 5:
	    		if(!G.vexnum) printf("图为空！\n");  
				else{
					printf("请输入要查找的结点关键字和其一个邻接结点的关键字，以空格分隔：");
					scanf("%d%d", &v, &w);
					i = NextAdjVex(G, v, w);
					if(i != -1) printf("%d 的相对于 %d 的下一邻接结点位序是 %d ！\n", v, w, i);
					else printf("未找到 %d 的相对于 %d 的下一邻接结点！\n", v, w);
				}
				getchar();
				system("pause");
				break;
	    	case 6: 				
				printf("请输入插入的结点关键字和描述，以空格分隔：\n");
				scanf("%d%s", &value.key, value.others);
				s = InsertVex(G, value);
				if(s == OK) printf("结点插入成功！\n");
				else if(s == OVERFLOW) printf("插入失败！结点数量已达上限！\n"); 
				else printf("插入失败！已存在关键字为 %d 的结点！\n", v);			
				getchar();
				system("pause");
				break;
	    	case 7:
				if(!G.vexnum) printf("图为空！\n");  
				else{
					printf("请输入要删除的结点关键字：");
					scanf("%d", &v);
					s = DeleteVex(G, v);
					if(s == OK) printf("结点删除成功！\n");
					else printf("删除失败！不存在关键字为 %d 的结点！\n", v);
				}
				getchar();
				system("pause");
				break;
	    	case 8:
	    		if(!G.vexnum) printf("图为空！\n");  
				else{
					if(G.kind == UDG){
						printf("请输入插入的边所链接的结点关键字，以空格分隔：");
						scanf("%d%d", &v, &w);
						s = InsertArc(G, v, w, 0);
					}else if(G.kind == UDN){
						printf("请输入插入的边所链接的结点关键字以及距离，以空格分隔：");
						scanf("%d%d%d", &v, &w, &i);
						s = InsertArc(G, v, w, i);
					}					
					if(s == OK) printf("边插入成功！\n");
					else if(s == INFEASIBLE) printf("插入失败！结点不存在！\n");
					else printf("插入失败！已存在这条边！\n");
				}
				getchar();
				system("pause");
				break;
	    	case 9:
	    		if(!G.vexnum) printf("图为空！\n");  
				else{
					printf("请输入要删除的边所链接的结点关键字，以空格分隔：");
					scanf("%d%d", &v, &w);
					s = DeleteArc(G, v, w);
					if(s == OK) printf("边删除成功！\n");
					else if(s == INFEASIBLE) printf("删除失败！结点不存在！\n");
					else printf("删除失败！不存在这条边！\n");
				}
				getchar();
				system("pause");
				break;
	    	case 10:  
				if(!G.vexnum) printf("图为空！\n");  
				else{
					printf("请输入要查找位序的结点关键字：");
					scanf("%d", &v);
					i = FindIndex(G, v);
					if(i != -1) printf("结点 %d 的位序为 %d ！\n", v, i);
					else printf("不存在关键字为 %d 的结点！\n", v);
				}
				getchar();
				system("pause");
				break;
			case 11:
				if(!G.vexnum) printf("图为空！\n"); 
				else{
					printf("对图进行深度优先遍历：\n");
					DFSTraverse(G, visit);
				} 							
				getchar();
				system("pause");
				break;
			case 12:
				if(!G.vexnum) printf("图为空！\n"); 
				else{
					printf("对图进行广度优先遍历：\n");
					BFSTraverse(G, visit);
				} 				
				getchar();
				system("pause");
				break;
			case 13:
				if(!G.vexnum) printf("图为空！\n"); 
				else{
					flag = 1;
					printf("请输入目标结点关键字与距离上限，以空格分隔：");
					scanf("%d%d", &v, &i);
					set = VerticesSetLessThanK(G, v, i);					
					for(int j = 0; j < G.vexnum; j++)
						if(set[j]){
							if(flag){
								printf("与 %d 距离小于 %d 的结点有：\n", v, i);
								flag = 0;
							}
							printf("%d ", G.vertices[j].data.key);
						}
					if(flag) printf("不存在与 %d 距离小于 %d 的结点！\n", v, i);
					else printf("\n");
				} 				
				getchar();
				system("pause");
				break;
			case 14:
				if(!G.vexnum) printf("图为空！\n"); 
				else{
					printf("请输入目标结点关键字，以空格分隔：");
					scanf("%d%d", &v, &w);
					i = ShortestPathLength(G, v, w);
					if(i != -1) printf("结点 %d 与结点 %d 的最短距离为 %d\n", v, w, i);
					else printf("结点之间不存在最短距离！\n");
				}				
				getchar();
				system("pause");
				break;
			case 15:
				if(!G.vexnum) printf("图为空！\n"); 
				else printf("图有 %d 个连通分量\n", ConnectedComponentsNums(G));
				getchar();
				system("pause");
				break;
			case 16:
				if(!G.vexnum) printf("图为空！\n"); 
				else{
					printf("请输入要保存到的文件名：");
					scanf("%s", filename);
					s = SaveGraph(G, filename);
					if(s == OK) printf("文件保存成功！\n");
					else printf("保存失败！打开文件失败！\n");
				}
				getchar();
				system("pause");
				break;
			case 17:
				if(G.vexnum) printf("图不为空！请先清空该图！\n"); 
				else{					
		input2:
					printf("请输入要创建的图类型：加权图（N）无权图（G）取消（Q）");
					getchar();
					scanf("%c", &ch);
					if(ch == 'n' || ch == 'N') k = UDN;
					else if(ch == 'g' || ch == 'G') k = UDG;
					else if(ch == 'q' || ch == 'Q') goto end1;
					else{
						printf("输入的图类型不合法，请重试！\n");
						goto input2;
					} 
					printf("请输入要载入的文件名：");
					scanf("%s", filename);
					s = LoadGraph(G, filename, k);
					if(s == OK) printf("图加载成功！\n");
					else printf("加载失败！打开文件失败！\n");
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
	printf("该图操作完毕。\n");
	system("pause");
	}//end of if
					else printf("不存在名称为 %s 的图！\n", filename);
				}
				getchar();
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	system("pause");
}//end of main()
