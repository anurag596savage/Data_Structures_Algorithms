#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void print(int** edges,int n,int current,bool* visited)
{
	queue<int>q;
	q.push(current);
	visited[current] = true;
	while(!q.empty())
	{
		int ele = q.front();
		q.pop();
		cout<<ele<<" ";
		for(int i=0;i<n;i++)
		{
			if(i==ele || visited[i])
			{
				continue;
			}
			else if(edges[ele][i]==1)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout<<endl;
}

void print(int** edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
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
	
	print(edges,n);
	
	return 0;
}

