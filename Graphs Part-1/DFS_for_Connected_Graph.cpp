#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void print(int** edges,int n,int current,bool* visited)
{
	cout<<current<<endl;
	visited[current] = true;
	
	for(int i=0;i<n;i++)
	{
		if(i==current)
		{
			continue;
		}
		else if(visited[i])
		{
			continue;
		}
		else if(edges[i][current]==1)
		{
			print(edges,n,i,visited);
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
	
	print(edges,n,0,visited);
	
	return 0;
}

