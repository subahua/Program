  /*
	Description:图书管理系统 
	Author:王涛 
	StartTime:2020.10.24
	EndTime:2020.10. 11.6

	Function:1.图书管理系统的基本功能
			 2.采用文件存储
			 3.支持修改主题字体颜色背景颜色 
			 
	BUG: 删除最后一本书后，将无法添加书籍！！！！      （已修复） 
	 
	graphics.h 绘图库，缺少库文件 
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
//*********全局变量与结构变量****************

//	书籍的属性定义 (结构体) 
typedef struct BookMessageManaged{
	char name[40];
	long num;
	float price;			
	int sum;
	int sellOut;
	struct BookMessageManaged *next;
}Book;

//全局单链表头尾部 
Book *BookMesSaveHead = NULL;
Book *BookMesSaveEnd = NULL;

//文件指针 
FILE *LoadMesBook;

//默认账号 
const char BookUG[N][10]={
"root","2546993153","666666"
};
const char BookPG[N][20]={
"root","wangtao","888888"
};



//*****菜单与欢迎界面**** 

//欢迎函数 
void Welcome(); 
//次菜单图书信息 
void BookMessageMenu();
//主菜单 
int Menu();
//次菜单购书结果处理
void BuyBookMenu();
//删除图书菜单结构
void DelBookMenu();
//查找书籍菜单 
void FindBookMenu();
//修改书籍菜单
void ChangeBookMenu(); 



//打印排版界面
void Print(); 
//************************

//******逻辑实现*********
 
//--------图像信息基本管理---------------
//增加图书 
void AddBook(); 
//输出图书 
void DelBook(Book *stayDel);
//修改图书 
void ChangeBook(Book *stayChange);
//查找图书两种函数 
Book * FindBookName(char *name,int status);
Book * FindBookNum(long num,int status);
//一览图书 
void AllPrint(int status);
//--------------------------------------

//购买图书 
void BuyBook(int status);

//判断书库是否为空
int BookIs(); 
//认证会员
int Verification(); 



//文件处理
//预加载 
void PreLoad(); 
//退出时数据保存 
void ExitSave(char *path); 
//**********************
int main(){

//	定义变量 	
	int option = -1;
	int loadTime,start,end;
//	获取程序当前路径,构建文件数据路径 
	char *p = getcwd(NULL,0);
	char path[100];
	strcat(strcpy(path,p),"\\BookMessage.txt");
	start = clock();
	//文件预加载，判断是否存有数据. 
	printf("数据加载>>>>>>>>>>>>>>>\n");
	if(LoadMesBook = fopen(path,"r")){
		PreLoad();
		printf("存在数据文件\n");
	}
	else{
			printf("无数据");
	}
	fclose(LoadMesBook);
	end = clock();
	loadTime = end - start;
	printf("数据加载共耗时:%g秒\n",loadTime/100.0);
//	框架实现 
	while(option){
		option = Menu();
		switch(option){	
//			程序结束 
			case 0:{
				printf("数据保存中,请等待一会儿>>>>>>>>>>>\n");
				ExitSave(path); 
				exit(0);
				break;
			}
			//图书基本信息管理 
			case 1:{
				BookMessageMenu();					
				break;
			}
			//购书结果处理 
			case 2:{
				if(BookIs() == 0)
					break;
				BuyBookMenu();	
				break;
			}
			//未开放 
			case 3:{
				printf("功能未开发！！！！");
				system("echo 任意键退出!! & pause>nul");
				system("cls");
				break;
			}
			default:{
				printf("不存在此选项，请您重新输入选项!!!\n\n");
				system("cls");
				break;
			}
				}
		}
	
	return 0;
}



//	欢迎界面 
void Welcome(){
	
}

//	主菜单界面 
int Menu(){
	int option = -1;
	
	printf("图书超市管理系统v1.0\n\n");
	printf("1.图书基本信息管理\n\n");
	printf("2.购书结果处理\n\n");
	printf("3.售书历史记录\n\n");
	printf("0.退出系统\n");
	
	printf("请输入您要进行的操作:");
	scanf("%d",&option);
	system("cls");
	return option;
}

//	次菜单
//  图书基本信息 
void BookMessageMenu(){
	int option = -1;
	while(option){
	printf("图书基本信息管理\n\n");
	printf("1.增加图书\n\n");
	printf("2.删除图书\n\n");
	printf("3.修改图书\n\n");
	printf("4.查找图书\n\n");
	printf("5.一览图书\n\n");
	printf("6:主题修改\n\n");
	printf("0.返回首页\n\n");	
	printf("请输入您要进行的操作:");
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
			system("echo 指令有误！！！请重新输入指令！！");
			system("echo 任意键继续 & pause>nul");
			system("cls");
			break;
		}
	}
	}
}	

//-------------------------图书基本信息功能实现-----------------------

//************************增加图书**************************************
void AddBook(){
	Book *head,*end,*point;
	
	//	获取程序当前路径,构建文件数据路径 
	char *p = getcwd(NULL,0);
	char path[100];
	strcat(strcpy(path,p),"\\BookMessage.txt");

	head = (Book *)malloc(sizeof(Book));
	end = head;
	LoadMesBook = fopen(path,"a");
	while(1){
//		创建Head空间 
		point = (Book *)malloc(sizeof(Book));
//		数据获取 
		printf("请输入书名(退出请输入Exit):");
		scanf("%s",point->name);
//		判断是否结束 
		if(strcmp(point->name,"Exit") == 0 || strcmp(point->name,"exit") == 0){
			free(point);
			system("cls");
			break;
		}
		 
		printf("请输入此书籍编号:");
		scanf("%ld",&(point->num));
		printf("请输入此书籍售价:");
		scanf("%f",&(point->price));
		printf("请输入此书籍现有数量:");
		scanf("%d",&(point->sum));

//		售卖的数量默认为0 
		point->sellOut = 0;

//		数据存入文件 
		fprintf(LoadMesBook,"%s\t\t%ld\t\t%g\t\t%d\t\t%d\n",point->name,point->num,point->price,point->sum,point->sellOut);

		
//		链表生成
		end ->next = point;
		end = point;
		printf("添加成功！！！！！\n");
	}
	fclose(LoadMesBook);
	end->next = NULL;
//	判断链表是否存在	
	if(BookMesSaveHead == NULL){
			BookMesSaveHead = head;
			BookMesSaveEnd = end;
		} 
	else{	  
			BookMesSaveEnd->next = head->next;
			BookMesSaveEnd = end; 
		}
} 

//*************************删除图书菜单功能********************** 
void DelBookMenu(){
	int option = -1;
	while(option){
		printf("图书删除\n\n");
		printf("1.根据书名删除\n");
		printf("2.根据编号删除\n");
		printf("0.返回上一级\n");	
		printf("请输入选项:");
//		boolean = getchar();
		scanf("%d",&option);
		switch(option){
			case 0:{
				system("cls");
				break;
			}
			case 1:{
				//局部变量  生存周期短，似乎可以减少内存的使用量 
				char name[100];
				Book *del;
				printf("请输入您要删除的书名:");
				scanf("%s",name);
				del = FindBookName(name,OUT);
				if(del != NULL)
					DelBook(del);	
				break;
			}
			case 2:{
				long num;
				Book *del;
				printf("请输入您要删除的书的编号:");
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

//*************删除图书
void DelBook(Book *stayBookDel){
	Book *tureBookDel = stayBookDel->next;
	stayBookDel->next = tureBookDel->next;
	if(tureBookDel->next!=NULL)
		free(tureBookDel);
	else{
		BookMesSaveEnd = stayBookDel;
		BookMesSaveEnd  -> next = NULL;
	}
		
		
	printf("删除成功！！\n");
	system("cls");
} 

//查找图书菜单
void FindBookMenu(){
	int option = -1;
	while(option){
		printf("图书查找\n\n");
		printf("1.书名查找\n");
		printf("2.编号查找\n");
		printf("0.返回上一级\n");
		
		printf("请输入选项:"); 
		scanf("%d",&option);
		
		switch(option){
			case 0:{
				system("cls");
				break;
			}
			case 1:{ 
				char name[100];
				printf("请输入您要查找的书名:");
				scanf("%s",name);
				FindBookName(name,IN);
				break;
			}
			case 2:{
				long num;
				printf("请输入您要查找书的编号:");
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


//--------------------查找图书(增与修的基本--------------------------------------) 

//********************书名查找******************************************************* 
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
			printf("未查到此名称的书籍,有可能名称输入错误或是此书未添加!!!!\n");
			printf("您刚才输入的书名为:%s\n",name);
			system("echo 任意键继续 & pause>nul");
			system("cls");
			return NULL;
		}
//			想增加相似书名输出功能 
		else{
		
//		界面排版 
		Print();
		printf("%-18s%-18ld%-18g%-18d\n\n",findOut->name,findOut->num,findOut->price,findOut->sum);
		system("echo 任意键退出 & pause>nul");
		system("cls");
		return NULL;
	}	
	} 
	else
	return findStayDel;
}



//**********************编号查找******************************************************* 
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
//		界面排版 
		if(findOut == NULL){
			printf("未查到此编号的书籍,有可能编号输入错误或是此书未添加!!!!\n");
			printf("您刚才输入的编号为:%ld\n",num);
			system("echo 任意键继续 & pause>nul");
			system("cls");
//			想增加相似编号输出功能
			return NULL; 
		}
		else{
//		界面排版 
		Print();
		printf("%-18s%-18ld%-18g%-18d\n\n",findOut->name,findOut->num,findOut->price,findOut->sum);
		system("echo 任意键退出 & pause>nul");
		system("cls");
		return NULL;
	}
	} 
	else
	return findStayDel;
}

//-------------------------------------------------------------------------------------- 

//修改图书菜单 
void ChangeBookMenu(){
	int option = -1;
		while(option){
			printf("修改图书\n\n");
			printf("1:根据书名修改\n");
			printf("2:根据编号修改\n");
			printf("0:返回上一级\n");
			printf("请输入选项:");
			scanf("%d",&option);
			switch(option){
				case 0:{
					system("cls");
					break;
				}
				case 1:{
					char name[100];
					printf("请输入书名:");
					scanf("%s",name);
					system("cls");
					ChangeBook(FindBookName(name,OUT));
					break;
				}
				case 2:{
					long num;
					printf("请输入书的编号:");
					scanf("%ld",&num);
					system("cls");
					ChangeBook(FindBookNum(num,OUT));
					break;
				}
				default:{
					system("echo 任意键退出 & pause>nul");
					system("cls");	
					break;
				}
			}
		}
	
}

//修改图书实现 
void ChangeBook(Book * stayChange){
	int option = -1;
	Book * trueChangeBook = stayChange->next;
	printf("图书信息修改\n\n");
	printf("1.全部修改\n");
	printf("2.修改书名\n");
	printf("3.修改编号\n");
	printf("4.修改价格\n");
	printf("5.修改数量\n");
	printf("0.返回上一级\n\n");
	printf("请输入选项:");
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
				
				printf("请输入修改后的书名:");
				scanf("%s",name);
				strcpy(trueChangeBook->name,name);
				printf("请输入修改后的编号:");
				scanf("%ld",&num);
				trueChangeBook->num=num;
				printf("请输入修改后的价格:");
				scanf("%f",&price);
				trueChangeBook->price=price;
				printf("请输入修改后的数量:");
				scanf("%d",&sum);
				trueChangeBook->sum=sum; 
				system("echo 修改成功！！");
				system("echo 任意键返回上一级 & pause >nul");
				system("cls");
				break;
			}
			case 2:{
				char name[100];
				printf("请输入修改后的书名:");
				scanf("%s",name);
				strcpy(trueChangeBook->name,name);
				break;
			}
			case 3:{
				long num;
				printf("请输入修改后的编号:");
				scanf("%ld",&num);
				trueChangeBook->num=num;
				break;
			}
			case 4:{
				float price;
				printf("请输入修改后的价格:");
				scanf("%f",&price);
				trueChangeBook->price=price;
				break;
			}
			case 5:{
				int sum;
				printf("请输入修改后的数量:");
				scanf("%d",&sum);
				trueChangeBook->sum=sum; 
				break;
			}
			default:{
				system("echo 选项错误 & 任意键重新输入选项！");
				system("cls");
//				ChangeBook(Book * stayChange);
				break;
			}
		}
}


//----------------------------------------------------------------------------------------------
//一览图书 
void AllPrint(int status){
	Book *indBook = BookMesSaveHead->next;
	Print();
	while(indBook!=NULL){
		printf("\n\n%-18s%-18ld%-18g%-18d%-18d\n\n",indBook->name,indBook->num,indBook->price,indBook->sum,indBook->sellOut);
		indBook = indBook->next;
	}
	if(status == IN){
	
	system("echo 任意键退出浏览 & pause>nul");
	system("cls");
}
	
}


//-----------------------------图书基本信息实现结尾--------------------------------------------------- 


//------------------------------购书结算--------------------------------------------------------------- 

// 购书菜单 
void BuyBookMenu(){
	int option = -1;
		printf("购书结算处理\n\n");
		printf("1.会员登陆\n");
		printf("2.非会员进入\n");
		printf("0.返回首页\n");
		
		printf("请输入您要进行的操作:");
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

//	书籍购买 
void BuyBook(int status){
	int option = -1;
	int show = 0;
	int buyNum;
	float paySum = 0;
	long num = -1;
	Book * buy;
	if(status == VIP){
		if(Verification()==0)
			printf("你不是VIP");

	else{
		printf("是否显示书馆现有书籍:(1:显示-0:不显示)");
		scanf("%d",&show);
		if(show == 1){
			printf("书馆现有书籍为:");
			AllPrint(OUT);
			}
		while(1){
			printf("请你输入你要购买的书籍的编号(退出请输入0):");
			scanf("%ld",&num);
			
			if(num == 0)
				break;
			buy = FindBookNum(num,OUT);
			buy = buy -> next;
			
			printf("您要购买的数量:");
			scanf("%d",&buyNum);
			
			while(buyNum > buy->sum){
				printf("库存不够，请您重新输入购买数量:");
				scanf("%d",&buyNum);
				if(buy->sum){
					printf("此书籍库存为空了!!!");
					break;
				}
			}
			
				buy->sum -= buyNum;
				buy->sellOut += buyNum;
				paySum += buyNum * buy->price * 0.8;
		}
				printf("\n您购买的的书籍共需:%g元",paySum);
		
	}
}
	else{
			
			while(1){
			printf("请你输入你要购买的书籍的编号(退出请输入0):");
			scanf("%ld",&num);
			
			if(num == 0)
				break;
			buy = FindBookNum(num,OUT);
			buy = buy -> next;
			
			printf("您要购买的数量:");
			scanf("%d",&buyNum);
			
			while(buyNum > buy->sum){
				printf("库存不够，请您重新输入购买数量:");
				scanf("%d",&buyNum);
				if(buy->sum){
					printf("此书籍库存为空了!!!");
					break;
				}
			}
			
				buy->sum -= buyNum;
				buy->sellOut += buyNum;
				paySum += buyNum * buy->price;
		}
				printf("\n您购买的的书籍共需:%g元",paySum);
		
	}
				
}
int Verification(){
	char user[10];
	char password[30];
	int idx;
	printf("请输入您的账户:");
	scanf("%s",user);
	printf("请输入您的密码:");
	scanf("%s",password);
	for(idx = 0;idx < N;idx++){
		if(strcmp(BookUG[idx],user)==0 && strcmp(BookPG[idx],password)==0){
			printf("登入成功");
			system("echo 任意键继续 & pause>nul");
			return VIP;
			}
		else{
			printf("登入失败，账号或密码错误！！！");
			system("echo 任意键继续 & pause >nul");
			return NVIP; 
		}
	}
}
//输出样式 
void Print(){
	printf("\n%-18s%-18s%-18s%-18s%-18s","名称","编号","价格","库存","剩余");
}
int BookIs(){
	if(BookMesSaveHead == NULL){
			printf("书库没有书本!!!请添加书籍!!\n");
			system("echo 跳转失败 &pause>nul");
			system("cls");
			return 0;
}
}





//------------------文件处理----------------------------

//预加载
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
		printf("文件创建失败！！");
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
