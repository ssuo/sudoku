#include <stdlib.h>
#include <stdio.h>
#include <time.h>    
#include <math.h> 
#include <string.h>       

void  shudu(  )                  // 函数shudu，功能：生成1~9的排列组合后按统一模式暴力求解出数独并输出 
{int i,j,x,m;
 int a[9][9]={{2}};             //a[9][9]为数独数组 
 int b[8]={1,3,4,5,6,7,8,9};    //b[8]存放除1~9(除去首位数字2)，后续从b中取出数放入a，防止重复出现 
  

      
	 for(i=0;i<8;i++)           // 用i做for循环共做8次，填满第一行剩下的8个数 
	 {x=rand()%(8-i);           // 限制随机数的取值范围[0,8-i] 
	  a[0][i+1]=b[x];           //将随机数指向的b中的元素放入a; 
	  for(j=x;j<8-i;j++ ) 
	  b[j]=b[j+1];   }         //将b中被取出的元素后的 数依次向前挪一位，覆盖住被取出的数，避免重复。随着随机数取值范围每次减1，最后一位数下次将不会被取到，避免重复。 
	   for(m=0;m<9;m++)         
	  {
	  a[1][m]=a[0][(m+3)%9] ;   //根据已有的第一行，按照固定规则生成数独。 
	  a[2][m]=a[0][(m+6)%9] ;
	  a[3][m]=a[0][(m+1)%9] ;
	  a[4][m]=a[0][(m+4)%9] ;
	  a[5][m]=a[0][(m+7)%9] ;
	  a[6][m]=a[0][(m+2)%9] ;
	  a[7][m]=a[0][(m+5)%9] ;
	  a[8][m]=a[0][(m+8)%9] ;
	 }	
	  
	
    for(i = 0; i < 9; i ++)
    {
	  for(j = 0; j < 9; j ++)
        printf("%d",a[i][j]);//输出数独 
        printf("\n");
    }
   printf("\n"); 
   
}






int main(int argc,char **argv)
{
	srand( (unsigned)time( NULL ) );
	int i,k;
    int n=atoi(argv[argc - 1]);         //将文件字符参数转化为数字参数。 

	freopen("sudoku.txt","w",stdout);   //将结果输出到对应txt文件中。 
	if(n>0&&n<40320)                    //检验输入值是否合法。 
	{
	for(k=0;k<n;k++)                    //用循环多次调用函数shudu来生成数独。 
    shudu();
	}
	else 
	printf("输入的数据不合法"); 

	return 0;

}


