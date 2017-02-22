#include <stdio.h>
#include <string.h>
extern void doMoves(char[],int);
extern char a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],f[3][3];
extern scanCube();
void orientPattern(char ch)
{
	switch(ch)
	{
		case 'l':
			while(1)
			{
				//printf("yay");
				if(f[1][2]=='y' && f[2][1]=='y')
					break;
				printf("U");
				doMoves("U",1);
			}
			printf("f R U Rp Up fp\n");
			doMoves("RU",2);doMoves("F",4);doMoves("2",2);doMoves("4",4);doMoves("0",2);
			break;
		case 'b':
			while(1)
			{
				if(f[1][0]=='y' && f[1][2]=='y')
					break;
				printf("U");
				doMoves("U",1);
			}
			printf("F R U Rp Up Fp\n");
			doMoves("FRU024",1);
			break;
		case 'c':
			while(1)
			{
				if((d[0][0]=='y' && d[0][2]=='y' && a[0][2]=='y' && c[0][2]=='y')||
				   (a[0][0]=='y' && a[0][2]=='y' && c[0][0]=='y' && c[0][2]=='y'))
					break;
				printf("U");
				doMoves("U",1);
			}
			if(a[0][0]=='y')
			{
				printf("F (R U Rp Up)x3 Fp\n");
				doMoves("FRU02RU02RU024",1);
			}
			if(d[0][0]=='y')
			{
				printf("R U2 R2 Up R2 Up R2 U2 R\n");
				doMoves("RUURR2RR2RRUUR",1);
			}
			break;
		case 'f':
			while(1)
			{
				if((d[0][0]=='y' && d[0][2]=='y') || (a[0][0]=='y'&& c[0][0]=='y'))
					break;
				printf("U");
				doMoves("U",1);
			}
			if(d[0][0]=='y')
			{
				printf("R U Rp Up R Up Rp U2 R Up Rp U2 R U Rp\n");
				doMoves("RU02R20UUR20UURU0",1);
			}
			if(a[0][0]=='y')
			{
				printf("(r U Rp Up)(rp F R Fp)\n");
				doMoves("LF041FR4",1);
			}
			break;
		case 'd':
			while(1)
			{
				if(d[0][2]=='y' && a[0][2]=='y')
					break;
				printf("U");
				doMoves("U",1);
			}
			printf("Fp(r U Rp Up)(rp F R)\n");
			doMoves("4LF041FR",1);
			break;
		case 's':
			while(1)
			{
				if((a[0][0]=='y' && b[0][0]=='y' && d[0][2]=='y')||
				   (a[0][2]=='y' && b[0][2]=='y' && c[0][0]=='y'))
					break;
				printf("U");
				doMoves("U",1);
			}
			if(a[0][0]=='y')
			{
				printf("R U2 Rp Up R Up Rp\n");
				doMoves("RUU02R20",1);
			}
			if(a[0][2]=='y')
			{
				printf("(R U Rp U) R U U Rp\n");
				doMoves("RU0URUU0",1);
			}
			break;
	}
}
void detectPattern()
{
	if(f[0][1]!='y' && f[1][2]!='y' && f[2][1]!='y' && f[1][0]!='y')
	{
		printf("F R U Rp Up Fp");
		doMoves("FRU024",1);
	}
	else if((f[1][0]=='y' && f[0][1]=='y' && f[2][1]!='y' && f[1][2]!='y')||
		(f[1][0]!='y' && f[0][1]!='y' && f[2][1]=='y' && f[1][2]=='y')||
		(f[0][1]=='y' && f[1][2]=='y' && f[1][0]!='y' && f[2][1]!='y')||
		(f[0][1]!='y' && f[1][2]!='y' && f[1][0]=='y' && f[2][1]=='y'))
	{
		//printf("yay");
		orientPattern('l');
	}
	else if((f[1][0]=='y' && f[1][2]=='y' && f[0][1]!='y' && f[2][1]!='y')||
		    (f[1][0]!='y' && f[1][2]!='y' && f[0][1]=='y' && f[2][1]=='y'))
	{
		orientPattern('b');
	}
	else if(f[0][0]!='y' && f[0][2]!='y' && f[2][0]!='y' && f[2][2]!='y')
	{
		orientPattern('c');
	}
	else if((f[0][2]=='y' && f[2][2]=='y' && f[0][0]!='y' && f[2][0]!='y')||
			(f[0][2]!='y' && f[2][2]!='y' && f[0][0]=='y' && f[2][0]=='y')||
			(f[2][0]=='y' && f[2][2]=='y' && f[0][0]!='y' && f[0][2]!='y')||
			(f[2][0]!='y' && f[2][2]!='y' && f[0][0]=='y' && f[0][2]=='y'))
	{
		orientPattern('f');
	}
	else if((f[0][2]=='y' && f[2][0]=='y' && f[0][0]!='y' && f[2][2]!='y')||
			(f[0][2]!='y' && f[2][0]!='y' && f[0][0]=='y' && f[2][2]=='y'))
	{
	
		orientPattern('d');
	}
	else
		orientPattern('s');
}
int check_oll()
{
	int i=0,j=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			if(f[i][j]!='y')
				return 0;
	}
	return 1;
}
void oll()
{
	while(check_oll()!=1)
	{
		detectPattern();
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
	oll();
	printf("--------orientation complete-----------\n");
	getch();
	return 0;
}*/
