#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Get_Path_DFS(int**edges,int n,int start,int end,bool* visited)
{
	if(start==end)
	{
		vector<int>v;
		v.push_back(start);
		return v;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && edges[start][i]==1 && i!=start)
		{
			visited[i] = true;
			vector<int>v = Get_Path_DFS(edges,n,i,end,visited);
			if(v.size()>0)
			{
				v.push_back(start);
				return v;
			}
		}
	}
	
	vector<int>v;
	return v;
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
		visited[i] = false;
	}
	visited[start] = true;
	vector<int>ans = Get_Path_DFS(edges,n,start,end,visited);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

