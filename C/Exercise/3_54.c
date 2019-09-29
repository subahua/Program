#include <stdio.h>
#define EXIT '0'
   int main(){
	 char get_ascll;
	 printf("****字母ASCLL获取****\n");
   printf("请输入字母:");
	 while((get_ascll = getchar()) != EXIT)
   if(get_ascll != 10){
	 printf("你输入的字母ASCLL值为:%d\n",get_ascll);
	 printf("!!!!!退出(EXIT)请键入0!!!!!\n");
	 printf("请键入字母(0退出):");
	 }
   printf("EXIT SUCCESS");
   return 0;
	 }

