#include <stdio.h>
  int main(){
	double x = 0.0,y = 0.0;
	
	printf("*****求商与余数*****\n");
  printf("浮点型无求余，计算求余结果已经进行强制类型转换!!!!\n");
	printf("请输入X与Y的值:\n");
	printf("X:");
	scanf("%lf",&x);
	printf("\nY:");
	scanf("%lf",&y);

	printf("\n\n*****X / Y ****\n");
  printf("X / Y = %.2lf\n",x / y);
	printf("*****X %% Y ****\n");
  printf("X %% Y =%d\n",(int)x % (int)y);
	
  printf("\n\n\n");

	printf("*****Y / X ****\n");
	printf("Y / X = %.2lf\n",y / x);
	printf("*****Y %% X ****\n");
	printf("Y %% X = %d\n",(int)y % (int)x);
	
	return 0;
	}	
