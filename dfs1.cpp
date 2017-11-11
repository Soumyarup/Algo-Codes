#include<stdio.h>
int s[100];
int top=-1;
int graph[10][10],ver[]={0,1,2,3,4,5,6};
int vis[10];
int enq(int item)
{
	if(top==-1)
	 {
	  s[++top]=item;
     }
	else
	 s[++top]=item;
  return 0;
}
int deq()
{
	int n;
	n=s[top--];
	return n;
}
int dfs(int s)
{
	int v,n,j;
	enq(s);
	printf("%d",ver[s]);
	while(top!=-1)
	{
	  v=deq();
	  vis[v]=1;
	  for(j=0;j<7;j++)
	  {
	  	if(vis[j]==0&&graph[v][j]==1)
	  	{
	  		enq(j);
	  		printf("%d",ver[j]);
	  		vis[j]=1;
		}
	  }
	  
	}
	
}
int main()
{
 int i,j,n;
  puts("Enter the matrix");
   for(i=0;i<7;i++)
    {
     for(j=0;j<7;j++)
     scanf("%d",&graph[i][j]);
     vis[i]=0;
	}
   puts("Enter the source vertex:");
    scanf("%d",&n);
    puts("Path----->>>");
   dfs(n);
  return 0;	
}
