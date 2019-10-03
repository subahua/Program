#include <stdio.h>
int main(){
	int array[100][100];
	// col:行 row:列
	int row = 0,col = 0,row_index = 0,col_index = 0;
	int n = 0;
	int i = 2;
	printf("请输入一个奇数(n):");
	scanf("%d",&n);
	//第一行中间为1
	row = (n-1)/2;
	array[col][row] = 1;
	
	for(;i<=n*n;i++){
		
		col_index = col;
		row_index = row;
		col = col-1;
		row = row+1;
		
		if(col<0)
			col = col+n;
		if(row>=n)
			row = row-n;
		
		if(array[col][row]==0)
			array[col][row] = i;
		else{
			row = row_index;
			col = col_index;
			col = col+1;
			if(col>=n)
				col = col-n;
			array[col][row] = i;
			
		}
	}
	for(row = 0;row<n;row++)
		for(col = 0;col<n;col++)
		if((col+1)%n==0)
		printf("%5d\n",array[row][col]);
	else
		printf("%5d",array[row][col]);
	return 0;
}
/*　奇阶魔方阵的排列方法：
	col:行 row:列
　　⑴将1放在第一行中间一列；

　　⑵从2开始直到n×n止各数依次按下列规则存放；每一个数存放的行比前一个数的行数减1，列数加1；

　　⑶如果上一个数的行数为1，则下一个数的行数为n（指最下一行）；

　　⑷当上一个数的列数为n时，下一个数的列数应为1，行数减去1；

　　⑸如果按上面规则确定的位置上已有数，或上一个数是第一行第n列时，则把下一个数放在上一个数的下面。

*/