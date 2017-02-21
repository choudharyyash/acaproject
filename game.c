#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void copy(int a[],int b[])
{
  for(int i=0;i<9;i++)
	b[i]=a[i];
}
int check(int a[])
{
	
	for(int i=0;i<3;i++)
	{  
	  if(a[i*3]==1&&a[i*3+1]==1&&a[i*3+2]==1)
	      return 10; 
	  else if(a[i]==1&&a[i+3]==1&&a[i+6]==1)
	      return 10;
	  else if(a[i*3]==-1&&a[i*3+1]==-1&&a[i*3+2]==-1)
	      return -10;
	  else if(a[i]==-1&&a[i+3]==-1&&a[i+6]==-1)
	      return -10;
	}

	if(a[0]==1&&a[4]==1&&a[8]==1)
	      return 10; 
	else if(a[0]==-1&&a[4]==-1&&a[8]==-1)
	      return -10;
	else if(a[2]==1&&a[4]==1&&a[6]==1)
	      return 10; 
	else if(a[2]==-1&&a[4]==-1&&a[6]==-1)
	      return -10;

	for(int i=0;i<9;i++)
	{
	  if(a[i]==0)
	  {  return 2;
	  }                              //2 is for game not completed
	}
	return 0;                  //0 is for draw
}
int fun(int a[],int k)         //k is either zero or 1
{
		
	int max=-999,min=999;
	int d;
	for(int i=0;i<9;i++)
	  {	
		if(a[i]==0)		
		{
		 a[i]=k;
		 if(check(a)==2)	
			{
			  d=fun(a,-k);
			}
		 else
			d=check(a);
		 if(d>max&&k>0)
			max=d;
		 if(d<min&&k<0)
			min=d;
		 a[i]=0;
		}
	  }
	return (k>0)?max:min;
}

int choose(int a[],int k)
{
	int max=-999,min=999;
	int d,c;	
	for(int i=0;i<9;i++)
	  {	
		if(a[i]==0)		
		{
		 a[i]=k;
		 if(check(a)==2)	
			{
			  d=fun(a,-k);
			}
		 else
			d=check(a);
		 if(d>max&&k>0)
		 {
			max=d;
			c=i;
		 }
		 if(d<min&&k<0)
		 {	
			min=d;
			c=i;
		 }
		 a[i]=0;
		}
	  }
	//printf("%d",c);
	return c;
}

int main(){
	int p[9]={0};
	int a[9];
	int k,si;
	/*copy(p,a);
	for(int j=0;j<9;j++)
	 {  
		scanf("%d",&p[j]);
	    
	 }
	printf("%d",check(p));*/
	printf("choose your side 1 or -1");
	
	scanf("%d",&k);
	if(k==-1)
	{
	 p[4]=1;
	 for(int j=0;j<3;j++)
	 {  for(int i=0;i<3;i++)
		printf("%d ",p[j*3+i]);
	    printf("\n");
	 }
	}		
	while(check(p)==2)
	{
		scanf("%d",&si);
		p[si]=k;
		copy(p,a);
		p[choose(a,-k)]=-k;
		for(int j=0;j<3;j++)
	 	{  for(int i=0;i<3;i++)
			printf("%d ",p[j*3+i]);
	    	   printf("\n");
	 	}
	}
	if(check(p)==0)
		printf("draw");
	else if(check(p)==10&&k<0)
		printf("you lose");
	else if(check(p)==-10&&k>0)
		printf("you lose");
	else
		printf("you win");	
	
	

	return 0;
}
