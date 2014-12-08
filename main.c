#include <stdio.h>
#include <string.h>

#define DEBUG 0


int AllDone(int a[9][9],int abscissa,int ordinate,int test);

//Horizontal 横
int Horizontal(int a[9][9],int abscissa,int ordinate,int test)
{
	int i;
	for(i=0;i<9;i++)
		if(a[abscissa][i] == test)return 0;
	return 1;
}

//Vertical
int Vertical(int a[9][9],int abscissa,int ordinate,int test)
{
	int i;
	for(i=0;i<9;i++)
		if(a[i][ordinate] == test) return 0;
	return 1;
}

//Area
int Area(int a[9][9],int abscissa,int ordinate,int test)
{
	int i,j;
	int absMin = (abscissa/3)*3;
	int absMax = (abscissa/3+1)*3;
	int ordMin = (ordinate/3)*3;
	int ordMax = (ordinate/3+1)*3;
	for(i=absMin;i<absMax;i++)
		for(j=ordMin;j<ordMax;j++)
			if(test == a[i][j]) return 0;
	return 1;
}

int AllDone(int a[9][9],int abscissa,int ordinate,int test)
{
	if(!Horizontal(a,abscissa,ordinate,test)) return 0;
	if(!Vertical(a,abscissa,ordinate,test)) return 0;
	if(!Area(a,abscissa,ordinate,test)) return 0;
	return 1;
}

int output(int a[9][9])
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 1;		
}

int SudokuCpy(int dest[9][9],int src[9][9])
{
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			dest[i][j] = src[i][j];
	return 1;
}

int nextData(int a[9][9],int offset)
{
	if(DEBUG) printf("offset: %d(a[%d][%d]): ",offset,offset/9,offset%9);
	if(offset >= 81)
	{
		if(DEBUG) printf("done\n");
		return 1;
	}
	//int ma[9][9];
	int i;
	int abs = offset/9;
	int ord = offset%9;
	//memcpy(ma,a,sizeof(int)*9*9);
	//SudokuCpy(ma,a);
	if(a[abs][ord]!=0)
	{
		if(DEBUG) printf("a[%d][%d] is %d,passed \n",abs,ord,a[abs][ord]);
		return nextData(a,offset+1);
	}
	for(i=1;i<10;i++)
	{
		if(DEBUG) printf("T:%d ",i);
		if(AllDone(a,abs,ord,i))
		{
			if(DEBUG) printf("D:%d \n",i);
			a[abs][ord] = i;
			//if(DEBUG) output(ma);
			if(nextData(a,offset+1))
			{
				if(DEBUG) printf("done\n");
				//memcpy(a,ma,sizeof(int)*9*9);
				//SudokuCpy(a,ma);
				return 1;
			}
		}
		a[abs][ord] = 0;
		if(DEBUG) printf("N ");
	}
	if(DEBUG) printf("can not get result\n");
	return 0;
}




int main()
{
	int a[9][9];
	int i;
	int j;
	memset(a,0,sizeof(a));
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(nextData(a,0))
	{
		printf("get result:\n");
		output(a);
	}else
	{
		printf("no result.\n");
	}
	return 0;
}
