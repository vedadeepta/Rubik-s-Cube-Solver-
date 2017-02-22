#include <stdio.h>
#include <string.h>
#include <time.h>
#define cyclic 1
#define acyclic 0
extern void doMoves(char[],int);
extern char a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],f[3][3];
extern scanCube();
extern printCube();
void swapSides()
{
	char temp[3][3];
	int i=0,j=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp[i][j]=a[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=b[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=2;j>=0;j--)
		{
			b[i][2-j]=c[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=d[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=2;j>=0;j--)
		{
			d[i][2-j]=temp[i][j];
		}
	}
}
void permute(char ch)
{
	if(ch=='T')
	{
		while(1)
		{
			if(a[0][0]==a[1][1] && d[0][0]==d[1][1] && d[0][2]==d[1][1] && c[0][0]==c[1][1])
				break;
			printf("rotate cube\n");
			swapSides();
		}
		printf("(R U Rp Up)(Rp F)(R2 Up Rp) Up (R U Rp Fp)\n");
		doMoves("RU020FRR202RU04",1);
	}
	else if(ch=='Y')
	{
		while(1)
		{
			if(a[0][0]==a[1][1] && d[0][0]==d[1][1] && b[0][2]==b[1][1] && c[0][2]==c[1][1])
				break;
			printf("rotate cube\n");
			swapSides();
		}
		printf("(F R Up Rp Up)(R U Rp Fp)(R U Rp Up)(Rp F R Fp)\n");
		doMoves("FR202RU04RU020FR4",1);
	}
	else if(ch==cyclic)
	{
		while(1)
		{
			if(c[0][1]==c[1][1])
				break;
			printf("rotate cube\n");
			swapSides();
		}
		if(a[0][1]==d[1][1] && d[0][1]==b[1][1] &&b[0][1]==a[1][1])
		{
			printf("R2 U R U (Rp Up)x2 Rp U Rp\n");
			doMoves("RRURU02020U0",1);
		}
		else
		{
			printf("R Up (R U)x2 R Up Rp Up Rp Rp\n");
			doMoves("R2RURUR20200",1);
		}
	}
	else if(ch==acyclic)
	{
		while(1)
		{
			if(a[0][1]==b[1][1] || a[0][1]==c[1][1])
				break;
			printf("rotate cube\n");
			swapSides();
		}
		if(a[0][1]==b[1][1])
		{
			printf("M2 U M2 U Mp U2 M2 U2 Mp U2\n");
			doMoves("11RRD11RRU0LDD11RRDD0LFF",1);
			doMoves("RRUU",2);
		}
		else
		{
			printf("M2 U M2 U2 M2 U M2\n");
			doMoves("00LLD00LLUU00LLD00LL",1);

		}
	}
}
void actionPos()
{
	while(1)
	{
		if((a[0][0]=='o' && d[0][0]=='g' && b[0][2]=='b' && c[0][2]=='r'
			&& a[0][2]!='o' && b[0][0]!='b' && d[0][2]!='g' && c[0][0]!='r') ||
			(a[0][0]!='o' && d[0][0]!='g' && b[0][2]!='b' && c[0][2]!='r'
			&& a[0][2]=='o' && b[0][0]=='b' && d[0][2]=='g' && c[0][0]=='r'))
		{
			permute('Y');
			break;
		}
		else if((a[0][0]=='o' && d[0][0]=='g' && d[0][2]=='g' && c[0][0]=='r'
			     && a[0][2]!='o' && b[0][0]!='b' && b[0][2]!='b' && c[0][2]!='r')||
			     
			     (a[0][0]=='o' && d[0][0]=='g' && d[0][2]!='g' && c[0][0]!='r'
			     && a[0][2]=='o' && b[0][0]=='b' && b[0][2]!='b' && c[0][2]!='r')||

			     (a[0][0]!='o' && d[0][0]!='g' && d[0][2]!='g' && c[0][0]!='r'
			      && a[0][2]=='o' && b[0][0]=='b' && b[0][2]=='b' && c[0][2]=='r')||

			      (a[0][0]!='o' && d[0][0]!='g' && d[0][2]=='g' && c[0][0]=='r'
			      && a[0][2]!='o' && b[0][0]!='b' && b[0][2]=='b' && c[0][2]=='r'))
		{
			permute('T');
			break;
		}
		else if(a[0][0]==a[1][1] && d[0][0]==d[1][1] && d[0][2]==d[1][1] && c[0][0]==c[1][1]
			     && a[0][2]==a[1][1] && b[0][0]==b[1][1] && b[0][2]==b[1][1] && c[0][2]==c[1][1])
		{
			if(c[0][1]!=c[1][1] && a[0][1]!=a[1][1] && b[0][1]!=b[1][1] && d[0][1]!=d[1][1])
				permute(acyclic);
			else
				permute(cyclic);
			break;
		}
		printf("U");
		doMoves("U",1);
	}
}
int check_pll()
{
	int i=0;
	for(i=0;i<3;i++)
	{
		if(a[0][i]!=a[1][1] || b[0][i]!=b[1][1] || c[0][i]!=c[1][1] || d[0][i]!=d[1][1])
			return 0;		
	}
	return 1;
}
void pll()
{
	while(check_pll()!=1)
	{
		actionPos();
	}
}
int main()
{
	clock_t tic,toc;
	tic=clock();
	scanCube();
	solveLowerEdges();
	printf("-----------lower edges complete-------\n");
	solveLowerCorners();
	printf("-------first layer complete-----------\n");
	solveMiddleEdges();
	printf("-------second layer complete----------\n");
	oll();
	printf("--------orientation complete-----------\n");
	pll();
	printf("--------cube solved!!-----------\n");
	toc=clock();
	printf("time taken = %f",(double)((toc-tic)/CLOCKS_PER_SEC));
	getch();
	return 0;
}