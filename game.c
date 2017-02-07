#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int max()
int check(int a[])
{
	
	for(int i=0;i<3;i++)
	{  
	  if(a[i*3]==1&&a[i][1]==1&&a[i][2]==1)
	      return 10; 
	  else if(a[0][i]==1&&a[1][i]==1&&a[2][i]==1)
	      return 10;
	  else if(a[i][0]==0&&a[i][1]==0&&a[i][2]==0)
	      return -1;
	  else if(a[0][i]==0&&a[1][i]==0&&a[2][i]==0)
	      return -1;
	}

	if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1)
	      return 10; 
	else if(a[0][0]==0&&a[1][1]==0&&a[2][2]==0)
	      return -1;
	else if(a[2][0]==1&&a[1][1]==1&&a[0][2]==1)
	      return 10; 
	else if(a[0][2]==0&&a[1][1]==0&&a[2][0]==0)
	      return -1;

	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	  {
		if(a[i][j]!=0&&a[i][j]!=1)
			return 2;               //2 is for tie
	  }
	return 0;
}
int fun(int a[],int k)         //k is either zero or 1
{
	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	  {	
		if(a[i][j]!=0&&a[i][j]!=1)		
		{
		 a[i][j]=k;
		 return fun(a,k);
		}
	  }
}
int main(){
	int a[9];
	
	return 0;
}
