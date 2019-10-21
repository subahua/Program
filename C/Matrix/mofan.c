#include <stdio.h>
int main(){
	//row:行(i为特殊情况下的备份值)  col:列(j与i作用一致),数组初始化为0
	int row,col,a[100][100] = {
		0
	},n,index,i,j;
	//n为n*n阶魔方阵
	scanf("%d",&n);
	
	row = 0;
	col = n/2;
	//第一行最中间为1
	a[row][col] = 1;
	//从数值2开始填入
	for(index = 2;index<=n*n;index++)
	{
		//防止特殊情况备份row，col的坐标
		i = row;
		j = col;
		//每行为上次行坐标向上移动1位(row-1),列坐标移动向右移动1位(col+1)
		row = row-1;
		col = col+1;
		// 当上次行坐标为第一行时,本次行即移至最后一行
		if(row==-1)
			row = row+n;
		//当上次列坐标为最后一列时，本次即移至第一列
		if(col==n)
			col = col-n;
		//当本次坐标有已经有数值占位时,行坐标向下移动1位,列坐标不变
		if(a[row][col]!=0)
		{
			row = i;
			col = j;
			row = row+1;
			if(row==n)
				row = row-n;
		}
		a[row][col] = index;
	}
	//输出
	for(row = 0;row<n;row++)
		for(col = 0;col<n;col++)
		if(col+1==n)
		printf("%6d\n",a[row][col]);
	else
		printf("%6d",a[row][col]);
	return 0;
	
}