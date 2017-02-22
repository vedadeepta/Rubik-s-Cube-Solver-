#include <stdio.h>
char a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],f[3][3];
void rotate90(char k[3][3])
{
	int temp=0;
	temp=k[0][0];
	k[0][0]=k[2][0];
	k[2][0]=k[2][2];
	k[2][2]=k[0][2];
	k[0][2]=temp;
	temp=k[0][1];
	k[0][1]=k[1][0];
	k[1][0]=k[2][1];
	k[2][1]=k[1][2];
	k[1][2]=temp;
}
void rotate90_anti(char k[3][3])
{
	int temp=0;
	temp=k[0][0];
	k[0][0]=k[0][2];
	k[0][2]=k[2][2];
	k[2][2]=k[2][0];
	k[2][0]=temp;
	temp=k[0][1];
	k[0][1]=k[1][2];
	k[1][2]=k[2][1];
	k[2][1]=k[1][0];
	k[1][0]=temp;
}
void front_a()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=b[i][0];
		b[i][0]=f[2][i];
		f[2][i]=d[2-i][0];
		d[2-i][0]=e[2][2-i];
		e[2][2-i]=temp;
	}
	rotate90(a);
}
void frontp_a()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=f[2][i];
		f[2][i]=b[i][0];
		b[i][0]=e[2][2-i];
		e[2][2-i]=d[2-i][0];
		d[2-i][0]=temp;
	}
	rotate90_anti(a);
}
void front_b()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=c[i][2];
		c[i][2]=f[2-i][2];
		f[2-i][2]=a[2-i][2];
		a[2-i][2]=e[i][2];
		e[i][2]=temp;
	}
	rotate90(b);
}
void frontp_b()
{
	int i=0;
	char temp;
	for (i = 0; i < 3; i++)
	{
		temp=f[2-i][2];
		f[2-i][2]=c[i][2];
		c[i][2]=e[i][2];
		e[i][2]=a[2-i][2];
		a[2-i][2]=temp;
	}
	rotate90_anti(b);
}
void front_c()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=d[i][2];
		d[i][2]=f[0][2-i];
		f[0][2-i]=b[2-i][2];
		b[2-i][2]=e[0][i];
		e[0][i]=temp;
	}
	rotate90_anti(c);
}
void frontp_c()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=f[0][2-i];
		f[0][2-i]=d[i][2];
		d[i][2]=e[0][i];
		e[0][i]=b[2-i][2];
		b[2-i][2]=temp;
	}
	rotate90(c);
}
void front_d()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=a[i][0];
		a[i][0]=f[i][0];
		f[i][0]=c[2-i][0];
		c[2-i][0]=e[2-i][0];
		e[2-i][0]=temp;
	}
	rotate90_anti(d);
}
void frontp_d()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=a[i][0];
		a[i][0]=e[2-i][0];
		e[2-i][0]=c[2-i][0];
		c[2-i][0]=f[i][0];
		f[i][0]=temp;
	}
	rotate90(d);	
}
void up()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=a[0][i];
		a[0][i]=b[0][i];
		b[0][i]=c[0][2-i];
		c[0][2-i]=d[0][2-i];
		d[0][2-i]=temp;
	}
	rotate90(f);
}
void upp()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=a[0][i];
		a[0][i]=d[0][2-i];
		d[0][2-i]=c[0][2-i];
		c[0][2-i]=b[0][i];
		b[0][i]=temp;
	}
	rotate90_anti(f);
}
void down()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=a[2][i];
		a[2][i]=d[2][2-i];
		d[2][2-i]=c[2][2-i];
		c[2][2-i]=b[2][i];
		b[2][i]=temp;
	}
	rotate90_anti(e);
}
void downp()
{
	int i=0;
	char temp;
	for(i=0;i<3;i++)
	{
		temp=a[2][i];
		a[2][i]=b[2][i];
		b[2][i]=c[2][2-i];
		c[2][2-i]=d[2][2-i];
		d[2][2-i]=temp;
	}
	rotate90(e);
}
void scanCube()
{
	int i=0,j=0;
	printf("------orange-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("pos (%d,%d)",i,j);
			scanf(" %c",&a[i][j]);
		}
	}
	printf("------blue-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("pos (%d,%d)",i,j);
			scanf(" %c",&b[i][j]);
		}
	}
	printf("------red-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("pos (%d,%d)",i,j);
			scanf(" %c",&c[i][j]);
		}
	}
	printf("------green-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("pos (%d,%d)",i,j);
			scanf(" %c",&d[i][j]);
		}
	}
	printf("------yellow-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("pos (%d,%d)",i,j);
			scanf(" %c",&f[i][j]);
		}
	}
	printf("------white-----\n");	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("pos (%d,%d)",i,j);
			scanf(" %c",&e[i][j]);
		}
	}

}
void printCube()
{
	int i=0,j=0;
	printf("------orange-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c",a[i][j]);
		}
		printf("\n");
	}
	printf("------blue-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c",b[i][j]);
		}
		printf("\n");
	}
	printf("------red-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c",c[i][j]);
		}
		printf("\n");
	}
	printf("------green-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c",d[i][j]);
		}
		printf("\n");
	}
	printf("------yellow-----\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c",f[i][j]);
		}
		printf("\n");
	}
	printf("------white-----\n");	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c",e[i][j]);
		}
		printf("\n");
	}
}
/*int main()
{
	return 0;
	scanCube();
	front_a();
	frontp_a();
	front_b();frontp_b();
	front_c();frontp_c();
	front_d();frontp_d();
	up();upp();
	down();downp();
	printCube();
}*/
