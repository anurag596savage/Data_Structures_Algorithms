#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007


bool Has_Path(int** edges,int n,int start,int end,bool* visited)
{
	if(edges[start][end])
	{
		return true;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && edges[start][i] && i!=start)
		{
			visited[i] = true;
			if(Has_Path(edges,n,i,end,visited))
			{
				return true;
			}
		}
	}
	
	return false;	
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
	
	int start,end;
	cin>>start>>end;
	
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	bool ans = Has_Path(edges,n,start,end,visited);
	
	if(ans)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	
	return 0;
}

