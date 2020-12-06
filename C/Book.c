  /*
	Description:ͼ�����ϵͳ 
	Author:���� 
	StartTime:2020.10.24
	EndTime:2020.10. 11.6

	Function:1.ͼ�����ϵͳ�Ļ�������
			 2.�����ļ��洢
			 3.֧���޸�����������ɫ������ɫ 
			 
	BUG: ɾ�����һ����󣬽��޷�����鼮��������      �����޸��� 
	 
	graphics.h ��ͼ�⣬ȱ�ٿ��ļ� 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <direct.h>
#define IN 1
#define OUT 0
#define VIP 1
#define NVIP 0
#define N 10
//*********ȫ�ֱ�����ṹ����****************

//	�鼮�����Զ��� (�ṹ��) 
typedef struct BookMessageManaged{
	char name[40];
	long num;
	float price;			
	int sum;
	int sellOut;
	struct BookMessageManaged *next;
}Book;

//ȫ�ֵ�����ͷβ�� 
Book *BookMesSaveHead = NULL;
Book *BookMesSaveEnd = NULL;

//�ļ�ָ�� 
FILE *LoadMesBook;

//Ĭ���˺� 
const char BookUG[N][10]={
"root","2546993153","666666"
};
const char BookPG[N][20]={
"root","wangtao","888888"
};



//*****�˵��뻶ӭ����**** 

//��ӭ���� 
void Welcome(); 
//�β˵�ͼ����Ϣ 
void BookMessageMenu();
//���˵� 
int Menu();
//�β˵�����������
void BuyBookMenu();
//ɾ��ͼ��˵��ṹ
void DelBookMenu();
//�����鼮�˵� 
void FindBookMenu();
//�޸��鼮�˵�
void ChangeBookMenu(); 



//��ӡ�Ű����
void Print(); 
//************************

//******�߼�ʵ��*********
 
//--------ͼ����Ϣ��������---------------
//����ͼ�� 
void AddBook(); 
//���ͼ�� 
void DelBook(Book *stayDel);
//�޸�ͼ�� 
void ChangeBook(Book *stayChange);
//����ͼ�����ֺ��� 
Book * FindBookName(char *name,int status);
Book * FindBookNum(long num,int status);
//һ��ͼ�� 
void AllPrint(int status);
//--------------------------------------

//����ͼ�� 
void BuyBook(int status);

//�ж�����Ƿ�Ϊ��
int BookIs(); 
//��֤��Ա
int Verification(); 



//�ļ�����
//Ԥ���� 
void PreLoad(); 
//�˳�ʱ���ݱ��� 
void ExitSave(char *path); 
//**********************
int main(){

//	������� 	
	int option = -1;
	int loadTime,start,end;
//	��ȡ����ǰ·��,�����ļ�����·�� 
	char *p = getcwd(NULL,0);
	char path[100];
	strcat(strcpy(path,p),"\\BookMessage.txt");
	start = clock();
	//�ļ�Ԥ���أ��ж��Ƿ��������. 
	printf("���ݼ���>>>>>>>>>>>>>>>\n");
	if(LoadMesBook = fopen(path,"r")){
		PreLoad();
		printf("���������ļ�\n");
	}
	else{
			printf("������");
	}
	fclose(LoadMesBook);
	end = clock();
	loadTime = end - start;
	printf("���ݼ��ع���ʱ:%g��\n",loadTime/100.0);
//	���ʵ�� 
	while(option){
		option = Menu();
		switch(option){	
//			������� 
			case 0:{
				printf("���ݱ�����,��ȴ�һ���>>>>>>>>>>>\n");
				ExitSave(path); 
				exit(0);
				break;
			}
			//ͼ�������Ϣ���� 
			case 1:{
				BookMessageMenu();					
				break;
			}
			//���������� 
			case 2:{
				if(BookIs() == 0)
					break;
				BuyBookMenu();	
				break;
			}
			//δ���� 
			case 3:{
				printf("����δ������������");
				system("echo ������˳�!! & pause>nul");
				system("cls");
				break;
			}
			default:{
				printf("�����ڴ�ѡ�������������ѡ��!!!\n\n");
				system("cls");
				break;
			}
				}
		}
	
	return 0;
}



//	��ӭ���� 
void Welcome(){
	
}

//	���˵����� 
int Menu(){
	int option = -1;
	
	printf("ͼ�鳬�й���ϵͳv1.0\n\n");
	printf("1.ͼ�������Ϣ����\n\n");
	printf("2.����������\n\n");
	printf("3.������ʷ��¼\n\n");
	printf("0.�˳�ϵͳ\n");
	
	printf("��������Ҫ���еĲ���:");
	scanf("%d",&option);
	system("cls");
	return option;
}

//	�β˵�
//  ͼ�������Ϣ 
void BookMessageMenu(){
	int option = -1;
	while(option){
	printf("ͼ�������Ϣ����\n\n");
	printf("1.����ͼ��\n\n");
	printf("2.ɾ��ͼ��\n\n");
	printf("3.�޸�ͼ��\n\n");
	printf("4.����ͼ��\n\n");
	printf("5.һ��ͼ��\n\n");
	printf("6:�����޸�\n\n");
	printf("0.������ҳ\n\n");	
	printf("��������Ҫ���еĲ���:");
	scanf("%d",&option);
	system("cls");
	switch(option){
		case 0:{
		
			break;
		}
		case 1:{
			AddBook();
			break;
		}
			
		case 2:{
			if(BookIs() == 0)
				break;
			DelBookMenu();
			break;
		}
		case 3:{
			if(BookIs() == 0)
				break;
			ChangeBookMenu();
			break;
		}
		case 4:{
			if(BookIs() == 0)
				break;
			FindBookMenu();
			break;
		}
		case 5:{
			if(BookIs() == 0)
				break;
			AllPrint(IN);	
			break;
		}
		default :{ 
			system("echo ָ�����󣡣�������������ָ���");
			system("echo ��������� & pause>nul");
			system("cls");
			break;
		}
	}
	}
}	

//-------------------------ͼ�������Ϣ����ʵ��-----------------------

//************************����ͼ��**************************************
void AddBook(){
	Book *head,*end,*point;
	
	//	��ȡ����ǰ·��,�����ļ�����·�� 
	char *p = getcwd(NULL,0);
	char path[100];
	strcat(strcpy(path,p),"\\BookMessage.txt");

	head = (Book *)malloc(sizeof(Book));
	end = head;
	LoadMesBook = fopen(path,"a");
	while(1){
//		����Head�ռ� 
		point = (Book *)malloc(sizeof(Book));
//		���ݻ�ȡ 
		printf("����������(�˳�������Exit):");
		scanf("%s",point->name);
//		�ж��Ƿ���� 
		if(strcmp(point->name,"Exit") == 0 || strcmp(point->name,"exit") == 0){
			free(point);
			system("cls");
			break;
		}
		 
		printf("��������鼮���:");
		scanf("%ld",&(point->num));
		printf("��������鼮�ۼ�:");
		scanf("%f",&(point->price));
		printf("��������鼮��������:");
		scanf("%d",&(point->sum));

//		����������Ĭ��Ϊ0 
		point->sellOut = 0;

//		���ݴ����ļ� 
		fprintf(LoadMesBook,"%s\t\t%ld\t\t%g\t\t%d\t\t%d\n",point->name,point->num,point->price,point->sum,point->sellOut);

		
//		��������
		end ->next = point;
		end = point;
		printf("��ӳɹ�����������\n");
	}
	fclose(LoadMesBook);
	end->next = NULL;
//	�ж������Ƿ����	
	if(BookMesSaveHead == NULL){
			BookMesSaveHead = head;
			BookMesSaveEnd = end;
		} 
	else{	  
			BookMesSaveEnd->next = head->next;
			BookMesSaveEnd = end; 
		}
} 

//*************************ɾ��ͼ��˵�����********************** 
void DelBookMenu(){
	int option = -1;
	while(option){
		printf("ͼ��ɾ��\n\n");
		printf("1.��������ɾ��\n");
		printf("2.���ݱ��ɾ��\n");
		printf("0.������һ��\n");	
		printf("������ѡ��:");
//		boolean = getchar();
		scanf("%d",&option);
		switch(option){
			case 0:{
				system("cls");
				break;
			}
			case 1:{
				//�ֲ�����  �������ڶ̣��ƺ����Լ����ڴ��ʹ���� 
				char name[100];
				Book *del;
				printf("��������Ҫɾ��������:");
				scanf("%s",name);
				del = FindBookName(name,OUT);
				if(del != NULL)
					DelBook(del);	
				break;
			}
			case 2:{
				long num;
				Book *del;
				printf("��������Ҫɾ������ı��:");
				scanf("%ld",&num);
				del = FindBookNum(num,OUT);
				if(del != NULL)
					DelBook(del);	
				break;
			}
			default:{
				break;
			}
		}
		
		
	}
}

//*************ɾ��ͼ��
void DelBook(Book *stayBookDel){
	Book *tureBookDel = stayBookDel->next;
	stayBookDel->next = tureBookDel->next;
	if(tureBookDel->next!=NULL)
		free(tureBookDel);
	else{
		BookMesSaveEnd = stayBookDel;
		BookMesSaveEnd  -> next = NULL;
	}
		
		
	printf("ɾ���ɹ�����\n");
	system("cls");
} 

//����ͼ��˵�
void FindBookMenu(){
	int option = -1;
	while(option){
		printf("ͼ�����\n\n");
		printf("1.��������\n");
		printf("2.��Ų���\n");
		printf("0.������һ��\n");
		
		printf("������ѡ��:"); 
		scanf("%d",&option);
		
		switch(option){
			case 0:{
				system("cls");
				break;
			}
			case 1:{ 
				char name[100];
				printf("��������Ҫ���ҵ�����:");
				scanf("%s",name);
				FindBookName(name,IN);
				break;
			}
			case 2:{
				long num;
				printf("��������Ҫ������ı��:");
				scanf("%ld",&num);
				FindBookNum(num,IN);
				break;
			}
			default:{
				break;
			}
		}
		 
	}
} 


//--------------------����ͼ��(�����޵Ļ���--------------------------------------) 

//********************��������******************************************************* 
Book * FindBookName(char *name,int status){
	Book *findOut = BookMesSaveHead->next;
	Book *findStayDel = BookMesSaveHead;
	while(findOut!=NULL && strcmp(findOut->name,name)!=0)
		if(status == OUT){
			findStayDel = findOut;
			findOut = findOut->next;
		}
		else
			findOut = findOut->next;
 
	if(status == IN){
		if(findOut == NULL){
			printf("δ�鵽�����Ƶ��鼮,�п����������������Ǵ���δ���!!!!\n");
			printf("���ղ����������Ϊ:%s\n",name);
			system("echo ��������� & pause>nul");
			system("cls");
			return NULL;
		}
//			��������������������� 
		else{
		
//		�����Ű� 
		Print();
		printf("%-18s%-18ld%-18g%-18d\n\n",findOut->name,findOut->num,findOut->price,findOut->sum);
		system("echo ������˳� & pause>nul");
		system("cls");
		return NULL;
	}	
	} 
	else
	return findStayDel;
}



//**********************��Ų���******************************************************* 
Book * FindBookNum(long num,int status){
	Book *findOut = BookMesSaveHead->next;
	Book *findStayDel = BookMesSaveHead;
	while(findOut!=NULL && findOut->num != num)
		if(status == OUT){
			findStayDel = findOut;
			findOut = findOut->next;
		}
		else
			findOut = findOut->next;
		 
	if(status == IN){
//		�����Ű� 
		if(findOut == NULL){
			printf("δ�鵽�˱�ŵ��鼮,�п��ܱ�����������Ǵ���δ���!!!!\n");
			printf("���ղ�����ı��Ϊ:%ld\n",num);
			system("echo ��������� & pause>nul");
			system("cls");
//			���������Ʊ���������
			return NULL; 
		}
		else{
//		�����Ű� 
		Print();
		printf("%-18s%-18ld%-18g%-18d\n\n",findOut->name,findOut->num,findOut->price,findOut->sum);
		system("echo ������˳� & pause>nul");
		system("cls");
		return NULL;
	}
	} 
	else
	return findStayDel;
}

//-------------------------------------------------------------------------------------- 

//�޸�ͼ��˵� 
void ChangeBookMenu(){
	int option = -1;
		while(option){
			printf("�޸�ͼ��\n\n");
			printf("1:���������޸�\n");
			printf("2:���ݱ���޸�\n");
			printf("0:������һ��\n");
			printf("������ѡ��:");
			scanf("%d",&option);
			switch(option){
				case 0:{
					system("cls");
					break;
				}
				case 1:{
					char name[100];
					printf("����������:");
					scanf("%s",name);
					system("cls");
					ChangeBook(FindBookName(name,OUT));
					break;
				}
				case 2:{
					long num;
					printf("��������ı��:");
					scanf("%ld",&num);
					system("cls");
					ChangeBook(FindBookNum(num,OUT));
					break;
				}
				default:{
					system("echo ������˳� & pause>nul");
					system("cls");	
					break;
				}
			}
		}
	
}

//�޸�ͼ��ʵ�� 
void ChangeBook(Book * stayChange){
	int option = -1;
	Book * trueChangeBook = stayChange->next;
	printf("ͼ����Ϣ�޸�\n\n");
	printf("1.ȫ���޸�\n");
	printf("2.�޸�����\n");
	printf("3.�޸ı��\n");
	printf("4.�޸ļ۸�\n");
	printf("5.�޸�����\n");
	printf("0.������һ��\n\n");
	printf("������ѡ��:");
	scanf("%d",&option);
		switch(option){
			case 0:{
				ChangeBookMenu(); 
				break;
			}
			case 1:{
				char name[100];
				long num;
				float price;
				int sum;
				
				printf("�������޸ĺ������:");
				scanf("%s",name);
				strcpy(trueChangeBook->name,name);
				printf("�������޸ĺ�ı��:");
				scanf("%ld",&num);
				trueChangeBook->num=num;
				printf("�������޸ĺ�ļ۸�:");
				scanf("%f",&price);
				trueChangeBook->price=price;
				printf("�������޸ĺ������:");
				scanf("%d",&sum);
				trueChangeBook->sum=sum; 
				system("echo �޸ĳɹ�����");
				system("echo �����������һ�� & pause >nul");
				system("cls");
				break;
			}
			case 2:{
				char name[100];
				printf("�������޸ĺ������:");
				scanf("%s",name);
				strcpy(trueChangeBook->name,name);
				break;
			}
			case 3:{
				long num;
				printf("�������޸ĺ�ı��:");
				scanf("%ld",&num);
				trueChangeBook->num=num;
				break;
			}
			case 4:{
				float price;
				printf("�������޸ĺ�ļ۸�:");
				scanf("%f",&price);
				trueChangeBook->price=price;
				break;
			}
			case 5:{
				int sum;
				printf("�������޸ĺ������:");
				scanf("%d",&sum);
				trueChangeBook->sum=sum; 
				break;
			}
			default:{
				system("echo ѡ����� & �������������ѡ�");
				system("cls");
//				ChangeBook(Book * stayChange);
				break;
			}
		}
}


//----------------------------------------------------------------------------------------------
//һ��ͼ�� 
void AllPrint(int status){
	Book *indBook = BookMesSaveHead->next;
	Print();
	while(indBook!=NULL){
		printf("\n\n%-18s%-18ld%-18g%-18d%-18d\n\n",indBook->name,indBook->num,indBook->price,indBook->sum,indBook->sellOut);
		indBook = indBook->next;
	}
	if(status == IN){
	
	system("echo ������˳���� & pause>nul");
	system("cls");
}
	
}


//-----------------------------ͼ�������Ϣʵ�ֽ�β--------------------------------------------------- 


//------------------------------�������--------------------------------------------------------------- 

// ����˵� 
void BuyBookMenu(){
	int option = -1;
		printf("������㴦��\n\n");
		printf("1.��Ա��½\n");
		printf("2.�ǻ�Ա����\n");
		printf("0.������ҳ\n");
		
		printf("��������Ҫ���еĲ���:");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 0:{
				system("cls");
				break;
			}
			case 1:{
				system("cls");
				BuyBook(VIP);
				break;
			}
			case 2:{
				system("cls");
				BuyBook(NVIP);
				break;
			}
			default:{
				
				break;
			}
		}
}

//	�鼮���� 
void BuyBook(int status){
	int option = -1;
	int show = 0;
	int buyNum;
	float paySum = 0;
	long num = -1;
	Book * buy;
	if(status == VIP){
		if(Verification()==0)
			printf("�㲻��VIP");

	else{
		printf("�Ƿ���ʾ��������鼮:(1:��ʾ-0:����ʾ)");
		scanf("%d",&show);
		if(show == 1){
			printf("��������鼮Ϊ:");
			AllPrint(OUT);
			}
		while(1){
			printf("����������Ҫ������鼮�ı��(�˳�������0):");
			scanf("%ld",&num);
			
			if(num == 0)
				break;
			buy = FindBookNum(num,OUT);
			buy = buy -> next;
			
			printf("��Ҫ���������:");
			scanf("%d",&buyNum);
			
			while(buyNum > buy->sum){
				printf("��治���������������빺������:");
				scanf("%d",&buyNum);
				if(buy->sum){
					printf("���鼮���Ϊ����!!!");
					break;
				}
			}
			
				buy->sum -= buyNum;
				buy->sellOut += buyNum;
				paySum += buyNum * buy->price * 0.8;
		}
				printf("\n������ĵ��鼮����:%gԪ",paySum);
		
	}
}
	else{
			
			while(1){
			printf("����������Ҫ������鼮�ı��(�˳�������0):");
			scanf("%ld",&num);
			
			if(num == 0)
				break;
			buy = FindBookNum(num,OUT);
			buy = buy -> next;
			
			printf("��Ҫ���������:");
			scanf("%d",&buyNum);
			
			while(buyNum > buy->sum){
				printf("��治���������������빺������:");
				scanf("%d",&buyNum);
				if(buy->sum){
					printf("���鼮���Ϊ����!!!");
					break;
				}
			}
			
				buy->sum -= buyNum;
				buy->sellOut += buyNum;
				paySum += buyNum * buy->price;
		}
				printf("\n������ĵ��鼮����:%gԪ",paySum);
		
	}
				
}
int Verification(){
	char user[10];
	char password[30];
	int idx;
	printf("�����������˻�:");
	scanf("%s",user);
	printf("��������������:");
	scanf("%s",password);
	for(idx = 0;idx < N;idx++){
		if(strcmp(BookUG[idx],user)==0 && strcmp(BookPG[idx],password)==0){
			printf("����ɹ�");
			system("echo ��������� & pause>nul");
			return VIP;
			}
		else{
			printf("����ʧ�ܣ��˺Ż�������󣡣���");
			system("echo ��������� & pause >nul");
			return NVIP; 
		}
	}
}
//�����ʽ 
void Print(){
	printf("\n%-18s%-18s%-18s%-18s%-18s","����","���","�۸�","���","ʣ��");
}
int BookIs(){
	if(BookMesSaveHead == NULL){
			printf("���û���鱾!!!������鼮!!\n");
			system("echo ��תʧ�� &pause>nul");
			system("cls");
			return 0;
}
}





//------------------�ļ�����----------------------------

//Ԥ����
void PreLoad(){
	Book *head,*end,*point;
	head = (Book *)malloc(sizeof(Book));
	end = head;
	while(!feof(LoadMesBook)){
		point = (Book *)malloc(sizeof(Book));
		fscanf(LoadMesBook,"%s\t\t%ld\t\t%g\t\t%d\t\t%d",point->name,&(point->num),&(point->price),&(point->sum),&(point->sellOut));
		end ->next = point;
		end = point;
	}
		end->next=NULL;
		BookMesSaveHead = head;
		BookMesSaveEnd = end;
}
void ExitSave(char *path){
	if((LoadMesBook = fopen(path,"w"))==NULL){
		printf("�ļ�����ʧ�ܣ���");
		fclose(LoadMesBook);
	}
	else{
		Book * point = BookMesSaveHead->next;
		while(point!=NULL){
			fprintf(LoadMesBook,"%s\t\t%ld\t\t%g\t\t%d\t\t%d\n",point->name,point->num,point->price,point->sum,point->sellOut);
			point = point ->next;
		}
	}
	fclose(LoadMesBook);
}
