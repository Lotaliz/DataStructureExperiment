/* Binary Tree */
#include "functions.h"

KeyType e, f;
TElemType *definition, a;
BiTree v;
int i, LR;
status s;
char filename[255], ch;

int main(){
	TreeList Lists;
	Lists.elem = NULL;
	int op = 1;
	while(op){
		system("cls");	printf("\n\n");
		printf("            Menu for Binary Tree \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList        4. DeleteTree\n");
		printf("    	  2. DestroyList     5. LocateTree\n");
		printf("    	  3. AddTree         6. OperateTree \n");
		printf("    	  0. Exit\n");
		printf("    请选择你的操作[0~6]:");
		scanf("%d",&op);
		switch(op){
	    	case 1:
		    	if((s = InitList(Lists))==OK) printf("二叉树组创建成功！\n");
				else if(s = INFEASIBLE) printf("创建失败！二叉树组已存在！\n");
				else printf("创建二叉树组时空间分配失败！\n");
				getchar();
				system("pause");
				break;
			case 2:
				if(DestroyList(Lists) == OK) printf("二叉树组删除成功！\n");
				else printf("二叉树组删除失败！\n");
				getchar();				
				system("pause");
				break;
			case 3:
				if(!Lists.elem) printf("二叉树组不存在！\n"); 
				else{
					printf("请输入二叉树名称：");
					scanf("%s", filename);
					if(LocateTree(Lists, filename)){
						printf("已存在名为 %s 的树！\n", filename);
						getchar();
						system("pause");
						break;
					}
					s = AddTree(Lists, filename);
					if(s == OK) printf("二叉树添加成功！\n");
					else printf("添加失败！二叉树组已满！\n");
				} 
				getchar();
				system("pause");
				break;
			case 4:
				if(!Lists.elem) printf("二叉树组不存在！\n"); 
				else{
					printf("输入需要删除的二叉树名：");
					scanf("%s", filename);
					if(DeleteTree(Lists, filename) == OK) printf("二叉树删除成功！\n");
					else printf("不存在名称为 %s 的二叉树！\n", filename);
				}
				getchar();
				system("pause");
				break;
	   		case 5:
				if(!Lists.elem) printf("二叉树组不存在！\n"); 
				else{
					printf("输入需要查找的二叉树名：");
					scanf("%s", filename);
					i = LocateTree(Lists, filename);
					if(i) printf("二叉树位于第 %d 个。\n", i);
					else printf("不存在名称为 %s 的二叉树！\n", filename);
				}
				getchar();
				system("pause");
				break;
	    	case 6:
				if(!Lists.elem) printf("二叉树组不存在！\n"); 
				else{
					printf("输入需要操作的二叉树名：");
					scanf("%s", filename);
					i = LocateTree(Lists, filename);
					if(i){
						printf("二叉树位于第 %d 个。\n", i);
		BiTree &L = Lists.elem[i-1].root;
		while(op){
						printf("选择操作功能：\n");
		printf("              Menu for Binary Tree \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateBiTree   8. InsertNode\n");
		printf("    	  2. ClearBiTree    9. DeleteNode \n");
		printf("    	  3. BiTreeEmpty    10. PreOrderTraverse  \n");
		printf("    	  4. BiTreeDepth    11. InOrderTraverse\n");
		printf("    	  5. LocateNode     12. PostOrderTraverse \n");
		printf("    	  6. Assign         13. LevelOrderTraverse \n");
		printf("    	  7. GetSibling \n");
		printf("\n");
		printf("      Menu for Additional Functions \n");
		printf("    	  14. SaveBiTree\n");
		printf("    	  15. LoadBiTree\n");
		printf("    	  16. MaxPathSum\n");
		printf("    	  17. LowestCommonAncestor\n");
		printf("    	  18. InvertTree\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~18]:");
		scanf("%d",&op);
		switch(op){
	   		case 1:
				if(L) printf("二叉树已建立！请先清空再建立新树！\n");
				else{
					printf("请输入二叉树的先序遍历序列，以key = -1结束：\n");
					definition = (TElemType*)malloc(sizeof(TElemType) * TREESIZE);
					for(i = 0; i < TREESIZE; i++){
						scanf("%d%s", &definition[i].key, definition[i].others);
						if(definition[i].key == -1) break;
					}
					if(i == TREESIZE) printf("二叉树大小达到上限！\n");
					else{
						if((s = CreateBiTree(L, definition)) == OK) printf("二叉树创建成功！\n");
						else if(s == OVERFLOW) printf("分配空间失败！\n");
						else printf("存在关键字重复的结点！\n");
					}
				}
 				getchar();
				system("pause");
				break;
	   		case 2:
				if(ClearBiTree(L) == OK) printf("二叉树已清空！\n");
				getchar();
				system("pause");
				break;
	   		case 3:
				if(!L) printf("二叉树为空！\n");  
				else printf("二叉树不为空！\n");
				getchar();
				system("pause");
				break;
	    	case 4:
				if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("二叉树的深度为 %d ！", BiTreeDepth(L));
				getchar();
				system("pause");
				break;
	    	case 5:
	    		if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要查找的结点关键字：");
				scanf("%d", &e);
				if(!(v = LocateNode(L, e))) printf("未找到指定的结点关键字！\n");
				else printf("已找到指定结点，描述为 %s ！\n", v->data.others); 
				getchar();
				system("pause");
				break;
	    	case 6:
	    		if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要赋值的结点关键字：");
				scanf("%d", &e);
				if(!LocateNode(L, e)) printf("不存在关键字为 %d 的结点！\n", e);
				else{
					printf("请输入赋值后结点的关键字和描述，用空格分隔：\n");
					scanf("%d%s", &a.key, a.others);
					if(Assign(L, e, a) == OK) printf("结点赋值成功！\n");
					else printf("赋值失败！包含重复的关键字！\n");
				}
				getchar();
				system("pause");
				break;
	    	case 7:
				if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入需要查找兄弟的结点关键字：");
				scanf("%d", &e);
				if((v = GetSibling(L, e)))
					printf("兄弟结点的关键字为 %d ，描述为 %s \n", v->data.key, v->data.others);
				else printf("未找到该结点的兄弟节点！\n");    
				getchar();
				system("pause");
				break;
	    	case 8:
	    		if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入插入位置的结点关键字：");
				scanf("%d", &e);
				if(!(v = LocateNode(L, e))){
					printf("不存在关键字为 %d 的结点！\n", e);
					printf("是否要作为根节点插入？(Y/N)\n");
					getchar();
					scanf("%c", &ch);
					if(ch == 'y' || ch == 'Y'){
						printf("请输入插入结点的关键字和描述，以空格分隔：\n");
						scanf("%d%s", &a.key, a.others);
						if(InsertNode(L, 0, -1, a) == OK) printf("结点插入成功！\n");
						else printf("插入失败！存在重复关键字！\n"); 
					}else printf("那么，插入失败qaq\n");
				}else{
					LR = 233;
					printf("请选择插入位置(L/R/Q)：");
					do{
						getchar();
						scanf("%c", &ch);
						if(ch == 'l' || ch == 'L') LR = 0;
						else if(ch == 'r' || ch == 'R') LR = 1;
						else if(ch == 'q' || ch == 'Q') break;
						else printf("位置输入不合法，请重试(L/R/Q)：");
					}while(LR != 0 && LR != 1);
					if(LR == 0 || LR == 1){
						printf("请输入插入结点的关键字和描述，以空格分隔：\n");
						scanf("%d%s", &a.key, a.others);
						if((s = InsertNode(L, e, LR, a)) == OK) printf("结点插入成功！\n");
						else if(s == INFEASIBLE) printf("插入失败！存在重复关键字！\n");
						else printf("插入失败！无法为新结点分配空间！\n");
					}
				}
				getchar();
				system("pause");
				break;
	    	case 9:
	    		if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("删除规则：\n");
				printf("如果结点度为0，删除即可；\n");
				printf("如结点度为1，用结点的孩子代替被删除的结点位置；\n");
				printf("如结点度为2，用结点的左孩子代替被删除的结点位置，结点的右子树作为其的左子树中最右结点的右子树。\n");
				printf("请输入需要删除的结点关键字：");
				scanf("%d", &e);
				s = DeleteNode(L, e);
				if(s == OK) printf("结点删除成功！\n");
				else if(s == ERROR) printf("不存在关键字为 %d 的结点！\n", e);
				getchar();
				system("pause");
				break;
	    	case 10:  
				if(!L) printf("二叉树不存在！\n");
				else PreOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 11:
				if(!L) printf("二叉树不存在！\n");
				else InOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 12:
				if(!L) printf("二叉树不存在！\n");
				else PostOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 13:
				if(!L) printf("二叉树不存在！\n");
				else LevelOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 14:
				if(!L){
					printf("二叉树不存在！\n");
					getchar();
					system("pause");
					break;
				}
				printf("请输入要保存到的文件名称：");
				scanf("%s", filename);
				s = SaveBiTree(L, filename);
				if(s == INFEASIBLE) printf("二叉树不存在！\n");
				else if(s == ERROR) printf("文件打开失败！\n");
				else printf("文件保存成功！\n");
				getchar();
				system("pause");
				break;
			case 15:
				if(L) printf("二叉树不为空！请先清空或创建一个新的二叉树！\n");
				else{
					printf("请输入源文件名：");
					scanf("%s", filename);
					s = LoadBiTree(L, filename);
					if(s == ERROR) printf("文件打开失败！\n");
					else printf("二叉树创建成功！\n");
				}
				getchar();
				system("pause");
				break;
			case 16:
				if(!L) printf("二叉树不存在！\n");
				else printf("二叉树从根到叶的最大路径和为 %d \n", MaxPathSum(L));
				getchar();
				system("pause");
				break;
			case 17:
				if(!L) printf("二叉树不存在！\n");
				else{
					printf("请输入需要查找祖先的结点关键字，以空格分隔：\n");
					scanf("%d%d", &e, &f);
					if(!LocateNode(L, e) || !LocateNode(L, f)) 
						printf("它们没有共同祖先！请检查结点是否存在！");
					else if(!(v = LowestCommonAncestor(L, e, f))) 
						printf("它们没有共同祖先！请检查结点是否存在！\n");
					else 
						printf("结点的共同祖先关键字为 %d ，描述为 %s \n", v->data.key, v->data.others);
				}
				getchar();
				system("pause");
				break;
			case 18:
				if(!L) printf("二叉树不存在！\n");
				else if(InvertTree(L) == OK) printf("二叉树已成功翻转！\n");
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	op = 1;
	printf("该二叉树操作完毕。\n");
	}//end of if
					else printf("不存在名称为 %s 的二叉树！\n", filename);
				}
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	system("pause");
}//end of main()
