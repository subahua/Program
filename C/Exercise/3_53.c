#include <stdio.h>
//常量定义
#define PI 3.14
    int main(){
    //变量定义
		double r = 0.0, h = 0.0;
    double cl = 0.0,cs = 0.0,cvz = 0.0;
    //数值输入
		printf("*****计算圆周长and面积与圆柱体积*****\n");
		printf("请输入半径(R)与高(H):\n");
		printf("半径(R)=");
		scanf("%lf",&r);
		printf("高(H)=");
		scanf("%lf",&h);
    //数值计算
		cl = 2 * r * PI;
		cs = r * r * PI;
		cvz = cs * h;
    //输出结果
		printf("圆周长:%g\n圆面积:%g\n圆柱体积:%g",cl,cs,cvz);
		return 0;
		}
