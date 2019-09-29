#include <stdio.h>
 int main(){
	int a,b,c,n=0;
	for(a = 1;a <= 5;a++)
		for(b = 1;b <= 5;b++)
			for(c = 1;c <= 5 && a != b;c++)
				if( a != c && b != c)
				{
				n++;
				printf("A:%d,B:%d,C:%d\n",a,b,c);
				}
		printf("Total:%d",n);

	
	}
