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
		printf("    ��ѡ����Ĳ���[0~6]:");
		scanf("%d",&op);
		switch(op){
	    	case 1:
		    	if((s = InitList(Lists))==OK) printf("�������鴴���ɹ���\n");
				else if(s = INFEASIBLE) printf("����ʧ�ܣ����������Ѵ��ڣ�\n");
				else printf("������������ʱ�ռ����ʧ�ܣ�\n");
				getchar();
				system("pause");
				break;
			case 2:
				if(DestroyList(Lists) == OK) printf("��������ɾ���ɹ���\n");
				else printf("��������ɾ��ʧ�ܣ�\n");
				getchar();				
				system("pause");
				break;
			case 3:
				if(!Lists.elem) printf("�������鲻���ڣ�\n"); 
				else{
					printf("��������������ƣ�");
					scanf("%s", filename);
					if(LocateTree(Lists, filename)){
						printf("�Ѵ�����Ϊ %s ������\n", filename);
						getchar();
						system("pause");
						break;
					}
					s = AddTree(Lists, filename);
					if(s == OK) printf("��������ӳɹ���\n");
					else printf("���ʧ�ܣ���������������\n");
				} 
				getchar();
				system("pause");
				break;
			case 4:
				if(!Lists.elem) printf("�������鲻���ڣ�\n"); 
				else{
					printf("������Ҫɾ���Ķ���������");
					scanf("%s", filename);
					if(DeleteTree(Lists, filename) == OK) printf("������ɾ���ɹ���\n");
					else printf("����������Ϊ %s �Ķ�������\n", filename);
				}
				getchar();
				system("pause");
				break;
	   		case 5:
				if(!Lists.elem) printf("�������鲻���ڣ�\n"); 
				else{
					printf("������Ҫ���ҵĶ���������");
					scanf("%s", filename);
					i = LocateTree(Lists, filename);
					if(i) printf("������λ�ڵ� %d ����\n", i);
					else printf("����������Ϊ %s �Ķ�������\n", filename);
				}
				getchar();
				system("pause");
				break;
	    	case 6:
				if(!Lists.elem) printf("�������鲻���ڣ�\n"); 
				else{
					printf("������Ҫ�����Ķ���������");
					scanf("%s", filename);
					i = LocateTree(Lists, filename);
					if(i){
						printf("������λ�ڵ� %d ����\n", i);
		BiTree &L = Lists.elem[i-1].root;
		while(op){
						printf("ѡ��������ܣ�\n");
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
		printf("    ��ѡ����Ĳ���[0~18]:");
		scanf("%d",&op);
		switch(op){
	   		case 1:
				if(L) printf("�������ѽ�������������ٽ���������\n");
				else{
					printf("�����������������������У���key = -1������\n");
					definition = (TElemType*)malloc(sizeof(TElemType) * TREESIZE);
					for(i = 0; i < TREESIZE; i++){
						scanf("%d%s", &definition[i].key, definition[i].others);
						if(definition[i].key == -1) break;
					}
					if(i == TREESIZE) printf("��������С�ﵽ���ޣ�\n");
					else{
						if((s = CreateBiTree(L, definition)) == OK) printf("�����������ɹ���\n");
						else if(s == OVERFLOW) printf("����ռ�ʧ�ܣ�\n");
						else printf("���ڹؼ����ظ��Ľ�㣡\n");
					}
				}
 				getchar();
				system("pause");
				break;
	   		case 2:
				if(ClearBiTree(L) == OK) printf("����������գ�\n");
				getchar();
				system("pause");
				break;
	   		case 3:
				if(!L) printf("������Ϊ�գ�\n");  
				else printf("��������Ϊ�գ�\n");
				getchar();
				system("pause");
				break;
	    	case 4:
				if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("�����������Ϊ %d ��", BiTreeDepth(L));
				getchar();
				system("pause");
				break;
	    	case 5:
	    		if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫ���ҵĽ��ؼ��֣�");
				scanf("%d", &e);
				if(!(v = LocateNode(L, e))) printf("δ�ҵ�ָ���Ľ��ؼ��֣�\n");
				else printf("���ҵ�ָ����㣬����Ϊ %s ��\n", v->data.others); 
				getchar();
				system("pause");
				break;
	    	case 6:
	    		if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫ��ֵ�Ľ��ؼ��֣�");
				scanf("%d", &e);
				if(!LocateNode(L, e)) printf("�����ڹؼ���Ϊ %d �Ľ�㣡\n", e);
				else{
					printf("�����븳ֵ����Ĺؼ��ֺ��������ÿո�ָ���\n");
					scanf("%d%s", &a.key, a.others);
					if(Assign(L, e, a) == OK) printf("��㸳ֵ�ɹ���\n");
					else printf("��ֵʧ�ܣ������ظ��Ĺؼ��֣�\n");
				}
				getchar();
				system("pause");
				break;
	    	case 7:
				if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫ�����ֵܵĽ��ؼ��֣�");
				scanf("%d", &e);
				if((v = GetSibling(L, e)))
					printf("�ֵܽ��Ĺؼ���Ϊ %d ������Ϊ %s \n", v->data.key, v->data.others);
				else printf("δ�ҵ��ý����ֵܽڵ㣡\n");    
				getchar();
				system("pause");
				break;
	    	case 8:
	    		if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("���������λ�õĽ��ؼ��֣�");
				scanf("%d", &e);
				if(!(v = LocateNode(L, e))){
					printf("�����ڹؼ���Ϊ %d �Ľ�㣡\n", e);
					printf("�Ƿ�Ҫ��Ϊ���ڵ���룿(Y/N)\n");
					getchar();
					scanf("%c", &ch);
					if(ch == 'y' || ch == 'Y'){
						printf("�����������Ĺؼ��ֺ��������Կո�ָ���\n");
						scanf("%d%s", &a.key, a.others);
						if(InsertNode(L, 0, -1, a) == OK) printf("������ɹ���\n");
						else printf("����ʧ�ܣ������ظ��ؼ��֣�\n"); 
					}else printf("��ô������ʧ��qaq\n");
				}else{
					LR = 233;
					printf("��ѡ�����λ��(L/R/Q)��");
					do{
						getchar();
						scanf("%c", &ch);
						if(ch == 'l' || ch == 'L') LR = 0;
						else if(ch == 'r' || ch == 'R') LR = 1;
						else if(ch == 'q' || ch == 'Q') break;
						else printf("λ�����벻�Ϸ���������(L/R/Q)��");
					}while(LR != 0 && LR != 1);
					if(LR == 0 || LR == 1){
						printf("�����������Ĺؼ��ֺ��������Կո�ָ���\n");
						scanf("%d%s", &a.key, a.others);
						if((s = InsertNode(L, e, LR, a)) == OK) printf("������ɹ���\n");
						else if(s == INFEASIBLE) printf("����ʧ�ܣ������ظ��ؼ��֣�\n");
						else printf("����ʧ�ܣ��޷�Ϊ�½�����ռ䣡\n");
					}
				}
				getchar();
				system("pause");
				break;
	    	case 9:
	    		if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("ɾ������\n");
				printf("�������Ϊ0��ɾ�����ɣ�\n");
				printf("�����Ϊ1���ý��ĺ��Ӵ��汻ɾ���Ľ��λ�ã�\n");
				printf("�����Ϊ2���ý������Ӵ��汻ɾ���Ľ��λ�ã�������������Ϊ��������������ҽ�����������\n");
				printf("��������Ҫɾ���Ľ��ؼ��֣�");
				scanf("%d", &e);
				s = DeleteNode(L, e);
				if(s == OK) printf("���ɾ���ɹ���\n");
				else if(s == ERROR) printf("�����ڹؼ���Ϊ %d �Ľ�㣡\n", e);
				getchar();
				system("pause");
				break;
	    	case 10:  
				if(!L) printf("�����������ڣ�\n");
				else PreOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 11:
				if(!L) printf("�����������ڣ�\n");
				else InOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 12:
				if(!L) printf("�����������ڣ�\n");
				else PostOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 13:
				if(!L) printf("�����������ڣ�\n");
				else LevelOrderTraverse(L, visit);
				getchar();
				system("pause");
				break;
			case 14:
				if(!L){
					printf("�����������ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("������Ҫ���浽���ļ����ƣ�");
				scanf("%s", filename);
				s = SaveBiTree(L, filename);
				if(s == INFEASIBLE) printf("�����������ڣ�\n");
				else if(s == ERROR) printf("�ļ���ʧ�ܣ�\n");
				else printf("�ļ�����ɹ���\n");
				getchar();
				system("pause");
				break;
			case 15:
				if(L) printf("��������Ϊ�գ�������ջ򴴽�һ���µĶ�������\n");
				else{
					printf("������Դ�ļ�����");
					scanf("%s", filename);
					s = LoadBiTree(L, filename);
					if(s == ERROR) printf("�ļ���ʧ�ܣ�\n");
					else printf("�����������ɹ���\n");
				}
				getchar();
				system("pause");
				break;
			case 16:
				if(!L) printf("�����������ڣ�\n");
				else printf("�������Ӹ���Ҷ�����·����Ϊ %d \n", MaxPathSum(L));
				getchar();
				system("pause");
				break;
			case 17:
				if(!L) printf("�����������ڣ�\n");
				else{
					printf("��������Ҫ�������ȵĽ��ؼ��֣��Կո�ָ���\n");
					scanf("%d%d", &e, &f);
					if(!LocateNode(L, e) || !LocateNode(L, f)) 
						printf("����û�й�ͬ���ȣ��������Ƿ���ڣ�");
					else if(!(v = LowestCommonAncestor(L, e, f))) 
						printf("����û�й�ͬ���ȣ��������Ƿ���ڣ�\n");
					else 
						printf("���Ĺ�ͬ���ȹؼ���Ϊ %d ������Ϊ %s \n", v->data.key, v->data.others);
				}
				getchar();
				system("pause");
				break;
			case 18:
				if(!L) printf("�����������ڣ�\n");
				else if(InvertTree(L) == OK) printf("�������ѳɹ���ת��\n");
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	op = 1;
	printf("�ö�����������ϡ�\n");
	}//end of if
					else printf("����������Ϊ %s �Ķ�������\n", filename);
				}
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	system("pause");
}//end of main()
