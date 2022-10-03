/* Linear Table On Linked Structure */
#include "def.h"
#include "functions.h"

ElemType e;
int i, op = 1;
status s;
char filename[255];

int main(){
	LLT Lists;
	Lists.elem = NULL;
	int op = 1;
	while(op){
		system("cls");	printf("\n\n");
		printf("    Menu for Linear Table List On Linked Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitLists       4. DeleteList\n");
		printf("    	  2. DestroyLists    5. LocateList\n");
		printf("    	  3. AddList         6. OperateList \n");
		printf("    	  0. Exit\n");
		printf("    请选择你的操作[0~6]:");
		scanf("%d",&op);
		switch(op){
	    	case 1:
		    	if(InitLists(Lists)==OK) printf("线性表组创建成功！\n");
				else printf("线性表组创建失败！\n");
				getchar();
				system("pause");
				break;
	   		case 2:
				if(DestroyLists(Lists) == OK) printf("线性表组删除成功！\n");
				else printf("线性表组删除失败！\n");
				getchar();				
				system("pause");
				break;
	   		case 3:
				if(!Lists.elem) printf("线性表组不存在！\n"); 
				else{
					printf("请输入线性表名称：");
					scanf("%s", filename);
					s = AddList(Lists, filename);
					if(s == OK) printf("线性表添加成功！\n");
					else if(s == OVERFLOW) printf("已存在名为 %s 的表！\n", filename);
					else printf("添加失败！线性表组已满且重分配空间失败！\n");
				} 
				getchar();
				system("pause");
				break;
	   		case 4:
				if(!Lists.elem) printf("线性表组不存在！\n"); 
				else{
					printf("输入需要删除的线性表名：");
					scanf("%s", filename);
					if(RemoveList(Lists, filename) == OK) printf("线性表删除成功！\n");
					else printf("不存在名称为 %s 的线性表！\n", filename);
				}
				getchar();
				system("pause");
				break;
	   		case 5:
				if(!Lists.elem) printf("线性表组不存在！\n"); 
				else{
					printf("输入需要查找的线性表名：");
					scanf("%s", filename);
					i = LocateList(Lists, filename);
					if(i) printf("线性表位于第 %d 个。\n", i);
					else printf("不存在名称为 %s 的线性表！\n", filename);
				}
				getchar();
				system("pause");
				break;
	    	case 6:
				if(!Lists.elem) printf("线性表组不存在！\n"); 
				else{
					printf("输入需要操作的线性表名：");
					scanf("%s", filename);
					i = LocateList(Lists, filename);
					if(i){
						printf("线性表位于第 %d 个。\n", i);
		LinkList &L = Lists.elem[i-1].L;
		while(op){
						printf("选择操作功能：\n");
		printf("      Menu for Linear Table On Linked Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. ClearList    6. PriorElem\n");
		printf("    	  2. ListEmpty    7. NextElem \n");
		printf("    	  3. ListLength   8. ListInsert \n");
		printf("    	  4. GetElem      9. ListDelete\n");
		printf("    	  5. LocateElem   10. ListTraverse \n");
		printf("\n");
		printf("      Menu for Additional Functions \n");
		printf("    	  11. ReverseList\n");
		printf("    	  12. RemoveNthFromEnd\n");
		printf("    	  13. SortList\n");
		printf("    	  14. SaveList\n");
		printf("    	  15. LoadList\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~15]:");
		scanf("%d",&op);
		switch(op){
	   		case 1:
				if(ClearList(L) == OK) printf("线性表已清空！\n"); 
				else printf("线性表清空失败！\n"); 
				getchar();
				system("pause");
				break;
	   		case 2:
				if(ListEmpty(L) == TRUE) printf("线性表为空！\n");  
				else if(ListEmpty(L) == FALSE) printf("线性表不为空！\n");
				else printf("无法判断，请检查线性表是否存在！\n");   
				getchar();
				system("pause");
				break;
	   		case 3:
				if(ListLength(L) == INFEASIBLE) printf("线性表不存在！\n");  
				else printf("线性表的长度为%d\n", ListLength(L));
				getchar();
				system("pause");
				break;
	    	case 4:
				if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入要获取的元素序号：");
				scanf("%d", &i);
				if(GetElem(L, i, e) == INFEASIBLE) printf("线性表不存在！\n");
				else if(GetElem(L, i, e) == ERROR) printf("输入的序号不合法！\n");
				else printf("成功获取到该元素为 %d ！\n", e);
				getchar();
				system("pause");
				break;
	    	case 5:
	    		if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要查找的元素：");
				scanf("%d", &e);
				if(LocateElem(L, e) == INFEASIBLE) printf("线性表不存在！\n");
				else if(!LocateElem(L, e)) printf("未找到指定的元素！\n");
				else printf("已找到指定元素，序号为 %d ！\n", LocateElem(L, e)); 
				getchar();
				system("pause");
				break;
	    	case 6:
	    		if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				ElemType pre;
				printf("请输入需要查找前驱的元素：");
				scanf("%d", &e);
				if(PriorElem(L, e, pre) == INFEASIBLE) printf("线性表不存在！\n");
				else if(PriorElem(L, e, pre) == ERROR) printf("未找到该元素的前驱！\n"); 
				else printf("该元素的前驱为 %d ！\n", pre);    
				getchar();
				system("pause");
				break;
	    	case 7:
				ElemType next;
				if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要查找后继的元素：");
				scanf("%d", &e);
				if(NextElem(L, e, next) == INFEASIBLE) printf("线性表不存在！\n");
				else if(NextElem(L, e, next) == ERROR) printf("未找到该元素的后继！\n"); 
				else printf("该元素的后继为 %d ！\n", next);    
				getchar();
				system("pause");
				break;
	    	case 8:
	    		if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要插入的元素的位置：");
				scanf("%d", &i);
				printf("请输入插入的元素：");
				scanf("%d", &e);
				s = ListInsert(L, i, e);
				if(s == INFEASIBLE) printf("线性表不存在！\n");
				else if(s == ERROR) printf("输入的位置不合法！\n");
				else printf("元素插入成功！\n"); 
				getchar();
				system("pause");
				break;
	    	case 9:
	    		if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要删除的元素的位置：");
				scanf("%d", &i);
				s = ListDelete(L, i, e);
				if(s == INFEASIBLE) printf("线性表不存在！\n");
				else if(s == ERROR) printf("输入的位置不合法！\n");
				else printf("元素 %d 已成功从线性表中删除！\n", e); 
				getchar();
				system("pause");
				break;
	    	case 10:  
				if(!L) printf("线性表不存在！\n");
				else if(!L->next) printf("线性表是空表！\n");
				else if(ListTraverse(L) == INFEASIBLE) printf("线性表不存在！\n");
				getchar();
				system("pause");
				break;
			case 11:
				if(ReverseList(L) == INFEASIBLE) printf("线性表不存在！\n");				
				else printf("线性表已成功翻转！\n");
				getchar();
				system("pause");
				break;
			case 12:
				if(!L) printf("线性表不存在！\n");
				else{
					int k;
					printf("请输入要删除倒数第几个：");
					scanf("%d", &k);
					s = RemoveNthFromEnd(L, k);
					if(s == INFEASIBLE) printf("线性表不存在！\n");
					else if(s == ERROR) printf("输入的位置不合法！\n");
					else printf("已删除倒数第 %d 个元素！\n", k);
				}
				getchar();
				system("pause");
				break;
			case 13:
				if(SortList(L) == INFEASIBLE) printf("线性表不存在！\n");
				else printf("线性表已按升序排列！\n");
				getchar();
				system("pause");
				break;
			case 14:
				if(!L){
					printf("线性表不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入保存到的文件名：");
				scanf("%s", filename);
				s = SaveList(L, filename);
				if(s == INFEASIBLE) printf("线性表不存在！\n");
				else if(s == ERROR) printf("文件打开失败！\n");
				else printf("文件保存成功！\n");
				getchar();
				system("pause");
				break;
			case 15:
				if(!L) printf("线性表不存在！\n");
				else if(L->next) printf("线性表不为空！请先清空或创建一个新的表！\n");
				else{
					printf("请输入源文件名：");
					scanf("%s", filename);
					s = LoadList(L, filename);
					if(s == ERROR) printf("文件打开失败！\n");
					else printf("线性表创建成功！\n");
				}
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	op = 1;
	printf("该线性表操作完毕。\n");
	system("pause");
	}//end of if
					else printf("不存在名称为 %s 的线性表！\n", filename);
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
