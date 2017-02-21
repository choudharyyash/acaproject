#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int check(int a[6][7])
{
	for(int i=0;i<6;i++)
	 for(int j=0;j<4;j++)
	 {
		if(a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1)
		    return 10;
		else if(a[i][j]==-1&&a[i][j+1]==-1&&a[i][j+2]==-1&&a[i][j+3]==-1)
		    return -10;
	 }
	
	for(int j=0;j<7;i++)
	{for(int i=0;i<3;j++)
	 {
		if(a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1)
		    return 10;
		else if(a[i][j]==-1&&a[i+1][j]==-1&&a[i+2][j]==-1&&a[i+3][j]==-1)
		    return -10;
	 }
	}
	for(int i=3;i<6;i++)
	  for(int k=i,j=0;k>2;k--,j++)
		{
		 if(a[k][j]==1&&a[k-1][j+1]==1&&a[k-2][j+2]==1&&a[k-3][j+3]==1)
		    return 10;
		 else if(a[k][j]==-1&&a[k-1][j+1]==-1&&a[k-2][j+2]==-1&&a[k-3][j+3]==-1)
		    return -10; 
		 if(a[5-k][6-j]==1&&a[6-k][5-j]==1&&a[7-k][4-j]==1&&a[8-k][3-j]==1)
		    return 10;
		 else if(a[5-k][6-j]==-1&&a[6-k][5-j]==-1&&a[7-k][4-j]==-1&&a[8-k][3-j]==-1)
		    return -10;
		}
	for(int i=0;i<3;i++)
	  for(int k=i,j=0;k<3;k++,j++)
		{
		 if(a[k][j]==1&&a[k+1][j+1]==1&&a[k+2][j+2]==1&&a[k+3][j+3]==1)
		    return 10;
		 else if(a[k][j]==-1&&a[k+1][j+1]==-1&&a[k+2][j+2]==-1&&a[k+3][j+3]==-1)
		    return -10; 
		 if(a[5-k][6-j]==1&&a[4-k][5-j]==1&&a[3-k][4-j]==1&&a[2-k][3-j]==1)
		    return 10;
		 else if(a[5-k][6-j]==-1&&a[4-k][5-j]==-1&&a[3-k][4-j]==-1&&a[2-k][3-j]==-1)
		    return -10;
		}
	for(int i=0;i<6;i++)
	  for(int j=0;j<7;j++)
	  {
		if(a[i][j]==0)
		  return 2;
	  }
	return 0;
	
}

int put(int a[6][7],int k,int p)
{
	for(int i=0;i<6;i++)
	{
		if(a[i][p]!=0&&k!=0&&i==0)
		   return 0;
		else if(a[i][p]!=0&&k!=0)
		    a[i-1][p]=k;
		else if(a[i][p]!=0&&k==0)
		    a[i][p]==k;
		   
	}
	return 1;
}

int heur(int a[6][7])
{
	for(int i=0;i<6;i++)
	 for(int j=0;j<4;j++)
	 {
		if(a[i][j]==0&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1&&j+4<7&&a[i][j+4]==0)
		    return 9;	
		else if(a[i][j]==0&&a[i][j+1]==-1&&a[i][j+2]==-1&&a[i][j+3]==-1&&j+4<7&&a[i][j+4]==0)
		    return -9;
	 }
	for(int j=0;j<7;i++)
	{for(int i=0;i<3;j++)
	 {
		if(a[i][j]==0&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1&&i<2&&a[i+4][j]==0)
		    return 9;
		else if(a[i][j]==0&&a[i+1][j]==-1&&a[i+2][j]==-1&&a[i+3][j]==-1&&i<2&&a[i+4][j]==0)
		    return -9;
	 }
	}
	for(int i=3;i<6;i++)
	  for(int k=i,j=0;k>2;k--,j++)
		{
		 if(a[k][j]==0&&a[k-1][j+1]==1&&a[k-2][j+2]==1&&a[k-3][j+3]==1&&k>3&&j<3&&a[k-4][j+4]==0)
		    return 9;
		 else if(a[k][j]==0&&a[k-1][j+1]==-1&&a[k-2][j+2]==-1&&a[k-3][j+3]==-1&&k>3&&j<3&&a[k-4][j+4]==0)
		    return -9; 
		 if(a[5-k][6-j]==0&&a[6-k][5-j]==1&&a[7-k][4-j]==1&&a[8-k][3-j]==1&&k>3&&j<3&&a[9-k][2-j]==0)
		    return 9;
		 else if(a[5-k][6-j]==0&&a[6-k][5-j]==-1&&a[7-k][4-j]==-1&&a[8-k][3-j]==-1&&k>3&&j<3&&a[9-k][2-j]==0)
		    return -9;
		}
	for(int i=0;i<3;i++)
	  for(int k=i,j=0;k<3;k++,j++)
		{
		 if(a[k][j]==0&&a[k+1][j+1]==1&&a[k+2][j+2]==1&&a[k+3][j+3]==1&&k<2&&j<3&&a[k+4][j+4]==0)
		    return 9;
		 else if(a[k][j]==0&&a[k+1][j+1]==-1&&a[k+2][j+2]==-1&&a[k+3][j+3]==-1&&k<2&&j<3&&a[k+4][j+4]==0)
		    return -9; 
		 if(a[5-k][6-j]==0&&a[4-k][5-j]==1&&a[3-k][4-j]==1&&a[2-k][3-j]==1&&k<2&&j<3&&a[1-k][2-j]==0)
		    return 9;
		 else if(a[5-k][6-j]==0&&a[4-k][5-j]==-1&&a[3-k][4-j]==-1&&a[2-k][3-j]==-1&&k<2&&j<3&&a[1-k][2-j]==0)
		    return -9;
		}
	
	for(int i=0;i<6;i++)
	 for(int j=0;j<4;j++)
	 {
		if(a[i][j]==0&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1)
		    return 8;
		else if(a[i][j]==0&&a[i][j+1]==-1&&a[i][j+2]==-1&&a[i][j+3]==-1)
		    return -8;
		if(a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==0)
		    return 8;
		else if(a[i][j]==-1&&a[i][j+1]==-1&&a[i][j+2]==-1&&a[i][j+3]==0)
		    return -8;
	 }
	for(int j=0;j<7;i++)
	{for(int i=0;i<3;j++)
	 {
		if(a[i][j]==0&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1)
		    return 8;
		else if(a[i][j]==0&&a[i+1][j]==-1&&a[i+2][j]==-1&&a[i+3][j]==-1)
		    return -8;
		if(a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==0)
		    return 8;
		else if(a[i][j]==-1&&a[i+1][j]==-1&&a[i+2][j]==-1&&a[i+3][j]==0)
		    return -8;
	 }
	}
	for(int i=3;i<6;i++)
	  for(int k=i,j=0;k>2;k--,j++)
		{
		 if(a[k][j]==0&&a[k-1][j+1]==1&&a[k-2][j+2]==1&&a[k-3][j+3]==1)
		    return 8;
		 else if(a[k][j]==0&&a[k-1][j+1]==-1&&a[k-2][j+2]==-1&&a[k-3][j+3]==-1)
		    return -8; 
		 if(a[5-k][6-j]==1&&a[6-k][5-j]==1&&a[7-k][4-j]==1&&a[8-k][3-j]==1) //resume from here
		    return 10;
		 else if(a[5-k][6-j]==-1&&a[6-k][5-j]==-1&&a[7-k][4-j]==-1&&a[8-k][3-j]==-1)
		    return -10;
		}
	for(int i=0;i<3;i++)
	  for(int k=i,j=0;k<3;k++,j++)
		{
		 if(a[k][j]==1&&a[k+1][j+1]==1&&a[k+2][j+2]==1&&a[k+3][j+3]==1)
		    return 10;
		 else if(a[k][j]==-1&&a[k+1][j+1]==-1&&a[k+2][j+2]==-1&&a[k+3][j+3]==-1)
		    return -10; 
		 if(a[5-k][6-j]==1&&a[4-k][5-j]==1&&a[3-k][4-j]==1&&a[2-k][3-j]==1)
		    return 10;
		 else if(a[5-k][6-j]==-1&&a[4-k][5-j]==-1&&a[3-k][4-j]==-1&&a[2-k][3-j]==-1)
		    return -10;
		}
	
	
}

int choose(int a[6][7],int k)
{
	
}

int main(){
	int a[6][7]={0};
	int k,si;
	printf("choose your side 1 or -1");
	scanf("%d",&k);
	if(k==-1)
	{
	 a[5][3]=1;
	 for(int j=0;j<6;j++)
	 {  for(int i=0;i<7;i++)
		printf("%d ",a[j][i]);
	    printf("\n");
	 }
	}
	while(check(a)==2)
	{
		scanf("%d",&si);
		int blah=put(a,k,si);
		int blah=put(a,-k,choose(a,-k));
		for(int j=0;j<6;j++)
	 	{  for(int i=0;i<7;i++)
			printf("%d ",a[j][i]);
	    	   printf("\n");
	 	}
	}
	if(check(a)==0)
		printf("draw");
	else if(check(a)==10&&k<0)
		printf("you lose");
	else if(check(a)==-10&&k>0)
		printf("you lose");
	else
		printf("you win");
	return 0;
}
