#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

/*

void dfs(int** edges,int n,int current,bool* visited)
{
	visited[current] = true;
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && edges[i][current]==1)
		{
			dfs(edges,n,i,visited);
		}
	}
}

*/

void bfs(int** edges,int n,int start,bool* visited)
{
	queue<int>q;
	q.push(start);
	visited[start] = true;
	
	while(!q.empty())
	{
		int element = q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(!visited[i] && edges[i][element]==1)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	
}

int main()
{
	int n,e;
	cin>>n>>e;
	
	int** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j] = 0;
		}
		
	}
	
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		
		edges[f][s] = 1;
		edges[s][f] = 1;	
	}
	
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	/*
	
	dfs(edges,n,0,visited);
	
	*/
	
	bfs(edges,n,0,visited);
	
	int ans = true;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			ans = false;
			break;
		}
	}
	
	cout<<(ans==true?"true":"false")<<endl;
	
	return 0;
}

