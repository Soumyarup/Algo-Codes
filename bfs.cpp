#include<stdio.h>
int q[6];
int front=-1,rear=-1;
int graph[6][6],ver[]={0,1,2,3,4,5};
int vis[6];
int enq(int item)
{
	if(front==rear==-1)
	 front=rear=0;
	else
	 q[++rear]=item;
  return 0;
}
int deq()
{
	int n;
	n=q[front];
	if(front==rear-1)
	 front=rear-1;
	else
	++front;
	return n;
}
int bfs(int s)
{
	int v,n,j;
	enq(s);
	vis[s]=1;
	while(front!=-1)
	{
	  v=deq();
	  vis[v]=1;
	  for(j=0;j<6;j++)
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
   for(i=0;i<6;i++)
    {
     for(j=0;j<6;j++)
     scanf("%d",&graph[i][j]);
     vis[i]=0;
	}
   puts("Enter the source vertex:");
    scanf("%d",&n);
   bfs(n);
  return 0;	
}
