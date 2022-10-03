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
		printf("    ��ѡ����Ĳ���[0~6]:");
		scanf("%d",&op);
		switch(op){
	    	case 1:
		    	if(InitLists(Lists)==OK) printf("���Ա��鴴���ɹ���\n");
				else printf("���Ա��鴴��ʧ�ܣ�\n");
				getchar();
				system("pause");
				break;
	   		case 2:
				if(DestroyLists(Lists) == OK) printf("���Ա���ɾ���ɹ���\n");
				else printf("���Ա���ɾ��ʧ�ܣ�\n");
				getchar();				
				system("pause");
				break;
	   		case 3:
				if(!Lists.elem) printf("���Ա��鲻���ڣ�\n"); 
				else{
					printf("���������Ա����ƣ�");
					scanf("%s", filename);
					s = AddList(Lists, filename);
					if(s == OK) printf("���Ա���ӳɹ���\n");
					else if(s == OVERFLOW) printf("�Ѵ�����Ϊ %s �ı�\n", filename);
					else printf("���ʧ�ܣ����Ա����������ط���ռ�ʧ�ܣ�\n");
				} 
				getchar();
				system("pause");
				break;
	   		case 4:
				if(!Lists.elem) printf("���Ա��鲻���ڣ�\n"); 
				else{
					printf("������Ҫɾ�������Ա�����");
					scanf("%s", filename);
					if(RemoveList(Lists, filename) == OK) printf("���Ա�ɾ���ɹ���\n");
					else printf("����������Ϊ %s �����Ա�\n", filename);
				}
				getchar();
				system("pause");
				break;
	   		case 5:
				if(!Lists.elem) printf("���Ա��鲻���ڣ�\n"); 
				else{
					printf("������Ҫ���ҵ����Ա�����");
					scanf("%s", filename);
					i = LocateList(Lists, filename);
					if(i) printf("���Ա�λ�ڵ� %d ����\n", i);
					else printf("����������Ϊ %s �����Ա�\n", filename);
				}
				getchar();
				system("pause");
				break;
	    	case 6:
				if(!Lists.elem) printf("���Ա��鲻���ڣ�\n"); 
				else{
					printf("������Ҫ���������Ա�����");
					scanf("%s", filename);
					i = LocateList(Lists, filename);
					if(i){
						printf("���Ա�λ�ڵ� %d ����\n", i);
		LinkList &L = Lists.elem[i-1].L;
		while(op){
						printf("ѡ��������ܣ�\n");
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
		printf("    ��ѡ����Ĳ���[0~15]:");
		scanf("%d",&op);
		switch(op){
	   		case 1:
				if(ClearList(L) == OK) printf("���Ա�����գ�\n"); 
				else printf("���Ա����ʧ�ܣ�\n"); 
				getchar();
				system("pause");
				break;
	   		case 2:
				if(ListEmpty(L) == TRUE) printf("���Ա�Ϊ�գ�\n");  
				else if(ListEmpty(L) == FALSE) printf("���Ա�Ϊ�գ�\n");
				else printf("�޷��жϣ��������Ա��Ƿ���ڣ�\n");   
				getchar();
				system("pause");
				break;
	   		case 3:
				if(ListLength(L) == INFEASIBLE) printf("���Ա����ڣ�\n");  
				else printf("���Ա�ĳ���Ϊ%d\n", ListLength(L));
				getchar();
				system("pause");
				break;
	    	case 4:
				if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("������Ҫ��ȡ��Ԫ����ţ�");
				scanf("%d", &i);
				if(GetElem(L, i, e) == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(GetElem(L, i, e) == ERROR) printf("�������Ų��Ϸ���\n");
				else printf("�ɹ���ȡ����Ԫ��Ϊ %d ��\n", e);
				getchar();
				system("pause");
				break;
	    	case 5:
	    		if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫ���ҵ�Ԫ�أ�");
				scanf("%d", &e);
				if(LocateElem(L, e) == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(!LocateElem(L, e)) printf("δ�ҵ�ָ����Ԫ�أ�\n");
				else printf("���ҵ�ָ��Ԫ�أ����Ϊ %d ��\n", LocateElem(L, e)); 
				getchar();
				system("pause");
				break;
	    	case 6:
	    		if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				ElemType pre;
				printf("��������Ҫ����ǰ����Ԫ�أ�");
				scanf("%d", &e);
				if(PriorElem(L, e, pre) == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(PriorElem(L, e, pre) == ERROR) printf("δ�ҵ���Ԫ�ص�ǰ����\n"); 
				else printf("��Ԫ�ص�ǰ��Ϊ %d ��\n", pre);    
				getchar();
				system("pause");
				break;
	    	case 7:
				ElemType next;
				if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫ���Һ�̵�Ԫ�أ�");
				scanf("%d", &e);
				if(NextElem(L, e, next) == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(NextElem(L, e, next) == ERROR) printf("δ�ҵ���Ԫ�صĺ�̣�\n"); 
				else printf("��Ԫ�صĺ��Ϊ %d ��\n", next);    
				getchar();
				system("pause");
				break;
	    	case 8:
	    		if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫ�����Ԫ�ص�λ�ã�");
				scanf("%d", &i);
				printf("����������Ԫ�أ�");
				scanf("%d", &e);
				s = ListInsert(L, i, e);
				if(s == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(s == ERROR) printf("�����λ�ò��Ϸ���\n");
				else printf("Ԫ�ز���ɹ���\n"); 
				getchar();
				system("pause");
				break;
	    	case 9:
	    		if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("��������Ҫɾ����Ԫ�ص�λ�ã�");
				scanf("%d", &i);
				s = ListDelete(L, i, e);
				if(s == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(s == ERROR) printf("�����λ�ò��Ϸ���\n");
				else printf("Ԫ�� %d �ѳɹ������Ա���ɾ����\n", e); 
				getchar();
				system("pause");
				break;
	    	case 10:  
				if(!L) printf("���Ա����ڣ�\n");
				else if(!L->next) printf("���Ա��ǿձ�\n");
				else if(ListTraverse(L) == INFEASIBLE) printf("���Ա����ڣ�\n");
				getchar();
				system("pause");
				break;
			case 11:
				if(ReverseList(L) == INFEASIBLE) printf("���Ա����ڣ�\n");				
				else printf("���Ա��ѳɹ���ת��\n");
				getchar();
				system("pause");
				break;
			case 12:
				if(!L) printf("���Ա����ڣ�\n");
				else{
					int k;
					printf("������Ҫɾ�������ڼ�����");
					scanf("%d", &k);
					s = RemoveNthFromEnd(L, k);
					if(s == INFEASIBLE) printf("���Ա����ڣ�\n");
					else if(s == ERROR) printf("�����λ�ò��Ϸ���\n");
					else printf("��ɾ�������� %d ��Ԫ�أ�\n", k);
				}
				getchar();
				system("pause");
				break;
			case 13:
				if(SortList(L) == INFEASIBLE) printf("���Ա����ڣ�\n");
				else printf("���Ա��Ѱ��������У�\n");
				getchar();
				system("pause");
				break;
			case 14:
				if(!L){
					printf("���Ա����ڣ�\n");
					getchar();
					system("pause");
					break;
				}
				printf("�����뱣�浽���ļ�����");
				scanf("%s", filename);
				s = SaveList(L, filename);
				if(s == INFEASIBLE) printf("���Ա����ڣ�\n");
				else if(s == ERROR) printf("�ļ���ʧ�ܣ�\n");
				else printf("�ļ�����ɹ���\n");
				getchar();
				system("pause");
				break;
			case 15:
				if(!L) printf("���Ա����ڣ�\n");
				else if(L->next) printf("���Ա�Ϊ�գ�������ջ򴴽�һ���µı�\n");
				else{
					printf("������Դ�ļ�����");
					scanf("%s", filename);
					s = LoadList(L, filename);
					if(s == ERROR) printf("�ļ���ʧ�ܣ�\n");
					else printf("���Ա����ɹ���\n");
				}
				getchar();
				system("pause");
				break;
			case 0:
        		break;
		}//end of switch
	}//end of while
	op = 1;
	printf("�����Ա������ϡ�\n");
	system("pause");
	}//end of if
					else printf("����������Ϊ %s �����Ա�\n", filename);
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
