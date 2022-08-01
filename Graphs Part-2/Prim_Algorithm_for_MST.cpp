#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool visited[100001];
int parent[100001];
int weight[100001];

int Get_Min_Vertex(int** arr,int n)
{
	int minIndex = -1;
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && (minIndex==-1 || weight[i]<weight[minIndex]))
		{
			minIndex = i;
		}
	}
	
	return minIndex;
}

void Prim_Algorithms_for_MST(int** arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minVertex = Get_Min_Vertex(arr,n);
		visited[minVertex] = true;
		for(int j=0;j<n;j++)
		{
			if(!visited[j] && arr[minVertex][j]>0)
			{
				if(arr[minVertex][j]<weight[j])
				{
					weight[j] = arr[minVertex][j];
					parent[j] = minVertex;
				}
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
	}
	parent[0] = -1;
	weight[0] = 0;
	for(int i=1;i<n;i++)
	{
		weight[i] = INT_MAX;
	}

	Prim_Algorithms_for_MST(arr,n);
	
	for(int i=1;i<n;i++)
	{
		cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
	}
	
	return 0;
}

