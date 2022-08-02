#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool visited[100001];
int cost[100001];

int Find_Minimum_Vertex(int** arr,int n)
{
	int minIndex = -1;
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && (minIndex==-1 || cost[i]<cost[minIndex]))
		{
			minIndex = i;
		}
	}
	
	return minIndex;
}

void Find_Shortest_Path(int** arr,int n)
{
	cost[0] = 0;
	for(int i=0;i<n-1;i++)
	{
		int minVertex = Find_Minimum_Vertex(arr,n);
		visited[minVertex] = true;
		for(int j=0;j<n;j++)
		{
			if(!visited[j] && arr[minVertex][j])
			{
				cost[j] = min(cost[j],cost[minVertex]+arr[minVertex][j]);
			}
		}	
	}
	
}

int main()
{
	int n,e;
	cin>>n>>e;
	
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			arr[i][j] = 0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		arr[x][y] = z;
		arr[y][x] = z;
	}
	
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
		cost[i] = INT_MAX;
	}
	
	Find_Shortest_Path(arr,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<cost[i]<<endl;
	}
	
	return 0;
}

