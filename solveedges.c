#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define notPrime 1
#define Prime 0
char p[8],q[8],r[8],s[12],t[12];
//char *storeMoves=(char *)malloc(sizeof(char*)*10);
extern char a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],f[3][3];
extern void rotate90();
extern void rotate90_anti();
extern void front_a();
extern void frontp_a();
extern void front_b();
extern void frontp_b();
extern void front_c();
extern void frontp_c();
extern void front_c();
extern void frontp_c();
extern void up();
extern void upp();
extern void down();
extern void downp();
extern void scanCube();
extern void printCube();
void cyclePositions(int i)
{	
	if(i==1)
	{
		p[0]=a[1][0]; p[1]=d[1][0];//p1
		p[2]=a[1][2]; p[3]=b[1][0];//p2
		p[4]=b[1][2]; p[5]=c[1][2];//p3
		p[6]=d[1][2]; p[7]=c[1][0];//p4

		q[0]=f[2][1]; q[1]=a[0][1];//q1
		q[2]=f[1][2]; q[3]=b[0][1];//q2
		q[4]=f[0][1]; q[5]=c[0][1];//q3
		q[6]=f[1][0]; q[7]=d[0][1];//q4

		r[0]=e[2][1]; r[1]=a[2][1];
		r[2]=e[1][2]; r[3]=b[2][1];
		r[4]=e[0][1]; r[5]=c[2][1];
		r[6]=e[1][0]; r[7]=d[2][1];

		s[0]=a[2][2];s[1]=b[2][0];s[2]=e[2][2];
		s[3]=b[2][2];s[4]=c[2][2];s[5]=e[0][2];
		s[6]=c[2][0];s[7]=d[2][2];s[8]=e[0][0];
		s[9]=d[2][0];s[10]=a[2][0];s[11]=e[2][0];

		t[0]=a[0][2];t[1]=b[0][0];t[2]=f[2][2];
		t[3]=b[0][2];t[4]=c[0][2];t[5]=f[0][2];
		t[6]=c[0][0];t[7]=d[0][2];t[8]=f[0][0];
		t[9]=d[0][0];t[10]=a[0][0];t[11]=f[2][0];
	}
	if(i==2)
	{
		p[0]=a[1][2]; p[1]=b[1][0];//p1
		p[2]=b[1][2]; p[3]=c[1][2];//p2
		p[4]=d[1][2]; p[5]=c[1][0];//p3
		p[6]=a[1][0]; p[7]=d[1][0];//p4

		q[0]=f[1][2]; q[1]=b[0][1];//q1
		q[2]=f[0][1]; q[3]=c[0][1];//q2
		q[4]=f[1][0]; q[5]=d[0][1];//q3
		q[6]=f[2][1]; q[7]=a[0][1];//q4

		r[0]=e[1][2]; r[1]=b[2][1];
		r[2]=e[0][1]; r[3]=c[2][1];
		r[4]=e[1][0]; r[5]=d[2][1];
		r[6]=e[2][1]; r[7]=a[2][1];

		s[0]=b[2][2];s[1]=c[2][2];s[2]=e[0][2];
		s[3]=c[2][0];s[4]=d[2][2];s[5]=e[0][0];
		s[6]=d[2][0];s[7]=a[2][0];s[8]=e[2][0];
		s[9]=a[2][2];s[10]=b[2][0];s[11]=e[2][2];

		t[9]=a[0][2];t[10]=b[0][0];t[11]=f[2][2];
		t[0]=b[0][2];t[1]=c[0][2];t[2]=f[0][2];
		t[3]=c[0][0];t[4]=d[0][2];t[5]=f[0][0];
		t[6]=d[0][0];t[7]=a[0][0];t[8]=f[2][0];
	}
	if(i==3)
	{
		p[0]=b[1][2]; p[1]=c[1][2];//p1
		p[2]=d[1][2]; p[3]=c[1][0];//p2
		p[4]=a[1][0]; p[5]=d[1][0];//p3
		p[6]=a[1][2]; p[7]=b[1][0];//p4

		q[0]=f[0][1]; q[1]=c[0][1];
		q[2]=f[1][0]; q[3]=d[0][1];
		q[4]=f[2][1]; q[5]=a[0][1];
		q[6]=f[1][2]; q[7]=b[0][1];

		r[0]=e[0][1]; r[1]=c[2][1];
		r[2]=e[1][0]; r[3]=d[2][1];
		r[4]=e[2][1]; r[5]=a[2][1];
		r[6]=e[1][2]; r[7]=b[2][1];

		s[0]=c[2][0];s[1]=d[2][2];s[2]=e[0][0];
		s[3]=d[2][0];s[4]=a[2][0];s[5]=e[2][0];
		s[6]=a[2][2];s[7]=b[2][0];s[8]=e[2][2];
		s[9]=b[2][2];s[10]=c[2][2];s[11]=e[0][2];

		t[6]=a[0][2];t[7]=b[0][0];t[8]=f[2][2];
		t[9]=b[0][2];t[10]=c[0][2];t[11]=f[0][2];
		t[0]=c[0][0];t[1]=d[0][2];t[2]=f[0][0];
		t[3]=d[0][0];t[4]=a[0][0];t[5]=f[2][0];

	}
	if(i==4)
	{
		p[0]=d[1][2]; p[1]=c[1][0];//p1
		p[2]=a[1][0]; p[3]=d[1][0];//p2
		p[4]=a[1][2]; p[5]=b[1][0];//p3
		p[6]=b[1][2]; p[7]=c[1][2];//p4

		q[0]=f[1][0]; q[1]=d[0][1];
		q[2]=f[2][1]; q[3]=a[0][1];
		q[4]=f[1][2]; q[5]=b[0][1];
		q[6]=f[0][1]; q[7]=c[0][1];

		r[0]=e[1][0]; r[1]=d[2][1];
		r[2]=e[2][1]; r[3]=a[2][1];
		r[4]=e[1][2]; r[5]=b[2][1];
		r[6]=e[0][1]; r[7]=c[2][1];

		s[0]=d[2][0];s[1]=a[2][0];s[2]=e[2][0];
		s[3]=a[2][2];s[4]=b[2][0];s[5]=e[2][2];
		s[6]=b[2][2];s[7]=c[2][2];s[8]=e[0][2];
		s[9]=c[2][0];s[10]=d[2][2];s[11]=e[0][0];

		t[3]=a[0][2];t[4]=b[0][0];t[5]=f[2][2];
		t[6]=b[0][2];t[7]=c[0][2];t[8]=f[0][2];
		t[9]=c[0][0];t[10]=d[0][2];t[11]=f[0][0];
		t[0]=d[0][0];t[1]=a[0][0];t[2]=f[2][0];

	}
}
void moveFace(int dir,int face)
{
	if(dir==Prime)
	{
		switch(face)
		{
			case 1:
				frontp_a();
				break;
			case 2:
				frontp_b();
				break;
			case 3:
				frontp_c();
				break;
			case 4:
				frontp_d();
				break;
		}
	}
	else
	{
		switch(face)
		{
			case 1:
				front_a();
				break;
			case 2:
				front_b();
				break;
			case 3:
				front_c();
				break;
			case 4:
				front_d();
				break;
			
		}
	}
}
void doMoves(char storeMoves[],int x)
{
	char ch;
	int y=0,i=0;
	for(i=0;i<strlen(storeMoves);i++)
	{
		ch=storeMoves[i];
		if(ch=='R' || ch== '0')
		{
			if(x!=4)
				y=x+1;
			else 
				y=1;
			if(ch=='R')
				moveFace(notPrime,y);
			else
				moveFace(Prime,y);
		}
		if(ch=='L'||ch=='1')
		{
			if(x!=1)
				y=x-1;
			else 
				y=4;
			if(ch=='L')
				moveFace(notPrime,y);
			else
				moveFace(Prime,y);
		}
		if(ch=='F'||ch=='4')
		{
			if(ch=='F')
				moveFace(notPrime,x);
			if(ch=='4')
				moveFace(Prime,x);
		}
		if(ch=='D')
		{
			down();
			continue;
		}
		if(ch=='3')
		{
			downp();
			continue;
		}
		if(ch=='U')
		{
			up();
			continue;
		}
		if(ch=='2')
		{
			upp();
			continue;
		}
	}
}
int detO(int face)
{
	if(f[0][1]=='w'&& face==3)
		return 1;
	if(f[1][2]=='w'&& face==2)
		return 1;
	if(f[2][1]=='w'&& face==1)
		return 1;
	if(f[1][0]=='w'&& face==4)
		return 1;
	return 0;
}
void placeLowerEdges(int face)
{
	if(detO(face))
	{
		printf("F,F\n");
		doMoves("FF",face);
	}
	else
	{
		printf("Uprime,Rprime,F,R\n");
		doMoves("20FR",face);
	}
}
void solveLowerEdges()
{	
	char s,b;
	int i=0;
	b='w';
	for(i=1;i<=4;i++)
	{
		if(i==1)s='o';
		if(i==2)s='b';
		if(i==3)s='r';
		if(i==4)s='g';
		cyclePositions(i);
		if((s==p[0]&&b==p[1])||(b==p[0]&&s==p[1]))//p1
		{
			printf("Lp,Up,L\n");
			doMoves("12L",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==p[2]&&b==p[3])||(b==p[2]&&s==p[3]))//p2
		{
			printf("R,U,Rp\n");
			doMoves("RU0",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==p[4]&&b==p[5])||(b==p[4]&&s==p[5]))//p3
		{
			printf("Rp,U,R\n");
			doMoves("0UR",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==p[6]&&b==p[7])||(b==p[6]&&s==p[7]))//p4
		{
			printf("L,Up,Lp\n");
			doMoves("L21",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[0]&&b==q[1])||(b==q[0]&&s==q[1]))//q1
		{
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[2]&&b==q[3])||(b==q[2]&&s==q[3]))//q2
		{
			printf("U\n");
			doMoves("U",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[4]&&b==q[5])||(b==q[4]&&s==q[5]))//q3
		{
			printf("U,U\n");
			doMoves("UU",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==q[6]&&b==q[7])||(b==q[6]&&s==q[7]))//q4
		{
			printf("Up\n");
			doMoves("2",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==r[0]&&b==r[1])||(b==r[0]&&s==r[1]))
		{
			printf("F,F\n");
			doMoves("FF",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==r[2]&&b==r[3])||(b==r[2]&&s==r[3]))
		{
			printf("R,R,U\n");
			doMoves("RRU",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==r[4]&&b==r[5])||(b==r[4]&&s==r[5]))
		{
			printf("Dp,R,R,U,D\n");
			doMoves("3RRUD",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
		if((s==r[6]&&b==r[7])||(b==r[6]&&s==r[7]))
		{
			printf("L,L,Up,L\n");
			doMoves("LL2L",i);
			placeLowerEdges(i);
			printf("rotate cube\n");continue;
		}
	}
}
/*int main()
{
	scanCube();
	solveLowerEdges();
	return 0;
}*/


