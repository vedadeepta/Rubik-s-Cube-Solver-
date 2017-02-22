#include <stdio.h>
#include <string.h>
#define notPrime 1
#define Prime 0
extern solveLowerEdges();
extern char p[8],q[8],r[8],s[12],t[12];
extern char a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],f[3][3];
extern scanCube();
extern void doMoves(char[],int);
extern void cyclePositions(int);
char base,fc,rc,middle;
int presentAt(int x,int y,int z)
{
	if(x==base && y==fc && z==rc)
		return 1;
	if(x==base && y==rc && z==fc)
		return 1;
	if(x==fc && y==base && z==rc)
		return 1;
	if(x==fc && y==rc && z==base)
		return 1;
	if(x==rc && y==base && z==fc)
		return 1;
	if(x==rc && y==fc && z==base)
		return 1;
	return 0;
}
int detOc()
{
	if(base==t[0])
		return 1;
	if(base==t[1])
		return 2;
	if(base==t[2])
		return 3;
}
void placeLowerCorners(int i)
{
	if(detOc()==1)
	{
		printf("U,R,Up,Rp\n");
		doMoves("UR20",i);
	}
	if(detOc()==2)
	{
		printf("R,U,Rp\n");
		doMoves("RU0",i);
	}
	if(detOc()==3)
	{
		printf("R,U,U,Rp,Up,R,U,Rp\n");
		doMoves("RUU02RU0",i);
	}
}
void solveLowerCorners()
{
	int i=0;
	base='w';
	for(i=1;i<=4;i++)
	{
		cyclePositions(i);
		if(i==1){fc='o';rc='b';}
		if(i==2){fc='b';rc='r';}
		if(i==3){fc='r';rc='g';}
		if(i==4){fc='g';rc='o';}
		if(presentAt(s[0],s[1],s[2]))
		{
			printf("R,U,Rp,Up\n");
			doMoves("RU02",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(s[3],s[4],s[5]))
		{
			printf("Rp,U,U,R,Up\n");
			doMoves("0UUR2",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(s[6],s[7],s[8]))
		{
			printf("L,U,U,Lp\n");
			doMoves("LUU1",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(s[9],s[10],s[11]))
		{
			printf("Lp,Up,L\n");
			doMoves("12L",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(t[0],t[1],t[2]))
		{
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(t[3],t[4],t[5]))
		{
			printf("U\n");
			doMoves("U",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(t[6],t[7],t[8]))
		{
			printf("U,U\n");
			doMoves("UU",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
		if(presentAt(t[9],t[10],t[11]))
		{
			printf("Up\n");
			doMoves("2",i);
			cyclePositions(i);
			placeLowerCorners(i);
			printf("rotate cube\n");continue;
		}
	}
}
int detOm()
{
	if(middle==q[1])
		return 1;
	else 
		return 0;
}
void placeMiddleEdges(int i)
{
	if(detOm())
	{
		printf("U,R,U,Rp,Up,Fp,Up,F\n");
		doMoves("URU0242F",i);
	}
	else
	{
		printf("U,R,U,Rp,Up,Up,R,Up,Up,Rp,U,U,R,Up,Rp\n");
		doMoves("URU022R220UUR20",i);
	}
}
void solveMiddleEdges()
{
	char s,g;
	int i=0;
	for(i=1;i<=4;i++)
	{
		printf("\n");
		if(i==1){s='o';g='b'; middle=a[1][1];}
		if(i==2){s='b';g='r'; middle=b[1][1];}
		if(i==3){s='r';g='g'; middle=c[1][1];}
		if(i==4){s='g';g='o'; middle=d[1][1];}
		cyclePositions(i);
		if((s==p[0]&&g==p[1])||(g==p[0]&&s==p[1]))//p1
		{
			printf("Lp,U,L,U,Lp,U,L,Up,Lp,Up,Lp,U,U\n");
			doMoves("1ULU1UL2121UU",i);
			cyclePositions(i);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==p[2]&&g==p[3])||(g==p[2]&&s==p[3]))//p2
		{
			printf("R,Up,Rp,Up,R,Up,Rp,U,R,U,Rp,U,U\n");
			doMoves("R202R20URU0UU",i);
			cyclePositions(i);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==p[4]&&g==p[5])||(g==p[4]&&s==p[5]))//p3
		{
			printf("Rp,U,R,U,Rp,U,R,Up,Rp,Up,R\n");
			doMoves("0URU0UR202R",i);
			cyclePositions(i);
			//printf("%c \n",a[0][1]);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==p[6]&&g==p[7])||(g==p[6]&&s==p[7]))//p4
		{
			printf("L,Up,Lp,Up,L,Up,Lp,U,L,U,Lp\n");
			doMoves("L212L21ULU1",i);
			cyclePositions(i);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[0]&&g==q[1])||(g==q[0]&&s==q[1]))//q1
		{
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[2]&&g==q[3])||(g==q[2]&&s==q[3]))//q2
		{
			printf("U\n");
			doMoves("U",i);
			cyclePositions(i);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[4]&&g==q[5])||(g==q[4]&&s==q[5]))//q3
		{
			printf("U,U\n");
			doMoves("UU",i);
			cyclePositions(i);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[6]&&g==q[7])||(g==q[6]&&s==q[7]))//q4
		{
			printf("Up\n");
			doMoves("2",i);
			cyclePositions(i);
			placeMiddleEdges(i);
			printf("rotate cube\n");continue;
		}
	}
}
/*int main()
{
	scanCube();
	solveLowerEdges();
	printf("-----------lower edges complete-------\n");
	solveLowerCorners();
	printf("-------first layer complete-----------\n");
	solveMiddleEdges();
	printf("-------second layer complete----------\n");
	getch();
	return 0;
}*/